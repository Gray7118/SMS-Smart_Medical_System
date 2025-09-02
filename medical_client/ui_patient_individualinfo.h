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
    QLabel *gender_label;
    QLineEdit *gender;
    QLabel *age_label;
    QLineEdit *age;
    QLabel *phone_label;
    QLineEdit *phonenumber;
    QPushButton *patient_info_sure;
    QPushButton *patient_info_return;

    void setupUi(QWidget *patient_individualinfo)
    {
        if (patient_individualinfo->objectName().isEmpty())
            patient_individualinfo->setObjectName(QString::fromUtf8("patient_individualinfo"));
        patient_individualinfo->resize(650, 550);
        patient_individualinfo->setStyleSheet(QString::fromUtf8("\n"
"    QWidget#patient_individualinfo {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #e3f2fd,\n"
"            stop:1 #ffffff\n"
"        );\n"
"        font-family: \"Microsoft YaHei\";\n"
"    }\n"
"    QLineEdit {\n"
"        border: 2px solid #64b5f6;\n"
"        border-radius: 8px;\n"
"        background-color: #ffffff;\n"
"        padding-left: 8px;\n"
"        font-size: 12pt;\n"
"    }\n"
"    /* \347\241\256\345\256\232\346\214\211\351\222\256\350\223\235\350\211\262\346\270\220\345\217\230 */\n"
"    #patient_info_sure {\n"
"        border-radius: 14px;\n"
"        border: 1px solid #64b5f6;\n"
"        color: #ffffff;\n"
"        font-weight: bold;\n"
"        font-size: 16pt;\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #6ec6ff,\n"
"            stop:1 #1e88e5\n"
"        );\n"
"        min-width: 154px;\n"
"        min-height: 68px;\n"
"    }\n"
"    #patient_info_sure:"
                        "hover {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #81d4fa,\n"
"            stop:1 #1976d2\n"
"        );\n"
"    }\n"
"    #patient_info_sure:pressed {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #1e88e5,\n"
"            stop:1 #1565c0\n"
"        );\n"
"    }\n"
"    /* \350\277\224\345\233\236\346\214\211\351\222\256\347\272\242\350\211\262\346\270\220\345\217\230 */\n"
"    #patient_info_return {\n"
"        border-radius: 14px;\n"
"        border: 1px solid #e74c3c;\n"
"        color: #ffffff;\n"
"        font-weight: bold;\n"
"        font-size: 16pt;\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #ff7f7f,\n"
"            stop:1 #e53935\n"
"        );\n"
"    }\n"
"    #patient_info_return:hover {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #ff8a8"
                        "0,\n"
"            stop:1 #f44336\n"
"        );\n"
"    }\n"
"    #patient_info_return:pressed {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #e53935,\n"
"            stop:1 #c62828\n"
"        );\n"
"    }\n"
"   "));
        info_change = new QLabel(patient_individualinfo);
        info_change->setObjectName(QString::fromUtf8("info_change"));
        info_change->setGeometry(QRect(210, 20, 230, 51));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        info_change->setFont(font);
        info_change->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        gender_label = new QLabel(patient_individualinfo);
        gender_label->setObjectName(QString::fromUtf8("gender_label"));
        gender_label->setGeometry(QRect(100, 120, 80, 40));
        QFont font1;
        font1.setPointSize(14);
        gender_label->setFont(font1);
        gender = new QLineEdit(patient_individualinfo);
        gender->setObjectName(QString::fromUtf8("gender"));
        gender->setGeometry(QRect(200, 115, 260, 45));
        QFont font2;
        font2.setPointSize(12);
        gender->setFont(font2);
        age_label = new QLabel(patient_individualinfo);
        age_label->setObjectName(QString::fromUtf8("age_label"));
        age_label->setGeometry(QRect(100, 200, 80, 40));
        age_label->setFont(font1);
        age = new QLineEdit(patient_individualinfo);
        age->setObjectName(QString::fromUtf8("age"));
        age->setGeometry(QRect(200, 195, 260, 45));
        age->setFont(font2);
        phone_label = new QLabel(patient_individualinfo);
        phone_label->setObjectName(QString::fromUtf8("phone_label"));
        phone_label->setGeometry(QRect(100, 280, 80, 40));
        phone_label->setFont(font1);
        phonenumber = new QLineEdit(patient_individualinfo);
        phonenumber->setObjectName(QString::fromUtf8("phonenumber"));
        phonenumber->setGeometry(QRect(200, 275, 260, 45));
        phonenumber->setFont(font2);
        patient_info_sure = new QPushButton(patient_individualinfo);
        patient_info_sure->setObjectName(QString::fromUtf8("patient_info_sure"));
        patient_info_sure->setGeometry(QRect(110, 380, 154, 68));
        patient_info_return = new QPushButton(patient_individualinfo);
        patient_info_return->setObjectName(QString::fromUtf8("patient_info_return"));
        patient_info_return->setGeometry(QRect(380, 380, 154, 68));

        retranslateUi(patient_individualinfo);

        QMetaObject::connectSlotsByName(patient_individualinfo);
    } // setupUi

    void retranslateUi(QWidget *patient_individualinfo)
    {
        patient_individualinfo->setWindowTitle(QApplication::translate("patient_individualinfo", "\346\202\243\350\200\205\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        info_change->setText(QApplication::translate("patient_individualinfo", "\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        gender_label->setText(QApplication::translate("patient_individualinfo", "\346\200\247\345\210\253", nullptr));
        age_label->setText(QApplication::translate("patient_individualinfo", "\345\271\264\351\276\204", nullptr));
        phone_label->setText(QApplication::translate("patient_individualinfo", "\347\224\265\350\257\235", nullptr));
        patient_info_sure->setText(QApplication::translate("patient_individualinfo", "\347\241\256\345\256\232", nullptr));
        patient_info_return->setText(QApplication::translate("patient_individualinfo", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class patient_individualinfo: public Ui_patient_individualinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENT_INDIVIDUALINFO_H
