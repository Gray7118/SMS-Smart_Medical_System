/********************************************************************************
** Form generated from reading UI file 'schedulechoose.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULECHOOSE_H
#define UI_SCHEDULECHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_schedulechoose
{
public:
    QPushButton *schedule_sure;
    QPushButton *schedule_return;
    QTextEdit *schedit;

    void setupUi(QWidget *schedulechoose)
    {
        if (schedulechoose->objectName().isEmpty())
            schedulechoose->setObjectName(QString::fromUtf8("schedulechoose"));
        schedulechoose->resize(656, 538);
        schedule_sure = new QPushButton(schedulechoose);
        schedule_sure->setObjectName(QString::fromUtf8("schedule_sure"));
        schedule_sure->setGeometry(QRect(120, 420, 111, 61));
        schedule_return = new QPushButton(schedulechoose);
        schedule_return->setObjectName(QString::fromUtf8("schedule_return"));
        schedule_return->setGeometry(QRect(400, 420, 111, 61));
        schedit = new QTextEdit(schedulechoose);
        schedit->setObjectName(QString::fromUtf8("schedit"));
        schedit->setGeometry(QRect(50, 60, 521, 331));

        retranslateUi(schedulechoose);

        QMetaObject::connectSlotsByName(schedulechoose);
    } // setupUi

    void retranslateUi(QWidget *schedulechoose)
    {
        schedulechoose->setWindowTitle(QApplication::translate("schedulechoose", "Form", nullptr));
        schedule_sure->setText(QApplication::translate("schedulechoose", "\347\241\256\345\256\232\346\214\202\345\217\267", nullptr));
        schedule_return->setText(QApplication::translate("schedulechoose", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class schedulechoose: public Ui_schedulechoose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULECHOOSE_H
