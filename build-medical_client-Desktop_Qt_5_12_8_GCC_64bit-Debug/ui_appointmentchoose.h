/********************************************************************************
** Form generated from reading UI file 'appointmentchoose.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINTMENTCHOOSE_H
#define UI_APPOINTMENTCHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_appointmentchoose
{
public:
    QLabel *label_choose_appointment;
    QPushButton *department_choose;
    QPushButton *time_choose;
    QPushButton *appointreturn;

    void setupUi(QWidget *appointmentchoose)
    {
        if (appointmentchoose->objectName().isEmpty())
            appointmentchoose->setObjectName(QString::fromUtf8("appointmentchoose"));
        appointmentchoose->resize(620, 522);
        label_choose_appointment = new QLabel(appointmentchoose);
        label_choose_appointment->setObjectName(QString::fromUtf8("label_choose_appointment"));
        label_choose_appointment->setGeometry(QRect(90, 20, 511, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font.setPointSize(20);
        label_choose_appointment->setFont(font);
        department_choose = new QPushButton(appointmentchoose);
        department_choose->setObjectName(QString::fromUtf8("department_choose"));
        department_choose->setGeometry(QRect(160, 130, 251, 91));
        QFont font1;
        font1.setPointSize(10);
        department_choose->setFont(font1);
        time_choose = new QPushButton(appointmentchoose);
        time_choose->setObjectName(QString::fromUtf8("time_choose"));
        time_choose->setGeometry(QRect(160, 280, 251, 91));
        time_choose->setFont(font1);
        appointreturn = new QPushButton(appointmentchoose);
        appointreturn->setObjectName(QString::fromUtf8("appointreturn"));
        appointreturn->setGeometry(QRect(450, 440, 121, 61));

        retranslateUi(appointmentchoose);

        QMetaObject::connectSlotsByName(appointmentchoose);
    } // setupUi

    void retranslateUi(QWidget *appointmentchoose)
    {
        appointmentchoose->setWindowTitle(QApplication::translate("appointmentchoose", "Form", nullptr));
        label_choose_appointment->setText(QApplication::translate("appointmentchoose", "\351\200\211\346\213\251\346\202\250\347\232\204\346\214\202\345\217\267\346\243\200\347\264\242\346\226\271\345\274\217", nullptr));
        department_choose->setText(QApplication::translate("appointmentchoose", "\346\214\211\347\247\221\345\256\244\346\243\200\347\264\242", nullptr));
        time_choose->setText(QApplication::translate("appointmentchoose", "\346\214\211\346\227\266\351\227\264\346\243\200\347\264\242", nullptr));
        appointreturn->setText(QApplication::translate("appointmentchoose", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class appointmentchoose: public Ui_appointmentchoose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINTMENTCHOOSE_H
