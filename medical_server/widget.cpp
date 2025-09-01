#include "widget.h"
#include "ui_widget.h"
#include <QNetworkInterface>  // 新增
#include <QDateTime>          // 新增

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 新增：获取并显示IP地址
    QString serverIP = getLocalIPAddress();
    setWindowTitle(QString("医患交流平台服务器 - %1:%2").arg(serverIP).arg(PORT));

    // 开启服务器
    server = new QTcpServer;
    if (server->listen(QHostAddress::AnyIPv4, PORT)) {
        QString info = QString("服务器启动成功！\nIP地址: %1:%2\n客户端请使用此IP连接服务器")
                      .arg(serverIP).arg(PORT);
        QMessageBox::information(this, "服务器状态", info);

        ui->textEdit->append(QString("服务器启动成功 - %1:%2").arg(serverIP).arg(PORT));
    } else {
        QMessageBox::critical(this, "错误", "服务器启动失败！");
    }

    // 监听连接请求
    connect(server, &QTcpServer::newConnection, this, &Widget::newClientHandler);

    QStringList allUsers = DBUtils::getAllUsers();
    for(const QString &user : allUsers) {
        QStringList parts = user.split("_");
        QString line;
        for(const QString &part : parts) {
            line.append(part).append("  ");
        }
        line.append(QChar('\n'));
        ui->allUserTextEdit->append(line);
    }

    QStringList allDoctors = DBUtils::getAllDoctorProfile();
    for(const QString &doctor : allDoctors) {
        QStringList parts = doctor.split("_");
        QString line;
        for(const QString &part : parts) {
            line.append(part).append("  ");
        }
        line.append(QChar('\n'));
        ui->allDoctorTextEdit->append(line);
    }

    QStringList allPatients = DBUtils::getAllPatientProfile();
    for(const QString &patient : allPatients) {
        QStringList parts = patient.split("_");
        QString line;
        for(const QString &part : parts) {
            line.append(part).append("  ");
        }
        line.append(QChar('\n'));
        ui->allPatientTextEdit->append(line);
    }

    QStringList allCases = DBUtils::getAllCases();
    for(const QString &case_ : allCases) {
        QStringList parts = case_.split("_");
        QString line;
        for(const QString &part : parts) {
            line.append(part).append("  ");
        }
        line.append(QChar('\n'));
        ui->allCaseTextEdit->append(line);
    }
}

Widget::~Widget()
{
    delete ui;
}

// 主线程只处理登录和注册请求，其它请求会创建子线程，让子线程自行处理
void Widget::newClientHandler() {
    QTcpSocket *socket = server->nextPendingConnection();

    // 服务器记录日志
    QString text = ui->textEdit->toPlainText();
    text.append(socket->peerAddress().toString()).append(QString(":")).append(QString::number(socket->peerPort())).append(QChar('\n'));
    ui->textEdit->setText(text);

    connect(socket, &QTcpSocket::readyRead, this, [this, socket](){
        // readAll阻塞等待
        QByteArray ba = socket->readAll();
        Message msg = Message::byteArrayToMessage(ba);

        qDebug() << "登录和注册";
        msg.print();

        // 判断MessageType
        if (msg.messageType == MessageType::LOGIN) { // 登录
            if (DBUtils::login(msg.sender->username, msg.sender->password, msg.sender->role)) {
                // 登录成功
                Message returnMsg = Message::serverReplyMessage(MessageType::LOGIN_SUCCESS);
                socket->write(Message::messageToByteArray(returnMsg));

                // 关闭connect，防止抢夺其它地方的消息：登录成功之后才断开，否则用户一旦输错，就无法再登录了
                disconnect(socket, &QTcpSocket::readyRead, this, nullptr);

                // 创建线程，维持和客户端的通信
                MyThread *t = new MyThread(socket, msg.sender);
                t->start();

                // 监听子线程的即时通讯信号，将Message转发给对应的receiver，可能有bug，这里不需要disconnect
                connect(t, &MyThread::sendToMainThread, this, &Widget::threadMessageHandler);

                // 在table中保持该socket
                if (!table.contains(msg.sender->username)) {
                    table.insert(msg.sender->username, socket);
                } else {
                    table[msg.sender->username] = socket;
                }
            } else {
                // 登录失败
                Message returnMsg = Message::serverReplyMessage(MessageType::LOGIN_FAILED);
                socket->write(Message::messageToByteArray(returnMsg));
            }

        } else if (msg.messageType == MessageType::REGISTER) { // 注册
            // 获取gender, age, phoneNumber
            QString content = msg.content;
            QStringList parts;
            QString gender;
            QString age;
            QString phoneNumber;

            if (content.trimmed() != QString()) {
                parts = content.split("_");
                gender = parts[0];
                age = parts[1];
                phoneNumber = parts[2];
            }

            if (DBUtils::signUp(msg.sender->username, msg.sender->password, msg.sender->role, gender, age, phoneNumber)) {
                // 注册成功
                Message returnMsg = Message::serverReplyMessage(MessageType::REGISTER_SUCCESS);
                socket->write(Message::messageToByteArray(returnMsg));
            } else {
                // 注册失败
                Message returnMsg = Message::serverReplyMessage(MessageType::REGISTER_FAILED);
                socket->write(Message::messageToByteArray(returnMsg));
            }
        }
    });
}

void Widget::threadMessageHandler(Message msg) {
     QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");
     QString logMessage;

     qDebug() << "主线程收到消息，类型:" << msg.messageType;
     qDebug() << "从" << msg.sender->username << "到" << msg.receiver->username;

    if (msg.messageType == MessageType::SEND_MESSAGE) { // 发送消息的请求
        if (table.contains(msg.receiver->username)) { // receiver在线
            QTcpSocket *senderSocket = table[msg.sender->username];
            QTcpSocket *receiverSocket = table[msg.receiver->username];

            QDateTime now = QDateTime::currentDateTime();

            // 创建全新的content
            QString content = msg.content + QString("_") + now.toString(DBUtils::DATE_FORMAT) + QString("_") + QString::number(1) +QString("_") + msg.sender->username;

            // 消息存储到数据库，已读
            DBUtils::insertChatMessage(msg.sender->username, msg.receiver->username, now, msg.content, 1);

            Message toReceiverMsg(msg.sender, msg.receiver, content, MessageType::RECEIVE_MESSAGE);
            receiverSocket->write(Message::messageToByteArray(toReceiverMsg));

            // 构造给sender的发送成功Message，sender一定在即时通讯系统
            Message toSenderMsg(msg.sender, msg.receiver, content, MessageType::SEND_SUCCESS);
            senderSocket->write(Message::messageToByteArray(toSenderMsg));
        } else { // receiver不在线
            // 消息存储到数据库
            QDateTime now = QDateTime::currentDateTime();
            DBUtils::insertChatMessage(msg.sender->username, msg.receiver->username, now, msg.content, 0);

            // 创建全新的content
            QString content = msg.content + QString("_") + now.toString(DBUtils::DATE_FORMAT) + QString("_") + QString::number(0) +QString("_") + msg.sender->username;

            // 返回对方不在线
            Message rtnMsg(msg.sender, msg.receiver, content, MessageType::RECEIVER_OFFLINE);
            QTcpSocket *socket = table[msg.sender->username];
            socket->write(Message::messageToByteArray(rtnMsg));
        }

    } else if (msg.messageType == MessageType::QUIT) { // 退出程序的请求，rm socket
        // 服务器记录日志
        QString text = ui->textEdit->toPlainText();
        text.append(QString("用户")).append(msg.sender->username).append(QString("退出登录")).append(QChar('\n'));
        ui->textEdit->setText(text);

        // 返回QUIT_SUCCESS
        table[msg.sender->username]->write(Message::messageToByteArray(Message::serverReplyMessage(MessageType::QUIT_SUCCESS)));

        table.remove(msg.sender->username);

    }

    // 在这里添加视频通话消息处理
    else if (msg.messageType == 54) { // 直接用数字54处理VIDEO_CALL_REQUEST
        qDebug() << "处理视频通话请求，消息类型:" << msg.messageType;
        qDebug() << "接收者用户名:" << msg.receiver->username;
        qDebug() << "用户表中是否存在该用户:" << table.contains(msg.receiver->username);
        qDebug() << "当前在线用户数量:" << table.size();

        // 打印所有在线用户
        for (auto it = table.begin(); it != table.end(); ++it) {
            qDebug() << "在线用户:" << it.key();
        }
        if (table.contains(msg.receiver->username)) {
            QTcpSocket *receiverSocket = table[msg.receiver->username];
            if (receiverSocket && receiverSocket->state() == QAbstractSocket::ConnectedState) {
                qDebug() << "找到接收者Socket，准备转发";
                receiverSocket->write(Message::messageToByteArray(msg));
                qDebug() << "视频通话请求已转发给" << msg.receiver->username;
            } else {
                qDebug() << "接收者Socket状态异常";
            }
        } else {
            qDebug() << "错误：接收者不在用户表中";
        }
    }

    // 处理其他视频通话相关消息
    else if (msg.messageType >= 54 && msg.messageType <= 58) { // 涵盖所有视频通话消息类型
        qDebug() << "处理视频通话相关消息:" << msg.messageType;
        if (table.contains(msg.receiver->username)) {
            QTcpSocket *receiverSocket = table[msg.receiver->username];
            receiverSocket->write(Message::messageToByteArray(msg));
            qDebug() << "视频通话消息已转发";
        }
    }
}

QString Widget::getLocalIPAddress()
{
    QList<QHostAddress> addresses = QNetworkInterface::allAddresses();
    for (const QHostAddress &address : addresses) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol &&
            !address.isLoopback()) {
            QString ip = address.toString();
            if (ip.startsWith("192.168.") || ip.startsWith("10.") || ip.startsWith("172.")) {
                return ip;
            }
        }
    }
    return "127.0.0.1";
}
