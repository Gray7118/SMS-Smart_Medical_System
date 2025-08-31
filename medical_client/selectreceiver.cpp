#include "selectreceiver.h"
#include "ui_selectreceiver.h"

SelectReceiver::SelectReceiver(QTcpSocket *socket, User *user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectReceiver)
{
    this->socket = socket;
    this->user = user;
    ui->setupUi(this);

    this->setWindowTitle(QString("选人页面"));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);

    // 构造请求查看可聊天的Message
    Message msg(user, new User, QString(), MessageType::GET_RECEIVER);
    socket->write(Message::messageToByteArray(msg));

    connect(socket, &QTcpSocket::readyRead, this, [this](){
        QByteArray ba = this->socket->readAll();
        Message msg = Message::byteArrayToMessage(ba);

        qDebug() << "服务器返回的可聊天的对象";
        msg.print();

        // 关闭connect，防止抢夺其它地方的消息
        disconnect(this->socket, &QTcpSocket::readyRead, this, nullptr);

        if (msg.messageType == MessageType::RET_RECEIVER) {
            // 服务器返回的聊天人选receivers username，以“_”分隔
            if (msg.content.trimmed() == QString()) {
                ui->receiverComboBox->addItem(QString("没有联系人"));
                ui->receiverTextEdit->setText(QString("没有联系人"));
                return;
            }

            QStringList receivers = msg.content.split("_");
            QString receiverRole = this->user->role == 0 ? QString("患者") : QString("医生");
            for (const QString &receiver : receivers) {
                if (!table.contains(receiver)) {
                    table.insert(receiver, 0);
                } else {
                    table[receiver]++;
                }
            }
            receivers = table.keys();
            QString text = ui->receiverTextEdit->toPlainText();
            for (const QString &receiver : receivers) {
                QString line;
                line.append(receiver);
                line.append(QString("  "));
                line.append(receiverRole);
                text.append(line).append(QChar('\n'));
                ui->receiverComboBox->addItem(line);
            }
            ui->receiverTextEdit->setText(text);
        }
    });

    // 回车直接发送
    connect(ui->msgLineEdit, &QLineEdit::returnPressed, this, &SelectReceiver::on_confirmButton_clicked);
}

SelectReceiver::~SelectReceiver()
{
    delete ui;
}

void SelectReceiver::on_quitButton_clicked()
{
    emit returnToProfile();
    this->close();
}

void SelectReceiver::on_confirmButton_clicked()
{
    QString receiver = ui->msgLineEdit->text();
    if (!table.contains(receiver)) {
        QMessageBox::critical(0, "选择失败", "您要联系的对象不存在");
        ui->msgLineEdit->setText(QString());
        return;
    } else {
        emit completeSelect(receiver);
        this->close();
    }
}

void SelectReceiver::on_receiverComboBox_activated(const QString &receiver)
{
    ui->msgLineEdit->setText(receiver.split("  ")[0]);
    ui->msgLineEdit->setFocus();
}


/*#include "selectreceiver.h"
#include "ui_selectreceiver.h"
#include <QTimer>
#include <QMessageBox>

SelectReceiver::SelectReceiver(QTcpSocket *socket, User *user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectReceiver),
    socket(socket),
    user(user)
{
    ui->setupUi(this);
    this->setWindowTitle("选人页面");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);

    // 检查是否是急诊病人
    if(user->username == "急诊病人") {
        setupEmergencyUI();
    } else {
        handleNormalUser();
    }

    connect(ui->msgLineEdit, &QLineEdit::returnPressed, this, &SelectReceiver::on_confirmButton_clicked);
}

SelectReceiver::~SelectReceiver()
{
    delete ui;
}

void SelectReceiver::setupEmergencyUI()
{
    // 硬编码的急诊医生信息（必须与数据库一致）
    const QString emergencyDoctorName = "急诊医生";

    // 设置急诊专用界面样式
    this->setStyleSheet("background-color: #fff8f8;");

    // 配置急诊按钮
    ui->confirmButton->setText("立即连接急诊医生");
    ui->confirmButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #ff5555;"
        "   color: white;"
        "   font-weight: bold;"
        "   font-size: 14px;"
        "   padding: 5px;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #ff3333;"
        "}"
    );

    // 显示急诊专用信息
    ui->receiverTextEdit->setText(
        "【急诊专用通道】\n"
        "您正在使用急诊服务\n\n"
        "已自动分配急诊医生:\n"
        + emergencyDoctorName + "  医生\n\n"
        "系统将在3秒后自动连接..."
    );

    // 填充联系人信息
    ui->receiverComboBox->addItem(emergencyDoctorName + "  医生");
    ui->msgLineEdit->setText(emergencyDoctorName);

    // 添加到合法联系人表
    table.insert(emergencyDoctorName, 1);

    // 3秒后自动连接急诊医生
    QTimer::singleShot(3000, this, [this, emergencyDoctorName](){
        if(this->isVisible()) { // 确保窗口仍然可见
            QMessageBox::information(this, "急诊连接",
                "正在为您连接急诊医生：" + emergencyDoctorName);
            emit completeSelect(emergencyDoctorName);
            this->close();
        }
    });
}

void SelectReceiver::handleNormalUser()
{
    // 原有普通用户逻辑保持不变
    Message msg(user, new User, QString(), MessageType::GET_RECEIVER);
    socket->write(Message::messageToByteArray(msg));

    connect(socket, &QTcpSocket::readyRead, this, [this](){
        QByteArray ba = this->socket->readAll();
        Message msg = Message::byteArrayToMessage(ba);
        disconnect(this->socket, &QTcpSocket::readyRead, this, nullptr);

        if (msg.messageType == MessageType::RET_RECEIVER) {
            if (msg.content.trimmed().isEmpty()) {
                ui->receiverComboBox->addItem("没有联系人");
                ui->receiverTextEdit->setText("没有可用联系人");
                return;
            }

            QStringList receivers = msg.content.split("_");
            QString roleStr = (user->role == 0) ? "医生" : "患者";

            ui->receiverTextEdit->clear();
            foreach (const QString &receiver, receivers) {
                QString line = receiver + "  " + roleStr + "\n";
                ui->receiverTextEdit->append(line);
                ui->receiverComboBox->addItem(line.trimmed());
                table.insert(receiver, 1);
            }
        }
    });
}

void SelectReceiver::on_quitButton_clicked()
{
    emit returnToProfile();
    this->close();
}

void SelectReceiver::on_confirmButton_clicked()
{
    QString receiver = ui->msgLineEdit->text().split("  ")[0].trimmed();

    // 急诊病人强制连接急诊医生
    if(user->username == "急诊病人") {
        receiver = "急诊医生"; // 确保连接正确的急诊医生
        QMessageBox::information(this, "急诊通道",
            "正在为您连接急诊医生，请稍候...");
    }

    if (!table.contains(receiver)) {
        QMessageBox::critical(this, "选择失败", "您要联系的对象不存在");
        ui->msgLineEdit->clear();
        return;
    }

    emit completeSelect(receiver);
    this->close();
}

void SelectReceiver::on_receiverComboBox_activated(const QString &text)
{
    ui->msgLineEdit->setText(text.split("  ")[0]);
    ui->msgLineEdit->setFocus();
}*/
