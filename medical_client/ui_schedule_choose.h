/********************************************************************************
** Form generated from reading UI file 'schedule_choose.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULE_CHOOSE_H
#define UI_SCHEDULE_CHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_schedule_choose
{
public:
    QComboBox *choose_schedule;
    QLabel *label;
    QPushButton *returnbutton;
    QPushButton *surebutton;
    QTextEdit *see_schedule;
    QLabel *label_2;
    QLineEdit *inputdocname;

    void setupUi(QWidget *schedule_choose)
    {
        if (schedule_choose->objectName().isEmpty())
            schedule_choose->setObjectName(QString::fromUtf8("schedule_choose"));
        schedule_choose->resize(751, 570);
        choose_schedule = new QComboBox(schedule_choose);
        choose_schedule->setObjectName(QString::fromUtf8("choose_schedule"));
        choose_schedule->setGeometry(QRect(10, 80, 201, 61));
        label = new QLabel(schedule_choose);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 481, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        label->setFont(font);
        returnbutton = new QPushButton(schedule_choose);
        returnbutton->setObjectName(QString::fromUtf8("returnbutton"));
        returnbutton->setGeometry(QRect(440, 420, 161, 51));
        returnbutton->setFont(font);
        surebutton = new QPushButton(schedule_choose);
        surebutton->setObjectName(QString::fromUtf8("surebutton"));
        surebutton->setGeometry(QRect(110, 420, 161, 51));
        surebutton->setFont(font);
        see_schedule = new QTextEdit(schedule_choose);
        see_schedule->setObjectName(QString::fromUtf8("see_schedule"));
        see_schedule->setGeometry(QRect(300, 30, 421, 341));
        label_2 = new QLabel(schedule_choose);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 160, 371, 71));
        label_2->setFont(font);
        inputdocname = new QLineEdit(schedule_choose);
        inputdocname->setObjectName(QString::fromUtf8("inputdocname"));
        inputdocname->setGeometry(QRect(10, 220, 201, 51));

        retranslateUi(schedule_choose);

        QMetaObject::connectSlotsByName(schedule_choose);
    } // setupUi

    void retranslateUi(QWidget *schedule_choose)
    {
        schedule_choose->setWindowTitle(QApplication::translate("schedule_choose", "Form", nullptr));
        label->setText(QApplication::translate("schedule_choose", "\350\257\267\351\200\211\346\213\251\351\242\204\347\272\246\346\227\266\351\227\264", nullptr));
        returnbutton->setText(QApplication::translate("schedule_choose", "\350\277\224\345\233\236", nullptr));
        surebutton->setText(QApplication::translate("schedule_choose", "\347\241\256\350\256\244\346\214\202\345\217\267", nullptr));
        label_2->setText(QApplication::translate("schedule_choose", "\350\257\267\350\276\223\345\205\245\345\214\273\347\224\237\345\247\223\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class schedule_choose: public Ui_schedule_choose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULE_CHOOSE_H
