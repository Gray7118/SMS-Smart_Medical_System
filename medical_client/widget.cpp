/*#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle(QString("如医医患平台欢迎您！"));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);

    // 连接服务器
    QString ip = QString("192.168.40.134");
    QString port = QString("8888");
    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress(ip), port.toShort());

    // 回车键直接登录
    connect(ui->usernameLineEdit, &QLineEdit::returnPressed, this, &Widget::on_loginButton_clicked);
    connect(ui->passwordLineEdit, &QLineEdit::returnPressed, this, &Widget::on_loginButton_clicked);
}

Widget::Widget(User *user, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->usernameLineEdit->setText(user->username);
    ui->passwordLineEdit->setText(user->password);
    if (user->role == 1) {
        ui->patientRadioButton->click();
    }

    // 连接服务器
    QString ip = QString("192.168.40.134");
    QString port = QString("8888");
    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress(ip), port.toShort());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_quitButton_clicked()
{
    this->close();
}

void Widget::on_loginButton_clicked()
{
    // 获取用户名和密码，以及身份
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    int role = 0;
    if (ui->patientRadioButton->isChecked()) // 病人role=1
        role++;
    User *user = new User(username, password, role);

    // 构造Message对象
    Message msg(user, new User, QString(), MessageType::LOGIN);

    // 传输Message
    socket->write(Message::messageToByteArray(msg));

    // 阻塞等待服务器的响应
    connect(socket, &QTcpSocket::readyRead, this, [this, username, password, role, user](){
        QByteArray ba = socket->readAll();
        Message msg = Message::byteArrayToMessage(ba);

        qDebug() << "服务器对登录的响应";
        msg.print();

        // 关闭connect，防止抢夺其它地方的消息
        disconnect(socket, &QTcpSocket::readyRead, this, nullptr);

        // 判断是否登录成功
        if (msg.messageType == MessageType::LOGIN_SUCCESS) {
            // 登录成功，提示框
            QString msg = QString(username);
            msg.append(QString("，欢迎您！"));
            QMessageBox::information(0, QString("登录成功"), msg);

            // 跳转到对应窗口
            this->hide();
            if (role == 0) {
                DoctorProfile *doctorProfile = new DoctorProfile(socket, user);
                doctorProfile->setWindowTitle(QString("医生界面"));
                doctorProfile->show();
            } else if (role == 1) {
                PatientProfile *patientProfile = new PatientProfile(socket, user);
                patientProfile->setWindowTitle(QString("患者界面"));
                patientProfile->show();
            }
        } else if (msg.messageType == MessageType::LOGIN_FAILED) {
            // 登录失败
            ui->usernameLineEdit->setText(QString(""));
            ui->passwordLineEdit->setText(QString(""));
            QMessageBox::information(0, QString("登录失败"), QString("用户名或密码不正确"));
        }
    });
}






void Widget::on_signupButton_clicked()
{
    SignUp *signUp = new SignUp(socket);
    signUp->show();
    this->close();
}*/

/*#include "widget.h"
#include "ui_widget.h"
#include "navigation/mainwindow.h"
#include "navigation/mydialog.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , emergencyButton(new QPushButton(this))  // 初始化急诊按钮
{
    ui->setupUi(this);

    this->setWindowTitle(QString("如医医患平台欢迎您！"));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);

    // 初始化急诊按钮
    setupEmergencyButton();

    // 连接服务器
    QString ip = QString("127.0.0.1");
    QString port = QString("8888");
    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress(ip), port.toShort());

    // 回车键直接登录
    connect(ui->usernameLineEdit, &QLineEdit::returnPressed, this, &Widget::on_loginButton_clicked);
    connect(ui->passwordLineEdit, &QLineEdit::returnPressed, this, &Widget::on_loginButton_clicked);
}

Widget::Widget(User *user, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , emergencyButton(new QPushButton(this))
{
    ui->setupUi(this);

    ui->usernameLineEdit->setText(user->username);
    ui->passwordLineEdit->setText(user->password);
    if (user->role == 1) {
        ui->patientRadioButton->click();
    }

    // 初始化急诊按钮
    setupEmergencyButton();

    // 连接服务器
    QString ip = QString("127.0.0.1");
    QString port = QString("8888");
    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress(ip), port.toShort());
}

Widget::~Widget()
{
    delete ui;
    delete emergencyButton;
}

void Widget::setupEmergencyButton()
{
    emergencyButton->setText("急诊通道");
    emergencyButton->setGeometry(QRect(110, 60, 190, 50));
    emergencyButton->setStyleSheet("QPushButton { background-color: #ff5555; color: white; }");
    connect(emergencyButton, &QPushButton::clicked, this, &Widget::on_emergencyButton_clicked);
}

void Widget::on_quitButton_clicked()
{
    this->close();
}

void Widget::on_loginButton_clicked()
{
    // 原有登录逻辑保持不变
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    int role = ui->patientRadioButton->isChecked() ? 1 : 0;
    User *user = new User(username, password, role);

    Message msg(user, new User, QString(), MessageType::LOGIN);
    socket->write(Message::messageToByteArray(msg));

    connect(socket, &QTcpSocket::readyRead, this, [this, username, role, user](){
        QByteArray ba = socket->readAll();
        Message msg = Message::byteArrayToMessage(ba);
        disconnect(socket, &QTcpSocket::readyRead, this, nullptr);

        if (msg.messageType == MessageType::LOGIN_SUCCESS) {
            this->hide();
            if (role == 0) {
                DoctorProfile *doctorProfile = new DoctorProfile(socket, user);
                doctorProfile->show();
            } else {
                PatientProfile *patientProfile = new PatientProfile(socket, user);
                patientProfile->show();
            }
        } else {
            QMessageBox::warning(this, "登录失败", "用户名或密码不正确");
        }
    });
}


void Widget::on_signupButton_clicked()
{
    SignUp *signUp = new SignUp(socket);
    signUp->show();
    this->close();
}

void Widget::on_emergencyButton_clicked()
{
    // 急诊登录处理
    handleEmergencyLogin();
}

void Widget::handleEmergencyLogin()
{
    User *emergencyUser = new User("急诊病人", "123", 1); // 使用预设急诊账号

    Message msg(emergencyUser, new User, QString(), MessageType::LOGIN);
    socket->write(Message::messageToByteArray(msg));

    connect(socket, &QTcpSocket::readyRead, this, [this, emergencyUser](){
        QByteArray ba = socket->readAll();
        Message msg = Message::byteArrayToMessage(ba);
        disconnect(socket, &QTcpSocket::readyRead, this, nullptr);

        if (msg.messageType == MessageType::LOGIN_SUCCESS) {
            this->hide();
            EmergencySymptoms *symptomsPage = new EmergencySymptoms(socket, emergencyUser);
            symptomsPage->setWindowTitle("急诊症状描述");
            symptomsPage->show();
        } else {
            QMessageBox::critical(this, "急诊通道异常", "无法进入急诊模式，请联系管理员");
        }
    });
}


#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , emergencyButton(new QPushButton(this))  // 初始化急诊按钮
{
    ui->setupUi(this);

    this->setWindowTitle(QString("中国无国界医疗平台平台欢迎您！"));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);

    // 初始化急诊按钮
    setupEmergencyButton();

    // 连接服务器
    QString ip = QString("127.0.0.1");
    QString port = QString("8888");
    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress(ip), port.toShort());

    // 回车键直接登录
    connect(ui->usernameLineEdit, &QLineEdit::returnPressed, this, &Widget::on_loginButton_clicked);
    connect(ui->passwordLineEdit, &QLineEdit::returnPressed, this, &Widget::on_loginButton_clicked);
}

Widget::Widget(User *user, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , emergencyButton(new QPushButton(this))
{
    ui->setupUi(this);

    ui->usernameLineEdit->setText(user->username);
    ui->passwordLineEdit->setText(user->password);
    if (user->role == 1) {
        ui->patientRadioButton->click();
    }

    // 初始化急诊按钮
    setupEmergencyButton();

    // 连接服务器
    QString ip = QString("127.0.0.1");
    QString port = QString("8888");
    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress(ip), port.toShort());
}

Widget::~Widget()
{
    delete ui;
    delete emergencyButton;
}

void Widget::setupEmergencyButton()
{
    emergencyButton->setText("急诊通道");
    emergencyButton->setGeometry(QRect(110, 70, 190, 50));
    emergencyButton->setStyleSheet("QPushButton { background-color: #ff5555; color: white; }");
    connect(emergencyButton, &QPushButton::clicked, this, &Widget::on_emergencyButton_clicked);
}

void Widget::on_quitButton_clicked()
{
    this->close();
}

void Widget::on_loginButton_clicked()
{
    // 原有登录逻辑保持不变
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    int role = ui->patientRadioButton->isChecked() ? 1 : 0;
    User *user = new User(username, password, role);

    Message msg(user, new User, QString(), MessageType::LOGIN);
    socket->write(Message::messageToByteArray(msg));

    connect(socket, &QTcpSocket::readyRead, this, [this, username, role, user](){
        QByteArray ba = socket->readAll();
        Message msg = Message::byteArrayToMessage(ba);
        disconnect(socket, &QTcpSocket::readyRead, this, nullptr);

        if (msg.messageType == MessageType::LOGIN_SUCCESS) {
            this->hide();
            if (role == 0) {
                DoctorProfile *doctorProfile = new DoctorProfile(socket, user);
                doctorProfile->show();
            } else {
                PatientProfile *patientProfile = new PatientProfile(socket, user);
                patientProfile->show();
            }
        } else {
            QMessageBox::warning(this, "登录失败", "用户名或密码不正确");
        }
    });
}

void Widget::on_signupButton_clicked()
{
    SignUp *signUp = new SignUp(socket);
    signUp->show();
    this->close();
}

void Widget::on_emergencyButton_clicked()
{
    // 急诊登录处理
    handleEmergencyLogin();
}

void Widget::handleEmergencyLogin()
{
    User *emergencyUser = new User("急诊病人", "123", 1); // 使用预设急诊账号

    Message msg(emergencyUser, new User, QString(), MessageType::LOGIN);
    socket->write(Message::messageToByteArray(msg));

    connect(socket, &QTcpSocket::readyRead, this, [this, emergencyUser](){
        QByteArray ba = socket->readAll();
        Message msg = Message::byteArrayToMessage(ba);
        disconnect(socket, &QTcpSocket::readyRead, this, nullptr);

        if (msg.messageType == MessageType::LOGIN_SUCCESS) {
            this->hide();
            EmergencySymptoms *symptomsPage = new EmergencySymptoms(socket, emergencyUser);
            symptomsPage->setWindowTitle("急诊症状描述");
            symptomsPage->show();
        } else {
            QMessageBox::critical(this, "急诊通道异常", "无法进入急诊模式，请联系管理员");
        }
    });
}
*/

#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "navigation/mainwindow.h"


void Widget::on_pushButton_navigation_clicked()
{
    // 动态创建窗口，点击按钮才显示
    MainWindow *navWin = new MainWindow;
    navWin->setWindowTitle("医院导航(Guide)");
    navWin->show();
}



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle(QString("寰宇医桥"));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);

    // 设置急诊按钮样式
    ui->emergencyButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #ff5555;"
        "   color: white;"
        "   border-radius: 8px;"
        "   padding: 12px 24px;"
        "   font-size: 16px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background-color: #e64545;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #d63535;"
        "}"
    );

    // 连接服务器
    QString ip = QString("192.168.174.134");
    QString port = QString("8888");
    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress(ip), port.toShort());

    // 回车键直接登录
    connect(ui->usernameLineEdit, &QLineEdit::returnPressed, this, &Widget::on_loginButton_clicked);
    connect(ui->passwordLineEdit, &QLineEdit::returnPressed, this, &Widget::on_loginButton_clicked);
}

Widget::Widget(User *user, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->usernameLineEdit->setText(user->username);
    ui->passwordLineEdit->setText(user->password);
    if (user->role == 1) {
        ui->patientRadioButton->click();
    }

    // 设置急诊按钮样式
    ui->emergencyButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #ff5555;"
        "   color: white;"
        "}"
    );

    // 连接服务器
//    QString ip = QString("127.0.0.1");
    QString ip = QString("192.168.174.134");
    QString port = QString("8888");
    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress(ip), port.toShort());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_quitButton_clicked()
{
    this->close();
}

void Widget::on_loginButton_clicked()
{
    // 原有登录逻辑保持不变
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    int role = ui->patientRadioButton->isChecked() ? 1 : 0;
    User *user = new User(username, password, role);

    Message msg(user, new User, QString(), MessageType::LOGIN);
    socket->write(Message::messageToByteArray(msg));

    connect(socket, &QTcpSocket::readyRead, this, [this, username, role, user](){
        QByteArray ba = socket->readAll();
        Message msg = Message::byteArrayToMessage(ba);
        disconnect(socket, &QTcpSocket::readyRead, this, nullptr);

        if (msg.messageType == MessageType::LOGIN_SUCCESS) {
            this->hide();
            if (role == 0) {
                DoctorProfile *doctorProfile = new DoctorProfile(socket, user);
                doctorProfile->show();
            } else {
                PatientProfile *patientProfile = new PatientProfile(socket, user);
                patientProfile->show();
            }
        } else {
            QMessageBox::warning(this, "登录失败", "用户名或密码不正确");
        }
    });
}

void Widget::on_signupButton_clicked()
{
    SignUp *signUp = new SignUp(socket);
    signUp->show();
    this->close();
}

void Widget::on_emergencyButton_clicked()
{
    // 急诊登录处理
    User *emergencyUser = new User("急诊病人", "123", 1); // 使用预设急诊账号

    Message msg(emergencyUser, new User, QString(), MessageType::LOGIN);
    socket->write(Message::messageToByteArray(msg));

    connect(socket, &QTcpSocket::readyRead, this, [this, emergencyUser](){
        QByteArray ba = socket->readAll();
        Message msg = Message::byteArrayToMessage(ba);
        disconnect(socket, &QTcpSocket::readyRead, this, nullptr);

        if (msg.messageType == MessageType::LOGIN_SUCCESS) {
            this->hide();
            EmergencySymptoms *symptomsPage = new EmergencySymptoms(socket, emergencyUser);
            symptomsPage->setWindowTitle("急诊症状描述");
            symptomsPage->show();
        } else {
            QMessageBox::critical(this, "急诊通道异常", "无法进入急诊模式，请联系管理员");
        }
    });
}

