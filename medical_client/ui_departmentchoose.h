/********************************************************************************
** Form generated from reading UI file 'departmentchoose.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENTCHOOSE_H
#define UI_DEPARTMENTCHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_departmentchoose
{
public:
    QLabel *schedule_info;
    QPushButton *depcho_return;
    QTextEdit *depedit;
    QPushButton *depcho_sure;

    void setupUi(QWidget *departmentchoose)
    {
        if (departmentchoose->objectName().isEmpty())
            departmentchoose->setObjectName(QString::fromUtf8("departmentchoose"));
        departmentchoose->resize(626, 506);
        schedule_info = new QLabel(departmentchoose);
        schedule_info->setObjectName(QString::fromUtf8("schedule_info"));
        schedule_info->setGeometry(QRect(250, 30, 151, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        schedule_info->setFont(font);
        depcho_return = new QPushButton(departmentchoose);
        depcho_return->setObjectName(QString::fromUtf8("depcho_return"));
        depcho_return->setGeometry(QRect(410, 390, 131, 71));
        depedit = new QTextEdit(departmentchoose);
        depedit->setObjectName(QString::fromUtf8("depedit"));
        depedit->setGeometry(QRect(90, 100, 451, 271));
        depcho_sure = new QPushButton(departmentchoose);
        depcho_sure->setObjectName(QString::fromUtf8("depcho_sure"));
        depcho_sure->setGeometry(QRect(70, 390, 231, 71));

        retranslateUi(departmentchoose);

        QMetaObject::connectSlotsByName(departmentchoose);
    } // setupUi

    void retranslateUi(QWidget *departmentchoose)
    {
        departmentchoose->setWindowTitle(QApplication::translate("departmentchoose", "Form", nullptr));
        schedule_info->setText(QApplication::translate("departmentchoose", "\346\216\222\347\217\255\344\277\241\346\201\257", nullptr));
        depcho_return->setText(QApplication::translate("departmentchoose", "\350\277\224\345\233\236", nullptr));
        depcho_sure->setText(QApplication::translate("departmentchoose", "\347\241\256\345\256\232\346\214\202\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class departmentchoose: public Ui_departmentchoose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENTCHOOSE_H
