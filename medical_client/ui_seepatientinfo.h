/********************************************************************************
** Form generated from reading UI file 'seepatientinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEEPATIENTINFO_H
#define UI_SEEPATIENTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_seepatientinfo
{
public:
    QTextEdit *mypatient_info;
    QPushButton *patientinfo_search;
    QPushButton *patientinfo_return;
    QLabel *label_seepatientinfo;

    void setupUi(QWidget *seepatientinfo)
    {
        if (seepatientinfo->objectName().isEmpty())
            seepatientinfo->setObjectName(QString::fromUtf8("seepatientinfo"));
        seepatientinfo->resize(645, 717);
        mypatient_info = new QTextEdit(seepatientinfo);
        mypatient_info->setObjectName(QString::fromUtf8("mypatient_info"));
        mypatient_info->setGeometry(QRect(20, 60, 601, 551));
        patientinfo_search = new QPushButton(seepatientinfo);
        patientinfo_search->setObjectName(QString::fromUtf8("patientinfo_search"));
        patientinfo_search->setGeometry(QRect(140, 630, 111, 51));
        patientinfo_return = new QPushButton(seepatientinfo);
        patientinfo_return->setObjectName(QString::fromUtf8("patientinfo_return"));
        patientinfo_return->setGeometry(QRect(410, 630, 111, 51));
        label_seepatientinfo = new QLabel(seepatientinfo);
        label_seepatientinfo->setObjectName(QString::fromUtf8("label_seepatientinfo"));
        label_seepatientinfo->setGeometry(QRect(160, 10, 441, 51));
        QFont font;
        font.setPointSize(15);
        label_seepatientinfo->setFont(font);

        retranslateUi(seepatientinfo);

        QMetaObject::connectSlotsByName(seepatientinfo);
    } // setupUi

    void retranslateUi(QWidget *seepatientinfo)
    {
        seepatientinfo->setWindowTitle(QApplication::translate("seepatientinfo", "Form", nullptr));
        patientinfo_search->setText(QApplication::translate("seepatientinfo", "\346\237\245\350\257\242", nullptr));
        patientinfo_return->setText(QApplication::translate("seepatientinfo", "\350\277\224\345\233\236", nullptr));
        label_seepatientinfo->setText(QApplication::translate("seepatientinfo", "\346\202\250\346\211\200\346\234\211\347\232\204\346\214\202\345\217\267\345\222\214\350\257\212\346\226\255\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class seepatientinfo: public Ui_seepatientinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEEPATIENTINFO_H
