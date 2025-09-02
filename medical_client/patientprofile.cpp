#include "patientprofile.h"
#include "ui_patientprofile.h"
#include <QQuickWidget>
#include <QQmlContext>
#include "ChatMainWindow.h"

PatientProfile::PatientProfile(QTcpSocket *socket, User *user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientProfile)
{
    this->socket = socket;
    this->user = user;
    ui->setupUi(this);

    this->setWindowTitle(QString("患者页面"));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);
}

PatientProfile::~PatientProfile()
{
    delete ui;
}

void PatientProfile::on_quitButton_clicked()
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

void PatientProfile::on_chatButton_clicked()
{
    qDebug() << "点击聊天按钮";

    // 直接创建窗口，不使用静态或成员变量
    ChatMainWindow *mainWindow = new ChatMainWindow(socket, user, this);
    mainWindow->setWindowTitle("患者聊天界面 - " + user->username);
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

void PatientProfile::on_appointmentButton_clicked() // 过时
{
    appointmentchoose* appcho = new appointmentchoose(socket, user);
    appcho->setWindowTitle(QString("挂号检索"));
    appcho->show();
    this->hide();
}

void PatientProfile::on_healthButton_clicked()
{
    healthtest* heates = new healthtest(socket, user);
    heates->setWindowTitle(QString("健康评估"));
    heates->show();
    this->hide();
}

void PatientProfile::on_doctorButton_clicked()
{
    seedoctorinfo* sdin = new seedoctorinfo(socket, user);
    sdin->setWindowTitle(QString("查看医生信息"));
    sdin->show();
    this->hide();
}

void PatientProfile::on_medicalRecordButton_clicked() // 过时
{
    patientcase *pc =new patientcase(socket, user);
    pc->setWindowTitle(QString("查看病历"));
    pc->show();
    this->hide();
}

void PatientProfile::on_profileButton_clicked()
{
    patient_individualinfo *pind = new patient_individualinfo(socket, user);
    pind->setWindowTitle(QString("查看个人信息"));
    pind->show();
    this->hide();

}

void PatientProfile::on_prescriptionButton_clicked() // 过时
{
    patientcase *pc =new patientcase(socket, user);
    pc->setWindowTitle(QString("查看病历"));
    pc->show();
    this->hide();
}

void PatientProfile::on_appointmentCaseButton_clicked()
{
    patientcase *pc =new patientcase(socket, user);
    pc->setWindowTitle(QString("查看病历"));
    pc->show();
    this->hide();
}

void PatientProfile::on_scheduleButton_clicked()
{ // 挂号
    department_choose *dep_cho = new department_choose(socket, user);
    dep_cho->setWindowTitle(QString("挂号"));
    dep_cho->show();
    this->hide();
}

// 新增槽函数：打开邮件窗口
void PatientProfile::on_emailDoctorButton_clicked()
{
    // 如果窗口还没创建，才新建
    if (!emailWindow) {
        emailWindow = new SendEmail();              // 不传 this，独立窗口
        emailWindow->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存

        // 窗口关闭时置空指针，避免重复创建
        connect(emailWindow, &QWidget::destroyed, this, [this]() {
            emailWindow = nullptr;
        });
    }

    // 显示窗口并激活
    emailWindow->show();
    emailWindow->raise();
    emailWindow->activateWindow();
}
