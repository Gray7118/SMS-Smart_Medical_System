/********************************************************************************
** Form generated from reading UI file 'healthtestoutcome.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEALTHTESTOUTCOME_H
#define UI_HEALTHTESTOUTCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_healthtestoutcome
{
public:
    QTextEdit *testoutcome_info;
    QLabel *label_healthtestoutcome;
    QPushButton *testoutcome;

    void setupUi(QWidget *healthtestoutcome)
    {
        if (healthtestoutcome->objectName().isEmpty())
            healthtestoutcome->setObjectName(QString::fromUtf8("healthtestoutcome"));
        healthtestoutcome->resize(638, 535);
        testoutcome_info = new QTextEdit(healthtestoutcome);
        testoutcome_info->setObjectName(QString::fromUtf8("testoutcome_info"));
        testoutcome_info->setGeometry(QRect(50, 70, 541, 371));
        label_healthtestoutcome = new QLabel(healthtestoutcome);
        label_healthtestoutcome->setObjectName(QString::fromUtf8("label_healthtestoutcome"));
        label_healthtestoutcome->setGeometry(QRect(270, 10, 191, 51));
        QFont font;
        font.setPointSize(15);
        label_healthtestoutcome->setFont(font);
        testoutcome = new QPushButton(healthtestoutcome);
        testoutcome->setObjectName(QString::fromUtf8("testoutcome"));
        testoutcome->setGeometry(QRect(280, 460, 121, 51));

        retranslateUi(healthtestoutcome);

        QMetaObject::connectSlotsByName(healthtestoutcome);
    } // setupUi

    void retranslateUi(QWidget *healthtestoutcome)
    {
        healthtestoutcome->setWindowTitle(QApplication::translate("healthtestoutcome", "Form", nullptr));
        label_healthtestoutcome->setText(QApplication::translate("healthtestoutcome", "\345\201\245\345\272\267\346\265\213\350\257\225\347\273\223\346\236\234", nullptr));
        testoutcome->setText(QApplication::translate("healthtestoutcome", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class healthtestoutcome: public Ui_healthtestoutcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEALTHTESTOUTCOME_H
