#ifndef DOCTORPROFILE_H
#define DOCTORPROFILE_H

#include <QWidget>
#include <QMessageBox>
#include <QTcpSocket>

#include "seepatientinfo.h"
#include "user.h"
#include "chat.h"
#include "message.h"
#include "messagetype.h"
#include "selectreceiver.h"
#include "doctorcase.h"
#include "doctor_individualinfo.h"
// 新增：引入 SendEmail
#include "email/demos/demo2/sendemail.h"

namespace Ui {
class doctorProfile;
}

class DoctorProfile : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorProfile(QTcpSocket *socket, User *user, QWidget *parent = nullptr);
    ~DoctorProfile();

private slots:
    void on_quitButton_clicked();

    void on_chatButton_clicked();

    void on_appointmentButton_clicked();

    void on_recordButton_clicked();

    void on_prescriptionButton_clicked();

    void on_profileButton_clicked();

    void on_appointmentCaseButton_clicked();

    void on_scheduleButton_clicked();

    // 新增槽函数：点击发送邮件给患者
    void on_emailPatientButton_clicked();

private:
    Ui::doctorProfile *ui;
    User *user;
    QTcpSocket *socket;

    // 邮件窗口指针
    SendEmail *emailWindow = nullptr;
};

#endif // DOCTORPROFILE_H
