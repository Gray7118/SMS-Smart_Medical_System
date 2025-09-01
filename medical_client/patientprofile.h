#ifndef PATIENTPROFILE_H
#define PATIENTPROFILE_H

#include <QWidget>
#include <QMessageBox>
#include <QTcpSocket>
#include <QString>

#include "user.h"
#include "chat.h"
#include "message.h"
#include "messagetype.h"
#include "selectreceiver.h"
#include "appointmentchoose.h"
#include "healthtest.h"
#include "seedoctorinfo.h"
#include "patientcase.h"
#include "patient_individualinfo.h"
#include "department_choose.h"

// 新增：引入 SendEmail
#include "email/demos/demo2/sendemail.h"

namespace Ui {
class PatientProfile;
}

class PatientProfile : public QWidget
{
    Q_OBJECT

public:
    explicit PatientProfile(QTcpSocket *socket, User *user, QWidget *parent = nullptr);
    ~PatientProfile();

private slots:
    void on_quitButton_clicked();
    void on_chatButton_clicked();
    void on_appointmentButton_clicked();
    void on_healthButton_clicked();
    void on_doctorButton_clicked();
    void on_medicalRecordButton_clicked();
    void on_profileButton_clicked();
    void on_prescriptionButton_clicked();
    void on_appointmentCaseButton_clicked();
    void on_scheduleButton_clicked();

    // 新增槽函数：发送邮件给医生
    void on_emailDoctorButton_clicked();

private:
    Ui::PatientProfile *ui;
    User *user;
    QTcpSocket *socket;

    // 邮件窗口指针
    SendEmail *emailWindow = nullptr;
};

#endif // PATIENTPROFILE_H
