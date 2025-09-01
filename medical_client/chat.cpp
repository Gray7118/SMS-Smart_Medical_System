#include "chat.h"
#include "ui_chat.h"
#include <QCameraInfo>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>


Chat::Chat(QTcpSocket *socket, User *user, QString receiver, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    this->socket = socket;
    this->user = user;
    this->receiver = QString(receiver);
    ui->setupUi(this);

    this->setWindowTitle(QString("即时聊天平台"));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);

    // 显示聊天对象
    ui->recerverLabel->setText(QString("您正在和 ") + getFullname(receiver, user->role == 0 ? 1 : 0) + QString(" 沟通："));

    // 请求服务器，获取历史信息
    Message msg(user, new User(receiver, QString(), user->role == 0 ? 1 : 0), QString(), MessageType::GET_HISTORY);
    socket->write(Message::messageToByteArray(msg));

    // 修改信号连接方式 - 替换原来的lambda连接
    connect(socket, &QTcpSocket::readyRead, this, &Chat::handleSocketReadyRead);


    // 回车键直接发送
    connect(ui->msgLineEdit, &QLineEdit::returnPressed, this, &Chat::on_sendButton_clicked);
    // 在这里添加视频通话按钮
    QPushButton *videoCallButton = new QPushButton("视频通话", this);
    videoCallButton->setGeometry(160, 790, 100, 50);  // 调整位置，避免与现有按钮重叠
    videoCallButton->setStyleSheet("background-color: #2196F3; color: white; font-weight: bold;");
    connect(videoCallButton, &QPushButton::clicked, this, &Chat::startVideoCall);
    // 初始化视频通话窗口指针
    m_videoCallWindow = nullptr;
}

Chat::~Chat()
{
    // 发送退出的请求
    Message msg(user, new User, QString(), MessageType::QUIT);
    socket->write(Message::messageToByteArray(msg));
    delete ui;
}

void Chat::on_returnButton_clicked()
{
    emit returnToProfile();

    // 退出的时候，告诉服务器自己已读，即把自己历史记录里面的所有消息设置为已读
    Message msg(user, new User(receiver, QString(), user->role == 0 ? 1 : 0), QString(), MessageType::UPDATE_ISREAD);
    socket->write(Message::messageToByteArray(msg));

    // disconnect和close移到上面判断接收消息类型里面去了
}

void Chat::on_sendButton_clicked()
{
    QString content = ui->msgLineEdit->text();
    ui->msgLineEdit->setText(QString());
    if (content.trimmed() == QString("")) {
        QMessageBox::warning(0, QString("发送失败"), QString("至少写点什么再发吧"));
        return;
    }

    // 构造Message对象，只需发送就可以了，不需要在这里connect，因为已经在构造函数里面connect了
    User *rcver = new User(receiver, QString(), user->role == 0 ? 1 : 0);
    Message msg(user, rcver, content, MessageType::SEND_MESSAGE);
    socket->write(Message::messageToByteArray(msg));
}

QString Chat::getFullname(QString username, int role) {
    QString fullname = QString("");
    fullname.append(username);
    fullname.append(QString(" ("));
    QString role_ = role == 0 ? QString("医生") : QString("患者");
    fullname.append(role_);
    fullname.append(QString(") "));
    return fullname;
}

QString Chat::getTextLine(QString line) {
    if (line == QString())
        return line;

    QStringList parts = line.split("_");
    QString content = (parts.size() > 0) ? parts[0] : "";
    QString chatDate = (parts.size() > 1) ? parts[1] : "";
    int isRead = parts[2].toInt();
    QString sender = (parts.size() > 3) ? parts[3] : "";
    int role = sender == this->user->username ? this->user->role : (this->user->role == 0 ? 1 : 0);

    QString textLine;

    textLine.append(getFullname(sender, role).append(QString("：")).append(content)
                    .append(isRead == 0 && user->username != sender ? QString("(未读)") : QString()).append(QChar('\n'))
                    .append(QString("------------------------------------")).append(chatDate)
                    .append(QChar('\n')));

    return textLine;
}

QString Chat::getLine(QString content, QString chatDate, QString isRead, QString sender) {
    return content + QString("_") + chatDate + QString("_") + isRead +QString("_") + sender;
}

void Chat::startVideoCall()
{
    Message msg(user, new User(receiver, QString(), user->role == 0 ? 1 : 0),
                QString(), VIDEO_CALL_REQUEST);
    socket->write(Message::messageToByteArray(msg));

    QMessageBox::information(this, "视频通话", "正在向对方发送通话邀请...");
}

void Chat::handleSocketReadyRead()
{
    QByteArray ba = socket->readAll();
    Message msg = Message::byteArrayToMessage(ba);

    qDebug() << "收到消息类型:" << msg.messageType;

    // 根据消息类型分发处理
    switch (msg.messageType) {
    case MessageType::RECEIVE_MESSAGE:
        handleReceiveMessage(msg);
        break;
    case MessageType::SEND_SUCCESS:
        handleSendSuccess(msg);
        break;
    case MessageType::RECEIVER_OFFLINE:
        handleReceiverOffline(msg);
        break;
    case MessageType::RET_HISTORY:
        handleRetHistory(msg);
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
    case MessageType::VIDEO_DATA:  // 确保这个分支存在
        qDebug() << "处理视频数据，大小:" << msg.content.size();
        handleVideoData(msg);
        break;
    default:
        qDebug() << "未知消息类型:" << msg.messageType;
    }
}

// 原有的消息处理函数（从lambda中移出来）
void Chat::handleReceiveMessage(const Message &msg)
{

    // 判断一下是否是当前我正在聊天的用户发给我的消息
    if (msg.content.split("_")[3] == this->receiver) {
        // 收到的消息显示到对话框里
        QString text = ui->chatTextEdit->toPlainText();
        text.append(getTextLine(msg.content));
        ui->chatTextEdit->setText(text);
    }
}

void Chat::handleSendSuccess(const Message &msg)
{
    // 自己发的消息显示到对话框里
    QString text = ui->chatTextEdit->toPlainText();
    text.append(getTextLine(msg.content));
    ui->chatTextEdit->setText(text);
}

void Chat::handleReceiverOffline(const Message &msg)
{
    QMessageBox::information(this, "对方不在线", "对方不在线，我们会在对方登录时转发您的消息");
    // 自己发的消息显示到对话框里
    QString text = ui->chatTextEdit->toPlainText();
    text.append(getTextLine(msg.content));
    ui->chatTextEdit->setText(text);
}

void Chat::handleRetHistory(const Message &msg)
{
    QStringList lines = msg.content.split("|");
    QString text = ui->chatTextEdit->toPlainText();
    for(const QString &line : lines) {
        text.append(getTextLine(line));
    }
    ui->chatTextEdit->setText(text);
}

void Chat::handleUpdateIsReadSuccess(const Message &msg)
{
    disconnect(this->socket, &QTcpSocket::readyRead, this, nullptr);
    this->close();
}

// 新增的视频通话处理函数
void Chat::handleVideoCallRequest(const Message &msg)
{
    // 确保在主线程执行UI操作
    QMetaObject::invokeMethod(this, [this, msg]() {
        // 创建来电弹窗
        QDialog *callDialog = new QDialog(this);
        callDialog->setWindowTitle("视频通话来电");
        callDialog->setFixedSize(350, 180);
        callDialog->setModal(true);
        callDialog->setAttribute(Qt::WA_DeleteOnClose);

        QVBoxLayout *layout = new QVBoxLayout(callDialog);

        // 来电提示
        QLabel *label = new QLabel(QString("%1 邀请您视频通话").arg(msg.sender->username));
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("font-size: 16px; font-weight: bold; padding: 20px; color: #333;");
        layout->addWidget(label);

        QLabel *tipLabel = new QLabel("请选择接听或挂断");
        tipLabel->setAlignment(Qt::AlignCenter);
        tipLabel->setStyleSheet("color: #666; padding: 10px;");
        layout->addWidget(tipLabel);

        // 按钮区域
        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(20);
        buttonLayout->setContentsMargins(30, 10, 30, 20);

        QPushButton *acceptButton = new QPushButton("接听");
        acceptButton->setFixedSize(100, 40);
        acceptButton->setStyleSheet("QPushButton {"
                                  "background-color: #4CAF50;"
                                  "color: white;"
                                  "font-weight: bold;"
                                  "border-radius: 5px;"
                                  "font-size: 14px;"
                                  "}"
                                  "QPushButton:hover {"
                                  "background-color: #45a049;"
                                  "}");

        QPushButton *rejectButton = new QPushButton("挂断");
        rejectButton->setFixedSize(100, 40);
        rejectButton->setStyleSheet("QPushButton {"
                                  "background-color: #f44336;"
                                  "color: white;"
                                  "font-weight: bold;"
                                  "border-radius: 5px;"
                                  "font-size: 14px;"
                                  "}"
                                  "QPushButton:hover {"
                                  "background-color: #da190b;"
                                  "}");

        buttonLayout->addWidget(acceptButton);
        buttonLayout->addWidget(rejectButton);
        layout->addLayout(buttonLayout);

        // 连接按钮事件
        connect(acceptButton, &QPushButton::clicked, [this, msg, callDialog]() {
            Message reply(this->user, msg.sender, "", VIDEO_CALL_ACCEPT);
            socket->write(Message::messageToByteArray(reply));

            // 打开视频通话窗口
            m_videoCallWindow = new SimpleVideoCall(socket, this->user, msg.sender->username, this);
            m_videoCallWindow->show();

            callDialog->accept();
        });

        connect(rejectButton, &QPushButton::clicked, [this, msg, callDialog]() {
            Message reply(this->user, msg.sender, "", VIDEO_CALL_REJECT);
            socket->write(Message::messageToByteArray(reply));
            callDialog->reject();
        });

        // 显示弹窗并置于最前
        callDialog->show();
        callDialog->raise();
        callDialog->activateWindow();
    });
}

void Chat::handleVideoCallAccept(const Message &msg)
{
    QMetaObject::invokeMethod(this, [this, msg]() {
        QMessageBox::information(this, "视频通话", "对方接受了您的通话请求");
        m_videoCallWindow = new SimpleVideoCall(socket, this->user, msg.sender->username, this);
        m_videoCallWindow->show();
    });
}

void Chat::handleVideoCallReject(const Message &msg)
{
    QMetaObject::invokeMethod(this, [this]() {
        QMessageBox::information(this, "视频通话", "对方拒绝了您的通话请求");
    });
}

void Chat::handleVideoCallEnd(const Message &msg)
{
    QMetaObject::invokeMethod(this, [this]() {
        if (m_videoCallWindow) {
            m_videoCallWindow->close();
            m_videoCallWindow = nullptr;
        }
        QMessageBox::information(this, "视频通话", "通话已结束");
    });
}

void Chat::handleVideoData(const Message &msg)
{
    qDebug() << "=== handleVideoData 被调用 ===";
    qDebug() << "视频数据大小:" << msg.content.size();
    qDebug() << "发送者:" << msg.sender->username;
    qDebug() << "接收者:" << msg.receiver->username;
    qDebug() << "视频窗口是否存在:" << (m_videoCallWindow != nullptr);

    // 确保消息是发给当前用户的
    if (msg.receiver->username != this->user->username) {
        qDebug() << "消息不是发给当前用户的，忽略";
        return;
    }

    if (m_videoCallWindow) {
        qDebug() << "转发给视频窗口";
        // 确保使用正确的数据格式
        m_videoCallWindow->handleIncomingImage(msg.content.toUtf8());
    } else {
        qDebug() << "错误：视频窗口不存在！";
        // 如果视频窗口不存在但收到了视频数据，可能需要创建窗口
        qDebug() << "收到视频数据但窗口未创建，发送者:" << msg.sender->username;
    }
}
