/********************************************************************************
** Form generated from reading UI file 'doctor_choose.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTOR_CHOOSE_H
#define UI_DOCTOR_CHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doctor_choose
{
public:
    QComboBox *choose_doctor;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *input_schedule;
    QTextEdit *see_doctor;
    QPushButton *returnbutton;
    QPushButton *surebutton;

    void setupUi(QWidget *doctor_choose)
    {
        if (doctor_choose->objectName().isEmpty())
            doctor_choose->setObjectName(QString::fromUtf8("doctor_choose"));
        doctor_choose->resize(592, 520);
        QFont font;
        font.setPointSize(20);
        doctor_choose->setFont(font);
        choose_doctor = new QComboBox(doctor_choose);
        choose_doctor->setObjectName(QString::fromUtf8("choose_doctor"));
        choose_doctor->setGeometry(QRect(10, 90, 221, 51));
        label = new QLabel(doctor_choose);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 281, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("AcadEref"));
        font1.setPointSize(22);
        label->setFont(font1);
        label_2 = new QLabel(doctor_choose);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 150, 281, 71));
        label_2->setFont(font1);
        input_schedule = new QLineEdit(doctor_choose);
        input_schedule->setObjectName(QString::fromUtf8("input_schedule"));
        input_schedule->setGeometry(QRect(10, 220, 221, 61));
        see_doctor = new QTextEdit(doctor_choose);
        see_doctor->setObjectName(QString::fromUtf8("see_doctor"));
        see_doctor->setGeometry(QRect(240, 10, 331, 331));
        returnbutton = new QPushButton(doctor_choose);
        returnbutton->setObjectName(QString::fromUtf8("returnbutton"));
        returnbutton->setGeometry(QRect(80, 390, 141, 51));
        surebutton = new QPushButton(doctor_choose);
        surebutton->setObjectName(QString::fromUtf8("surebutton"));
        surebutton->setGeometry(QRect(340, 390, 141, 51));

        retranslateUi(doctor_choose);

        QMetaObject::connectSlotsByName(doctor_choose);
    } // setupUi

    void retranslateUi(QWidget *doctor_choose)
    {
        doctor_choose->setWindowTitle(QApplication::translate("doctor_choose", "Form", nullptr));
        label->setText(QApplication::translate("doctor_choose", "\350\257\267\351\200\211\346\213\251\345\214\273\347\224\237\345\247\223\345\220\215", nullptr));
        label_2->setText(QApplication::translate("doctor_choose", "\350\257\267\350\276\223\345\205\245\351\242\204\347\272\246\346\227\266\351\227\264", nullptr));
        returnbutton->setText(QApplication::translate("doctor_choose", "\350\277\224\345\233\236", nullptr));
        surebutton->setText(QApplication::translate("doctor_choose", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class doctor_choose: public Ui_doctor_choose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTOR_CHOOSE_H
