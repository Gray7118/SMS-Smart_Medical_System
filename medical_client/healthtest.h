//#ifndef HEALTHTEST_H
//#define HEALTHTEST_H

//#include <QWidget>
//#include <QTcpSocket>
//#include <QString>
//#include <QLineEdit>

//#include "patientprofile.h"
//#include "user.h"
//#include "healthtestoutcome.h"

//namespace Ui {
//class healthtest;
//}

//class healthtest : public QWidget
//{
//    Q_OBJECT

//public:
//    explicit healthtest(QTcpSocket *socket, User *user, QWidget *parent = nullptr);
//    ~healthtest();

//private slots:

//    void on_healthtest_return_clicked();

//    void on_healthtest_sure_clicked();

//private:
//    Ui::healthtest *ui;
//    QTcpSocket *socket;
//    User *user;


//    QString Health_Test(int heightint, int weightint,
//                        int heart_rateint, int pressureint_height,
//                        int pressureint_low, int vital_capacityint,
//                        const QString &sexstr, int temperatureint,
//                        bool heightok, bool weightok, bool heartok,
//                        bool presshighok, bool presslowok,
//                        bool vitalok, bool temperaok);

//    QString sexstr;
//    int heightint;
//    int weightint;
//    int heart_rateint;
//    int pressureint_height;
//    int pressureint_low;
//    int temperatureint;
//    int vital_capacityint;
//};

//#endif // HEALTHTEST_H

#ifndef HEALTHTEST_H
#define HEALTHTEST_H

#include <QWidget>
#include <QTcpSocket>
#include <QString>
#include <QLineEdit>
#include <QProgressDialog>

#include "patientprofile.h"
#include "user.h"
#include "healthtestoutcome.h"
#include "aihealthservice.h"

namespace Ui {
class healthtest;
}

class healthtest : public QWidget
{
    Q_OBJECT

public:
    explicit healthtest(QTcpSocket *socket, User *user, QWidget *parent = nullptr);
    ~healthtest();

private slots:
    void on_healthtest_return_clicked();
    void on_healthtest_sure_clicked();

private:
    Ui::healthtest *ui;
    QTcpSocket *socket;
    User *user;

    // AI服务
    AIHealthService* m_aiService;
    QProgressDialog* m_progressDialog;

    // 传统健康评估方法（作为后备方案）
    QString Health_Test(int heightint, int weightint,
                        int heart_rateint, int pressureint_height,
                        int pressureint_low, int vital_capacityint,
                        const QString &sexstr, int temperatureint,
                        bool heightok, bool weightok, bool heartok,
                        bool presshighok, bool presslowok,
                        bool vitalok, bool temperaok);

    // 辅助方法
    void useFallbackAnalysis();
    void showResults(const QString& assessment);

    // 健康数据成员变量
    QString sexstr;
    int heightint;
    int weightint;
    int heart_rateint;
    int pressureint_height;
    int pressureint_low;
    int temperatureint;
    int vital_capacityint;
};

#endif // HEALTHTEST_H
