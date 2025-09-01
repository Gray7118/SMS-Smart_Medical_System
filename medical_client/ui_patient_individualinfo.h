/********************************************************************************
** Form generated from reading UI file 'patient_individualinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENT_INDIVIDUALINFO_H
#define UI_PATIENT_INDIVIDUALINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_patient_individualinfo
{
public:
    QLabel *info_change;
    QPushButton *patient_info_sure;
    QPushButton *patient_info_return;
    QLabel *gender_label;
    QLineEdit *gender;
    QLabel *age_label;
    QLabel *phone_label;
    QLineEdit *phonenumber;
    QLineEdit *age;

    void setupUi(QWidget *patient_individualinfo)
    {
        if (patient_individualinfo->objectName().isEmpty())
            patient_individualinfo->setObjectName(QString::fromUtf8("patient_individualinfo"));
        patient_individualinfo->resize(634, 549);
        info_change = new QLabel(patient_individualinfo);
        info_change->setObjectName(QString::fromUtf8("info_change"));
        info_change->setGeometry(QRect(260, 20, 151, 51));
        QFont font;
        font.setPointSize(18);
        info_change->setFont(font);
        patient_info_sure = new QPushButton(patient_individualinfo);
        patient_info_sure->setObjectName(QString::fromUtf8("patient_info_sure"));
        patient_info_sure->setGeometry(QRect(140, 430, 91, 41));
        patient_info_return = new QPushButton(patient_individualinfo);
        patient_info_return->setObjectName(QString::fromUtf8("patient_info_return"));
        patient_info_return->setGeometry(QRect(350, 430, 91, 41));
        gender_label = new QLabel(patient_individualinfo);
        gender_label->setObjectName(QString::fromUtf8("gender_label"));
        gender_label->setGeometry(QRect(90, 80, 71, 51));
        QFont font1;
        font1.setPointSize(12);
        gender_label->setFont(font1);
        gender = new QLineEdit(patient_individualinfo);
        gender->setObjectName(QString::fromUtf8("gender"));
        gender->setGeometry(QRect(160, 90, 231, 41));
        age_label = new QLabel(patient_individualinfo);
        age_label->setObjectName(QString::fromUtf8("age_label"));
        age_label->setGeometry(QRect(90, 180, 51, 31));
        age_label->setFont(font1);
        phone_label = new QLabel(patient_individualinfo);
        phone_label->setObjectName(QString::fromUtf8("phone_label"));
        phone_label->setGeometry(QRect(90, 270, 61, 31));
        phone_label->setFont(font1);
        phonenumber = new QLineEdit(patient_individualinfo);
        phonenumber->setObjectName(QString::fromUtf8("phonenumber"));
        phonenumber->setGeometry(QRect(160, 270, 231, 41));
        age = new QLineEdit(patient_individualinfo);
        age->setObjectName(QString::fromUtf8("age"));
        age->setGeometry(QRect(160, 180, 231, 41));

        retranslateUi(patient_individualinfo);

        QMetaObject::connectSlotsByName(patient_individualinfo);
    } // setupUi

    void retranslateUi(QWidget *patient_individualinfo)
    {
        patient_individualinfo->setWindowTitle(QApplication::translate("patient_individualinfo", "Form", nullptr));
        info_change->setText(QApplication::translate("patient_individualinfo", "\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        patient_info_sure->setText(QApplication::translate("patient_individualinfo", "\347\241\256\345\256\232", nullptr));
        patient_info_return->setText(QApplication::translate("patient_individualinfo", "\350\277\224\345\233\236", nullptr));
        gender_label->setText(QApplication::translate("patient_individualinfo", "\346\200\247\345\210\253", nullptr));
        age_label->setText(QApplication::translate("patient_individualinfo", "\345\271\264\351\276\204", nullptr));
        phone_label->setText(QApplication::translate("patient_individualinfo", "\347\224\265\350\257\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class patient_individualinfo: public Ui_patient_individualinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENT_INDIVIDUALINFO_H
