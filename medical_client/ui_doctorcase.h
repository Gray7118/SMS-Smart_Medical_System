/********************************************************************************
** Form generated from reading UI file 'doctorcase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORCASE_H
#define UI_DOCTORCASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doctorcase
{
public:
    QLabel *label_seecase;
    QTextEdit *seecase;
    QLabel *label_addcase;
    QLineEdit *patient_username;
    QLabel *label_patient_username;
    QLineEdit *doctor_username;
    QLabel *label_doctor_username;
    QLineEdit *date;
    QLabel *label_date;
    QLineEdit *department;
    QLabel *label_department;
    QLineEdit *symptoms;
    QLabel *label_symptoms;
    QLabel *label_diagnosis;
    QLabel *label_medicine;
    QLineEdit *diagnosis;
    QLineEdit *medicine;
    QPushButton *doctorcase_return;
    QPushButton *doctorcase_sure;
    QPushButton *doctorcase_sure_2;

    void setupUi(QWidget *doctorcase)
    {
        if (doctorcase->objectName().isEmpty())
            doctorcase->setObjectName(QString::fromUtf8("doctorcase"));
        doctorcase->resize(624, 1283);
        label_seecase = new QLabel(doctorcase);
        label_seecase->setObjectName(QString::fromUtf8("label_seecase"));
        label_seecase->setGeometry(QRect(220, 10, 641, 51));
        QFont font;
        font.setPointSize(13);
        label_seecase->setFont(font);
        seecase = new QTextEdit(doctorcase);
        seecase->setObjectName(QString::fromUtf8("seecase"));
        seecase->setGeometry(QRect(30, 70, 571, 281));
        label_addcase = new QLabel(doctorcase);
        label_addcase->setObjectName(QString::fromUtf8("label_addcase"));
        label_addcase->setGeometry(QRect(220, 440, 811, 51));
        label_addcase->setFont(font);
        patient_username = new QLineEdit(doctorcase);
        patient_username->setObjectName(QString::fromUtf8("patient_username"));
        patient_username->setGeometry(QRect(200, 510, 271, 41));
        label_patient_username = new QLabel(doctorcase);
        label_patient_username->setObjectName(QString::fromUtf8("label_patient_username"));
        label_patient_username->setGeometry(QRect(40, 510, 151, 31));
        label_patient_username->setFont(font);
        doctor_username = new QLineEdit(doctorcase);
        doctor_username->setObjectName(QString::fromUtf8("doctor_username"));
        doctor_username->setGeometry(QRect(200, 570, 271, 41));
        label_doctor_username = new QLabel(doctorcase);
        label_doctor_username->setObjectName(QString::fromUtf8("label_doctor_username"));
        label_doctor_username->setGeometry(QRect(40, 570, 161, 31));
        label_doctor_username->setFont(font);
        date = new QLineEdit(doctorcase);
        date->setObjectName(QString::fromUtf8("date"));
        date->setGeometry(QRect(200, 630, 271, 41));
        label_date = new QLabel(doctorcase);
        label_date->setObjectName(QString::fromUtf8("label_date"));
        label_date->setGeometry(QRect(50, 630, 161, 31));
        label_date->setFont(font);
        department = new QLineEdit(doctorcase);
        department->setObjectName(QString::fromUtf8("department"));
        department->setGeometry(QRect(200, 700, 271, 41));
        label_department = new QLabel(doctorcase);
        label_department->setObjectName(QString::fromUtf8("label_department"));
        label_department->setGeometry(QRect(50, 690, 151, 41));
        label_department->setFont(font);
        symptoms = new QLineEdit(doctorcase);
        symptoms->setObjectName(QString::fromUtf8("symptoms"));
        symptoms->setGeometry(QRect(160, 770, 301, 131));
        label_symptoms = new QLabel(doctorcase);
        label_symptoms->setObjectName(QString::fromUtf8("label_symptoms"));
        label_symptoms->setGeometry(QRect(50, 800, 121, 51));
        label_symptoms->setFont(font);
        label_diagnosis = new QLabel(doctorcase);
        label_diagnosis->setObjectName(QString::fromUtf8("label_diagnosis"));
        label_diagnosis->setGeometry(QRect(60, 950, 111, 51));
        label_diagnosis->setFont(font);
        label_medicine = new QLabel(doctorcase);
        label_medicine->setObjectName(QString::fromUtf8("label_medicine"));
        label_medicine->setGeometry(QRect(20, 1080, 131, 51));
        label_medicine->setFont(font);
        diagnosis = new QLineEdit(doctorcase);
        diagnosis->setObjectName(QString::fromUtf8("diagnosis"));
        diagnosis->setGeometry(QRect(160, 920, 301, 121));
        medicine = new QLineEdit(doctorcase);
        medicine->setObjectName(QString::fromUtf8("medicine"));
        medicine->setGeometry(QRect(160, 1070, 301, 111));
        doctorcase_return = new QPushButton(doctorcase);
        doctorcase_return->setObjectName(QString::fromUtf8("doctorcase_return"));
        doctorcase_return->setGeometry(QRect(410, 1210, 91, 41));
        doctorcase_sure = new QPushButton(doctorcase);
        doctorcase_sure->setObjectName(QString::fromUtf8("doctorcase_sure"));
        doctorcase_sure->setGeometry(QRect(120, 1210, 91, 41));
        doctorcase_sure_2 = new QPushButton(doctorcase);
        doctorcase_sure_2->setObjectName(QString::fromUtf8("doctorcase_sure_2"));
        doctorcase_sure_2->setGeometry(QRect(250, 370, 111, 41));

        retranslateUi(doctorcase);

        QMetaObject::connectSlotsByName(doctorcase);
    } // setupUi

    void retranslateUi(QWidget *doctorcase)
    {
        doctorcase->setWindowTitle(QApplication::translate("doctorcase", "Form", nullptr));
        label_seecase->setText(QApplication::translate("doctorcase", "\346\202\250\350\277\230\346\234\252\350\257\212\346\226\255\347\232\204\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        label_addcase->setText(QApplication::translate("doctorcase", "\350\257\212\346\226\255\344\270\212\350\241\250\344\270\255\347\232\204\344\277\241\346\201\257", nullptr));
        label_patient_username->setText(QApplication::translate("doctorcase", "\347\227\205\344\272\272\347\224\250\346\210\267\345\220\215", nullptr));
        label_doctor_username->setText(QApplication::translate("doctorcase", "\345\214\273\347\224\237\347\224\250\346\210\267\345\220\215", nullptr));
        label_date->setText(QApplication::translate("doctorcase", "\345\260\261\350\257\212\346\227\266\351\227\264", nullptr));
        label_department->setText(QApplication::translate("doctorcase", "\345\260\261\350\257\212\347\247\221\345\256\244", nullptr));
        label_symptoms->setText(QApplication::translate("doctorcase", "\347\227\207\347\212\266", nullptr));
        label_diagnosis->setText(QApplication::translate("doctorcase", "\345\214\273\345\230\261", nullptr));
        label_medicine->setText(QApplication::translate("doctorcase", "\345\244\204\346\226\271\345\217\212\347\274\264\350\264\271", nullptr));
        doctorcase_return->setText(QApplication::translate("doctorcase", "\350\277\224\345\233\236", nullptr));
        doctorcase_sure->setText(QApplication::translate("doctorcase", "\347\241\256\345\256\232", nullptr));
        doctorcase_sure_2->setText(QApplication::translate("doctorcase", "\346\237\245\347\234\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class doctorcase: public Ui_doctorcase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORCASE_H
