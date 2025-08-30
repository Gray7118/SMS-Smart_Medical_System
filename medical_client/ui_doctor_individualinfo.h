/********************************************************************************
** Form generated from reading UI file 'doctor_individualinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTOR_INDIVIDUALINFO_H
#define UI_DOCTOR_INDIVIDUALINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doctor_individualinfo
{
public:
    QLabel *info_change;
    QPushButton *doctor_info_sure;
    QPushButton *doctor_info_return;
    QLineEdit *gender;
    QLabel *age_label;
    QLabel *gender_label;
    QLineEdit *phonenumber;
    QLineEdit *age;
    QLabel *phone_label;
    QLabel *department_label;
    QLineEdit *department;

    void setupUi(QWidget *doctor_individualinfo)
    {
        if (doctor_individualinfo->objectName().isEmpty())
            doctor_individualinfo->setObjectName(QString::fromUtf8("doctor_individualinfo"));
        doctor_individualinfo->resize(608, 516);
        info_change = new QLabel(doctor_individualinfo);
        info_change->setObjectName(QString::fromUtf8("info_change"));
        info_change->setGeometry(QRect(200, 20, 241, 51));
        QFont font;
        font.setPointSize(18);
        info_change->setFont(font);
        doctor_info_sure = new QPushButton(doctor_individualinfo);
        doctor_info_sure->setObjectName(QString::fromUtf8("doctor_info_sure"));
        doctor_info_sure->setGeometry(QRect(90, 440, 101, 41));
        doctor_info_return = new QPushButton(doctor_individualinfo);
        doctor_info_return->setObjectName(QString::fromUtf8("doctor_info_return"));
        doctor_info_return->setGeometry(QRect(370, 440, 101, 41));
        gender = new QLineEdit(doctor_individualinfo);
        gender->setObjectName(QString::fromUtf8("gender"));
        gender->setGeometry(QRect(91, 106, 341, 41));
        age_label = new QLabel(doctor_individualinfo);
        age_label->setObjectName(QString::fromUtf8("age_label"));
        age_label->setGeometry(QRect(91, 153, 131, 41));
        QFont font1;
        font1.setPointSize(12);
        age_label->setFont(font1);
        gender_label = new QLabel(doctor_individualinfo);
        gender_label->setObjectName(QString::fromUtf8("gender_label"));
        gender_label->setGeometry(QRect(91, 72, 151, 41));
        gender_label->setFont(font1);
        phonenumber = new QLineEdit(doctor_individualinfo);
        phonenumber->setObjectName(QString::fromUtf8("phonenumber"));
        phonenumber->setGeometry(QRect(90, 280, 341, 41));
        age = new QLineEdit(doctor_individualinfo);
        age->setObjectName(QString::fromUtf8("age"));
        age->setGeometry(QRect(91, 188, 341, 41));
        phone_label = new QLabel(doctor_individualinfo);
        phone_label->setObjectName(QString::fromUtf8("phone_label"));
        phone_label->setGeometry(QRect(91, 235, 141, 41));
        phone_label->setFont(font1);
        department_label = new QLabel(doctor_individualinfo);
        department_label->setObjectName(QString::fromUtf8("department_label"));
        department_label->setGeometry(QRect(91, 316, 141, 41));
        department_label->setFont(font1);
        department = new QLineEdit(doctor_individualinfo);
        department->setObjectName(QString::fromUtf8("department"));
        department->setGeometry(QRect(90, 360, 341, 41));

        retranslateUi(doctor_individualinfo);

        QMetaObject::connectSlotsByName(doctor_individualinfo);
    } // setupUi

    void retranslateUi(QWidget *doctor_individualinfo)
    {
        doctor_individualinfo->setWindowTitle(QApplication::translate("doctor_individualinfo", "Form", nullptr));
        info_change->setText(QApplication::translate("doctor_individualinfo", "\344\277\241\346\201\257\345\256\214\345\226\204", nullptr));
        doctor_info_sure->setText(QApplication::translate("doctor_individualinfo", "\347\241\256\345\256\232", nullptr));
        doctor_info_return->setText(QApplication::translate("doctor_individualinfo", "\350\277\224\345\233\236", nullptr));
        age_label->setText(QApplication::translate("doctor_individualinfo", "\345\271\264\351\276\204", nullptr));
        gender_label->setText(QApplication::translate("doctor_individualinfo", "\346\200\247\345\210\253", nullptr));
        phone_label->setText(QApplication::translate("doctor_individualinfo", "\347\224\265\350\257\235", nullptr));
        department_label->setText(QApplication::translate("doctor_individualinfo", "\347\247\221\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class doctor_individualinfo: public Ui_doctor_individualinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTOR_INDIVIDUALINFO_H
