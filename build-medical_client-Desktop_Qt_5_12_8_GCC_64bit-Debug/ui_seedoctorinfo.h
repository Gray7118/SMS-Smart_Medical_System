/********************************************************************************
** Form generated from reading UI file 'seedoctorinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEEDOCTORINFO_H
#define UI_SEEDOCTORINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_seedoctorinfo
{
public:
    QLabel *label_seedoctorinfo;
    QPushButton *doctorinfo_return;
    QTextEdit *mydoctor_info;
    QPushButton *doctorinfo_search;

    void setupUi(QWidget *seedoctorinfo)
    {
        if (seedoctorinfo->objectName().isEmpty())
            seedoctorinfo->setObjectName(QString::fromUtf8("seedoctorinfo"));
        seedoctorinfo->resize(655, 547);
        label_seedoctorinfo = new QLabel(seedoctorinfo);
        label_seedoctorinfo->setObjectName(QString::fromUtf8("label_seedoctorinfo"));
        label_seedoctorinfo->setGeometry(QRect(270, 30, 201, 51));
        QFont font;
        font.setPointSize(15);
        label_seedoctorinfo->setFont(font);
        doctorinfo_return = new QPushButton(seedoctorinfo);
        doctorinfo_return->setObjectName(QString::fromUtf8("doctorinfo_return"));
        doctorinfo_return->setGeometry(QRect(420, 440, 141, 61));
        mydoctor_info = new QTextEdit(seedoctorinfo);
        mydoctor_info->setObjectName(QString::fromUtf8("mydoctor_info"));
        mydoctor_info->setGeometry(QRect(40, 100, 541, 311));
        doctorinfo_search = new QPushButton(seedoctorinfo);
        doctorinfo_search->setObjectName(QString::fromUtf8("doctorinfo_search"));
        doctorinfo_search->setGeometry(QRect(100, 440, 131, 61));

        retranslateUi(seedoctorinfo);

        QMetaObject::connectSlotsByName(seedoctorinfo);
    } // setupUi

    void retranslateUi(QWidget *seedoctorinfo)
    {
        seedoctorinfo->setWindowTitle(QApplication::translate("seedoctorinfo", "Form", nullptr));
        label_seedoctorinfo->setText(QApplication::translate("seedoctorinfo", "\345\214\273\347\224\237\344\277\241\346\201\257", nullptr));
        doctorinfo_return->setText(QApplication::translate("seedoctorinfo", "\350\277\224\345\233\236", nullptr));
        doctorinfo_search->setText(QApplication::translate("seedoctorinfo", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class seedoctorinfo: public Ui_seedoctorinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEEDOCTORINFO_H
