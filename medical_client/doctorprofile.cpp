#include "doctorprofile.h"
#include "ui_doctorprofile.h"
#include <QQuickWidget>
#include <QQmlContext>
#include "ChatMainWindow.h"

DoctorProfile::DoctorProfile(QTcpSocket *socket, User *user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doctorProfile)
{
    this ->socket = socket;
    this->user = user;
    ui->setupUi(this);

    this->setWindowTitle(QString("医生页面"));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);
}

DoctorProfile::~DoctorProfile()
{
    delete ui;
}

void DoctorProfile::on_quitButton_clicked()
{
    // 发送退出的请求
    Message msg(user, new User, QString(), MessageType::QUIT);
    socket->write(Message::messageToByteArray(msg));

    connect(socket, &QTcpSocket::readyRead, this, [this](){
        QByteArray ba = this->socket->readAll();
        Message msg = Message::byteArrayToMessage(ba);

        msg.print();

        disconnect(socket, &QTcpSocket::readyRead, this, nullptr);

        if(msg.messageType == MessageType::QUIT_SUCCESS) {
            this->close();
        }
    });
}

void DoctorProfile::on_chatButton_clicked()
{
    qDebug() << "点击聊天按钮";

    // 直接创建窗口，不使用静态或成员变量
    ChatMainWindow *mainWindow = new ChatMainWindow(socket, user, this);
    mainWindow->setWindowTitle("医生聊天界面 - " + user->username);
    mainWindow->setWindowFlags(Qt::Window);

    // 居中显示
    mainWindow->move(839, 341);

    // 显示窗口
    mainWindow->show();
    mainWindow->raise();
    mainWindow->activateWindow();

    // 连接返回信号
    connect(mainWindow, &ChatMainWindow::returnToProfile, this, [this, mainWindow](){
        this->show();
        mainWindow->deleteLater();
    });

    // 窗口关闭时自动删除
    mainWindow->setAttribute(Qt::WA_DeleteOnClose);
}

void DoctorProfile::on_appointmentButton_clicked() // 过时
{
    seeAllSchedule* sptinf = new seeAllSchedule(socket, user);
    sptinf->setWindowTitle(QString("查看挂号患者信息"));
    sptinf->show();
    this->hide();
}

void DoctorProfile::on_recordButton_clicked() // 过时
{
    doctorcase* doct = new doctorcase(socket, user);
    doct->setWindowTitle(QString("查看并修改病历"));
    doct->show();
    this->hide();
}

void DoctorProfile::on_prescriptionButton_clicked() // 过时
{
    doctorcase* doct = new doctorcase(socket, user);
    doct->setWindowTitle(QString("查看处方与缴费"));
    doct->show();
    this->hide();
}

void DoctorProfile::on_profileButton_clicked()
{
    doctor_individualinfo* doc = new doctor_individualinfo(socket, user);
    doc->setWindowTitle(QString("个人信息编辑"));
    doc->show();
    this->hide();
}

void DoctorProfile::on_appointmentCaseButton_clicked()
{
    doctorcase* doct = new doctorcase(socket, user);
    doct->setWindowTitle(QString("编辑病例和处方"));
    doct->show();
    this->hide();
}

void DoctorProfile::on_scheduleButton_clicked()
{
    seeAllSchedule* sptinf = new seeAllSchedule(socket, user);
    sptinf->setWindowTitle(QString("查看所有挂号和病例"));
    sptinf->show();
    this->hide();
}

// 新增槽函数：发送邮件给患者
void DoctorProfile::on_emailPatientButton_clicked()
{
    if (!emailWindow) {
        emailWindow = new SendEmail();                // 独立窗口，不传 this
        emailWindow->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放

        // 窗口关闭时重置指针
        connect(emailWindow, &QWidget::destroyed, this, [this]() {
            emailWindow = nullptr;
        });
    }

    emailWindow->show();
    emailWindow->raise();
    emailWindow->activateWindow();
}
