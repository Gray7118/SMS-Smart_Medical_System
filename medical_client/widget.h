/*#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

#include "user.h"
#include "message.h"
#include "messagetype.h"
#include "doctorprofile.h"
#include "patientprofile.h"
#include "signup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    Widget(User *user, QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_quitButton_clicked();

    void on_loginButton_clicked();

    void on_signupButton_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
};
#endif // WIDGET_H
*/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QPushButton>

#include "user.h"
#include "message.h"
#include "messagetype.h"
#include "doctorprofile.h"
#include "patientprofile.h"
#include "signup.h"
#include "emergency.h"  // 新增急诊症状界面头文件
#include "navigation/mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    Widget(User *user, QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_quitButton_clicked();
    void on_loginButton_clicked();
    void on_signupButton_clicked();
    void on_emergencyButton_clicked();  // 新增急诊按钮点击槽函数
    void on_pushButton_navigation_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
    QPushButton *emergencyButton;  // 新增急诊按钮成员变量

    void setupEmergencyButton();    // 新增急诊按钮初始化方法
    void handleEmergencyLogin();    // 新增急诊登录处理方法
};

#endif // WIDGET_H
