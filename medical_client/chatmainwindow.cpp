#include "chatmainwindow.h"
#include "ui_chatmainwindow.h"
#include <QMessageBox>
#include <QUrlQuery>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QCryptographicHash>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QCryptographicHash>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

ChatMainWindow::ChatMainWindow(QTcpSocket *socket, User *user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatMainWindow),
    socket(socket),
    user(user),
    m_videoCallWindow(nullptr)
{
    qDebug() << "ChatMainWindow 构造函数开始";

    try {
        ui->setupUi(this);
        qDebug() << "UI setup 完成";

        // 检查UI元素
        if (!ui->contactListWidget) qCritical() << "contactListWidget 不存在!";
        if (!ui->chatTextEdit) qCritical() << "chatTextEdit 不存在!";
        if (!ui->msgLineEdit) qCritical() << "msgLineEdit 不存在!";
        if (!ui->currentChatLabel) qCritical() << "currentChatLabel 不存在!";
        if (!ui->sendButton) qCritical() << "sendButton 不存在!";
        if (!ui->videoCallButton) qCritical() << "videoCallButton 不存在!";

        this->setWindowTitle("即时聊天平台");
        // 移除这行：this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);

        // 连接信号槽
        connect(socket, &QTcpSocket::readyRead, this, &ChatMainWindow::handleSocketReadyRead);
        connect(ui->msgLineEdit, &QLineEdit::returnPressed, this, &ChatMainWindow::on_sendButton_clicked);
        connect(ui->contactListWidget, &QListWidget::itemClicked, this, &ChatMainWindow::on_contactListWidget_itemClicked);

        // 初始化界面状态
        ui->currentChatLabel->setText("请选择联系人开始聊天");
        ui->chatTextEdit->setEnabled(false);
        ui->msgLineEdit->setEnabled(false);
        ui->sendButton->setEnabled(false);
        ui->videoCallButton->setEnabled(false);

        // 设置固定大小
        this->resize(1200, 800);
        this->setMinimumSize(1000, 600);

        // 加载联系人列表
        loadContactList();

        qDebug() << "ChatMainWindow 构造函数完成";

    } catch (const std::exception &e) {
        qCritical() << "构造函数异常:" << e.what();
    } catch (...) {
        qCritical() << "未知异常在构造函数";
    }
}

ChatMainWindow::~ChatMainWindow()
{
    // 清理资源
    if (m_videoCallWindow) {
        m_videoCallWindow->close();
        delete m_videoCallWindow;
    }
    delete ui;
}

void ChatMainWindow::loadContactList()
{
    // 请求服务器获取联系人列表
    // 使用 GET_RECEIVER 消息类型（与SelectReceiver相同）
    Message msg(user, new User("", "", -1), "", MessageType::GET_RECEIVER);
    socket->write(Message::messageToByteArray(msg));

    qDebug() << "正在请求联系人列表...";
}

void ChatMainWindow::on_contactListWidget_itemClicked(QListWidgetItem *item)
{
    // 获取联系人的用户名（存储在UserRole中）
    QString receiver = item->data(Qt::UserRole).toString();

    // 检查是否是有效的联系人（不是"没有联系人"这样的提示）
    if (receiver != "没有联系人") {
        switchChat(receiver);
    }
}

void ChatMainWindow::switchChat(const QString &receiver)
{
    currentReceiver = receiver;

    // 更新界面状态 - 启用聊天功能
    ui->currentChatLabel->setText(QString("您正在和 ") + getFullname(receiver, user->role == 0 ? 1 : 0) + QString(" 沟通："));
    ui->chatTextEdit->setEnabled(true);
    ui->msgLineEdit->setEnabled(true);
    ui->sendButton->setEnabled(true);
    ui->videoCallButton->setEnabled(true);

    // 清空聊天记录，准备显示新对话
    ui->chatTextEdit->clear();

    // 请求与当前联系人的历史消息
    Message msg(user, new User(receiver, QString(), user->role == 0 ? 1 : 0), QString(), MessageType::GET_HISTORY);
    socket->write(Message::messageToByteArray(msg));

    qDebug() << "切换到与" << receiver << "的聊天";
}

void ChatMainWindow::on_sendButton_clicked()
{
    if (currentReceiver.isEmpty()) {
        QMessageBox::warning(this, "发送失败", "请先选择联系人");
        return;
    }

    QString content = ui->msgLineEdit->text();
    ui->msgLineEdit->clear();

    if (content.trimmed().isEmpty()) {
        QMessageBox::warning(this, "发送失败", "消息内容不能为空");
        return;
    }

    // 自动识别语言，翻译成中英文双语（保持原有逻辑）
    // 这里需要添加网络管理器，与原有Chat类相同
    static QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QString appid = "20250830002442722";
    QString key = "ZA4I8xw5tALk42QmiHEZ";
    QString salt = QString::number(qrand() % 100000);
    QString signSrc = appid + content + salt + key;
    QString sign = QCryptographicHash::hash(signSrc.toUtf8(), QCryptographicHash::Md5).toHex();

    QUrl url("https://api.fanyi.baidu.com/api/trans/vip/translate");
    QUrlQuery query;
    query.addQueryItem("q", content);
    query.addQueryItem("from", "auto");
    query.addQueryItem("to", "zh");
    query.addQueryItem("appid", appid);
    query.addQueryItem("salt", salt);
    query.addQueryItem("sign", sign);
    url.setQuery(query);

    QNetworkRequest request(url);
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, [this, content, reply]() {
        QByteArray response = reply->readAll();
        reply->deleteLater();

        QString zhTrans = "翻译失败";
        QJsonDocument json = QJsonDocument::fromJson(response);
        if (!json.isNull() && json.isObject()) {
            QJsonObject obj = json.object();
            if (obj.contains("trans_result")) {
                QJsonArray arr = obj["trans_result"].toArray();
                if (!arr.isEmpty()) {
                    zhTrans = arr[0].toObject()["dst"].toString();
                }
            }
        }

        // 发送翻译后的消息
        QString finalMsg = content + "\n中文: " + zhTrans;
        User *rcver = new User(currentReceiver, "", user->role == 0 ? 1 : 0);
        Message msg(user, rcver, finalMsg, MessageType::SEND_MESSAGE);
        socket->write(Message::messageToByteArray(msg));

        delete rcver;
    });
}

void ChatMainWindow::on_videoCallButton_clicked()
{
    if (currentReceiver.isEmpty()) {
        QMessageBox::warning(this, "视频通话", "请先选择联系人");
        return;
    }

    // 发送视频通话请求
    Message msg(user, new User(currentReceiver, QString(), user->role == 0 ? 1 : 0),
                QString(), VIDEO_CALL_REQUEST);
    socket->write(Message::messageToByteArray(msg));

    QMessageBox::information(this, "视频通话", "正在向对方发送通话邀请...");
}

void ChatMainWindow::on_returnButton_clicked()
{
    if (!currentReceiver.isEmpty()) {
        // 告诉服务器已读消息
        Message msg(user, new User(currentReceiver, QString(), user->role == 0 ? 1 : 0),
                    QString(), MessageType::UPDATE_ISREAD);
        socket->write(Message::messageToByteArray(msg));
    }

    emit returnToProfile();
    this->close();
}

void ChatMainWindow::handleSocketReadyRead()
{
    QByteArray ba = socket->readAll();
    Message msg = Message::byteArrayToMessage(ba);

    qDebug() << "收到消息类型:" << msg.messageType;

    // 根据消息类型分发处理
    switch (msg.messageType) {
    case MessageType::RET_RECEIVER:
        handleRetContacts(msg);
        break;
    case MessageType::RET_HISTORY:
        handleRetHistory(msg);
        break;
    case MessageType::RECEIVE_MESSAGE:
        handleReceiveMessage(msg);
        break;
    case MessageType::SEND_SUCCESS:
        handleSendSuccess(msg);
        break;
    case MessageType::RECEIVER_OFFLINE:
        handleReceiverOffline(msg);
        break;
    case MessageType::UPDATE_ISREAD_SUCCESS:
        handleUpdateIsReadSuccess(msg);
        break;
    case MessageType::VIDEO_CALL_REQUEST:
        handleVideoCallRequest(msg);
        break;
    case MessageType::VIDEO_CALL_ACCEPT:
        handleVideoCallAccept(msg);
        break;
    case MessageType::VIDEO_CALL_REJECT:
        handleVideoCallReject(msg);
        break;
    case MessageType::VIDEO_CALL_END:
        handleVideoCallEnd(msg);
        break;
    case MessageType::VIDEO_DATA:
        handleVideoData(msg);
        break;
    default:
        qDebug() << "未知消息类型:" << msg.messageType;
    }
}

void ChatMainWindow::handleRetContacts(const Message &msg)
{
    if (msg.messageType == MessageType::RET_RECEIVER) {
        ui->contactListWidget->clear();
        contactTable.clear();

        if (msg.content.trimmed().isEmpty()) {
            QListWidgetItem *item = new QListWidgetItem("没有联系人");
            item->setData(Qt::UserRole, "没有联系人");
            ui->contactListWidget->addItem(item);
            return;
        }

        QStringList contacts = msg.content.split("_");
        QString roleStr = (user->role == 0) ? "患者" : "医生";

        for (const QString &contact : contacts) {
            if (contact.trimmed().isEmpty()) continue;

            if (!contactTable.contains(contact)) {
                contactTable.insert(contact, 1);

                QString displayText = contact + "  (" + roleStr + ")";
                QListWidgetItem *item = new QListWidgetItem(displayText);
                item->setData(Qt::UserRole, contact);
                ui->contactListWidget->addItem(item);
            }
        }

        qDebug() << "加载了" << contactTable.size() << "个联系人";
    }
}

// 以下消息处理函数与原有Chat类基本相同，只需注意使用currentReceiver

void ChatMainWindow::handleReceiveMessage(const Message &msg)
{
    // 检查消息是否来自当前正在聊天的联系人
    QStringList parts = msg.content.split("_");
    if (parts.size() > 3 && parts[3] == currentReceiver) {
        QString text = ui->chatTextEdit->toPlainText();
        text.append(getTextLine(msg.content));
        ui->chatTextEdit->setText(text);
    }
}

void ChatMainWindow::handleSendSuccess(const Message &msg)
{
    QString text = ui->chatTextEdit->toPlainText();
    text.append(getTextLine(msg.content));
    ui->chatTextEdit->setText(text);
}

void ChatMainWindow::handleReceiverOffline(const Message &msg)
{
    QMessageBox::information(this, "对方不在线", "对方不在线，我们会在对方登录时转发您的消息");
    QString text = ui->chatTextEdit->toPlainText();
    text.append(getTextLine(msg.content));
    ui->chatTextEdit->setText(text);
}

void ChatMainWindow::handleRetHistory(const Message &msg)
{
    QStringList lines = msg.content.split("|");
    QString text = ui->chatTextEdit->toPlainText();
    for(const QString &line : lines) {
        text.append(getTextLine(line));
    }
    ui->chatTextEdit->setText(text);
}

void ChatMainWindow::handleUpdateIsReadSuccess(const Message &msg)
{
    // 可以在这里处理已读确认
    qDebug() << "消息已读状态更新成功";
}

// 视频通话相关处理函数 - 大窗口清晰版本
void ChatMainWindow::handleVideoCallRequest(const Message &msg)
{
    QMetaObject::invokeMethod(this, [this, msg]() {
        // 创建来电弹窗 - 更大更清晰的版本
        QDialog *callDialog = new QDialog(this);
        callDialog->setWindowTitle("寰宇医桥 - 视频通话邀请");
        callDialog->setFixedSize(500, 280); // 增大尺寸
        callDialog->setModal(true);
        callDialog->setAttribute(Qt::WA_DeleteOnClose);

        // 设置背景渐变
        callDialog->setStyleSheet(
            "QDialog {"
            "background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #e3f2fd, stop:1 #bbdefb);"
            "border-radius: 20px;"
            "border: 3px solid #90caf9;"
            "}"
        );

        QVBoxLayout *layout = new QVBoxLayout(callDialog);
        layout->setSpacing(20);
        layout->setContentsMargins(30, 30, 30, 30);

        // 图标和标题
        QLabel *iconLabel = new QLabel("📹");
        iconLabel->setAlignment(Qt::AlignCenter);
        iconLabel->setStyleSheet(
            "QLabel {"
            "font-size: 56px;"  // 增大图标
            "padding: 15px 10px 5px 10px;"  // 调整内边距：上右下左
            "}"
        );
        layout->addWidget(iconLabel);

        // 添加一些间距
        layout->addSpacing(10);

        // 来电提示
        QLabel *label = new QLabel(QString("视频通话邀请"));
        label->setAlignment(Qt::AlignCenter);
        label->setMinimumSize(350, 90);  // 进一步增大尺寸
        label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        label->setStyleSheet(
            "QLabel {"
            "color: #1565c0;"
            "font-size: 26px;"  // 再增大一点字体
            "font-weight: bold;"
            "padding: 25px 30px;"  // 增加更多内边距
            "background-color: rgba(255, 255, 255, 0.95);"
            "border-radius: 20px;"  // 更大的圆角
            "border: 3px solid #90caf9;"
            "margin: 10px 20px;"  // 增加外边距：上下10px，左右20px
            "}"
        );
        layout->addWidget(label);

        // 添加更多间距
        layout->addSpacing(15);

        QLabel *nameLabel = new QLabel(QString("来自: %1").arg(getFullname(msg.sender->username, msg.sender->role)));
        nameLabel->setAlignment(Qt::AlignCenter);
        nameLabel->setMinimumHeight(50);  // 设置最小高度
        nameLabel->setStyleSheet(
            "QLabel {"
            "color: #37474f;"  // 更深的颜色
            "font-size: 18px;"
            "font-weight: medium;"
            "padding: 15px 20px;"  // 增加内边距
            "background-color: rgba(255, 255, 255, 0.85);"
            "border-radius: 12px;"
            "border: 1.5px solid #b0bec5;"  // 稍微粗一点的边框
            "margin: 0px 30px;"  // 水平方向更多外边距
            "}"
        );
        layout->addWidget(nameLabel);

        // 添加更大的间距
        layout->addSpacing(25);

        // 按钮区域
        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(50);  // 增加按钮间距
        buttonLayout->setContentsMargins(40, 20, 40, 30);  // 增加边距：左、上、右、下

        QPushButton *acceptButton = new QPushButton("🎥 接听通话");
        acceptButton->setFixedSize(160, 60);  // 增大按钮尺寸
        acceptButton->setStyleSheet(
            "QPushButton {"
            "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #66bb6a, stop:1 #2e7d32);"
            "color: white;"
            "font-weight: bold;"
            "font-size: 18px;"
            "border-radius: 18px;"  // 更大的圆角
            "border: 2px solid #81c784;"
            "padding: 8px 12px;"  // 增加内边距
            "}"
            "QPushButton:hover {"
            "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #81c784, stop:1 #1b5e20);"
            "border: 2px solid #a5d6a7;"
            "}"
            "QPushButton:pressed {"
            "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #2e7d32, stop:1 #1b5e20);"
            "padding: 7px 11px;"  // 按下时稍微缩小
            "}"
        );

        QPushButton *rejectButton = new QPushButton("📵 拒绝通话");
        rejectButton->setFixedSize(160, 60);  // 增大按钮尺寸
        rejectButton->setStyleSheet(
            "QPushButton {"
            "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #ff6b6b, stop:1 #d32f2f);"
            "color: white;"
            "font-weight: bold;"
            "font-size: 18px;"
            "border-radius: 18px;"  // 更大的圆角
            "border: 2px solid #ff8a80;"
            "padding: 8px 12px;"  // 增加内边距
            "}"
            "QPushButton:hover {"
            "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #ff8a80, stop:1 #c62828);"
            "border: 2px solid #ffab91;"
            "}"
            "QPushButton:pressed {"
            "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #d32f2f, stop:1 #b71c1c);"
            "padding: 7px 11px;"  // 按下时稍微缩小
            "}"
        );

        buttonLayout->addWidget(acceptButton);
        buttonLayout->addWidget(rejectButton);
        layout->addLayout(buttonLayout);

        // 在底部添加一些额外间距
        layout->addSpacing(15);


        // 连接按钮事件
        connect(acceptButton, &QPushButton::clicked, [this, msg, callDialog]() {
            Message reply(this->user, msg.sender, "", VIDEO_CALL_ACCEPT);
            socket->write(Message::messageToByteArray(reply));

            // 打开更大的视频通话窗口
            m_videoCallWindow = new SimpleVideoCall(socket, this->user, msg.sender->username, this);
            m_videoCallWindow->resize(1000, 800); // 更大的窗口尺寸
            m_videoCallWindow->move(200, 100);   // 更好的位置
            m_videoCallWindow->show();

            callDialog->accept();
        });

        connect(rejectButton, &QPushButton::clicked, [this, msg, callDialog]() {
            Message reply(this->user, msg.sender, "", VIDEO_CALL_REJECT);
            socket->write(Message::messageToByteArray(reply));
            callDialog->reject();
        });

        // 显示弹窗
        callDialog->show();
        callDialog->raise();
        callDialog->activateWindow();
    });
}

void ChatMainWindow::handleVideoCallAccept(const Message &msg)
{
    QMetaObject::invokeMethod(this, [this, msg]() {
        // 创建自定义消息对话框
        QDialog *successDialog = new QDialog(this);
        successDialog->setWindowTitle("寰宇医桥 - 通话连接成功");
        successDialog->setFixedSize(450, 250);
        successDialog->setStyleSheet(
            "QDialog {"
            "background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #e8f5e8, stop:1 #c8e6c9);"
            "border-radius: 20px;"
            "border: 3px solid #81c784;"
            "}"
        );

        QVBoxLayout *layout = new QVBoxLayout(successDialog);

        QLabel *iconLabel = new QLabel("✅");
        iconLabel->setAlignment(Qt::AlignCenter);
        iconLabel->setStyleSheet("font-size: 48px;");
        layout->addWidget(iconLabel);

        QLabel *textLabel = new QLabel("对方已接受视频通话\n正在建立连接...");
        textLabel->setAlignment(Qt::AlignCenter);
        textLabel->setStyleSheet(
            "QLabel {"
            "color: #2e7d32;"
            "font-size: 18px;"
            "font-weight: bold;"
            "padding: 20px;"
            "}"
        );
        layout->addWidget(textLabel);

        QTimer::singleShot(1500, successDialog, [this, msg, successDialog]() {
            successDialog->accept();
            m_videoCallWindow = new SimpleVideoCall(socket, this->user, msg.sender->username, this);
            m_videoCallWindow->resize(900, 700); // 更大的视频窗口
            m_videoCallWindow->move(150, 50);    // 居中偏上的位置
            m_videoCallWindow->setWindowTitle(QString("寰宇医桥 - 与 %1 的视频通话").arg(getFullname(msg.sender->username, msg.sender->role)));
            m_videoCallWindow->show();
        });

        successDialog->exec();
    });
}

void ChatMainWindow::handleVideoCallReject(const Message &msg)
{
    QMetaObject::invokeMethod(this, [this, msg]() {
        QDialog *rejectDialog = new QDialog(this);
        rejectDialog->setWindowTitle("寰宇医桥 - 通话结束");
        rejectDialog->setFixedSize(400, 200);
        rejectDialog->setStyleSheet(
            "QDialog {"
            "background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #ffebee, stop:1 #ffcdd2);"
            "border-radius: 15px;"
            "border: 2px solid #ef9a9a;"
            "}"
        );

        QVBoxLayout *layout = new QVBoxLayout(rejectDialog);

        QLabel *iconLabel = new QLabel("❌");
        iconLabel->setAlignment(Qt::AlignCenter);
        iconLabel->setStyleSheet("font-size: 36px;");
        layout->addWidget(iconLabel);

        QLabel *textLabel = new QLabel(QString("对方拒绝了视频通话邀请"));
        textLabel->setAlignment(Qt::AlignCenter);
        textLabel->setStyleSheet(
            "QLabel {"
            "color: #c62828;"
            "font-size: 16px;"
            "font-weight: bold;"
            "padding: 15px;"
            "}"
        );
        layout->addWidget(textLabel);

        QTimer::singleShot(2000, rejectDialog, &QDialog::accept);
        rejectDialog->exec();
    });
}

void ChatMainWindow::handleVideoCallEnd(const Message &msg)
{
    QMetaObject::invokeMethod(this, [this]() {
        if (m_videoCallWindow) {
            m_videoCallWindow->close();
            m_videoCallWindow = nullptr;
        }

        QDialog *endDialog = new QDialog(this);
        endDialog->setWindowTitle("寰宇医桥 - 通话结束");
        endDialog->setFixedSize(400, 200);
        endDialog->setStyleSheet(
            "QDialog {"
            "background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #e3f2fd, stop:1 #bbdefb);"
            "border-radius: 15px;"
            "border: 2px solid #90caf9;"
            "}"
        );

        QVBoxLayout *layout = new QVBoxLayout(endDialog);

        QLabel *iconLabel = new QLabel("📞");
        iconLabel->setAlignment(Qt::AlignCenter);
        iconLabel->setStyleSheet("font-size: 36px;");
        layout->addWidget(iconLabel);

        QLabel *textLabel = new QLabel("视频通话已结束");
        textLabel->setAlignment(Qt::AlignCenter);
        textLabel->setStyleSheet(
            "QLabel {"
            "color: #1565c0;"
            "font-size: 18px;"
            "font-weight: bold;"
            "padding: 15px;"
            "}"
        );
        layout->addWidget(textLabel);

        QTimer::singleShot(1500, endDialog, &QDialog::accept);
        endDialog->exec();
    });
}

void ChatMainWindow::handleVideoData(const Message &msg)
{
    qDebug() << "=== 收到视频数据 ===";
    qDebug() << "视频数据大小:" << msg.content.size();
    qDebug() << "发送者:" << msg.sender->username;
    qDebug() << "接收者:" << msg.receiver->username;
    qDebug() << "视频窗口状态:" << (m_videoCallWindow != nullptr ? "已创建" : "未创建");

    // 确保消息是发给当前用户的
    if (msg.receiver->username != this->user->username) {
        qDebug() << "消息不是发给当前用户的，忽略";
        return;
    }

    if (m_videoCallWindow) {
        qDebug() << "转发视频数据到视频窗口";
        m_videoCallWindow->handleIncomingImage(msg.content.toUtf8());
    } else {
        qDebug() << "警告：收到视频数据但视频窗口未创建";
        qDebug() << "发送者:" << msg.sender->username;

        // 自动创建视频窗口（如果需要）
        if (QMessageBox::question(this, "视频通话",
            QString("收到来自 %1 的视频数据，是否打开视频窗口？").arg(getFullname(msg.sender->username, msg.sender->role)),
            QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {

            m_videoCallWindow = new SimpleVideoCall(socket, this->user, msg.sender->username, this);
            m_videoCallWindow->show();
            m_videoCallWindow->handleIncomingImage(msg.content.toUtf8());
        }
    }
}

// 工具函数（从原有Chat类复制）
QString ChatMainWindow::getFullname(const QString &username, int role)
{
    QString role_ = role == 0 ? QString("医生") : QString("患者");
    return username + " (" + role_ + ") ";
}

QString ChatMainWindow::getTextLine(const QString &line)
{
    if (line.isEmpty()) return line;

    QStringList parts = line.split("_");
    QString content = (parts.size() > 0) ? parts[0] : "";
    QString chatDate = (parts.size() > 1) ? parts[1] : "";
    int isRead = (parts.size() > 2) ? parts[2].toInt() : 0;
    QString sender = (parts.size() > 3) ? parts[3] : "";

    int role = (sender == user->username) ? user->role : (user->role == 0 ? 1 : 0);

    QString textLine = getFullname(sender, role) + "：" + content +
                     (isRead == 0 && user->username != sender ? "(未读)" : "") + "\n" +
                     "------------------------------------" + chatDate + "\n";

    return textLine;
}
