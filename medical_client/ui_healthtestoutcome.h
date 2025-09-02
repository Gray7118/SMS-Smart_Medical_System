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
    QLabel *label_healthtestoutcome;
    QTextEdit *testoutcome_info;
    QPushButton *testoutcome;

    void setupUi(QWidget *healthtestoutcome)
    {
        if (healthtestoutcome->objectName().isEmpty())
            healthtestoutcome->setObjectName(QString::fromUtf8("healthtestoutcome"));
        healthtestoutcome->resize(638, 535);
        healthtestoutcome->setStyleSheet(QString::fromUtf8("\n"
"    QWidget#healthtestoutcome {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #e3f2fd,\n"
"            stop:1 #ffffff\n"
"        );\n"
"        font-family: \"Microsoft YaHei\";\n"
"    }\n"
"    QTextEdit#testoutcome_info {\n"
"        border: 2px solid #64b5f6;\n"
"        border-radius: 8px;\n"
"        background-color: #ffffff;\n"
"    }\n"
"    QPushButton {\n"
"        border-radius: 12px;\n"
"        border: 1px solid #64b5f6;\n"
"        color: #ffffff;\n"
"        font-weight: bold;\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #6ec6ff,\n"
"            stop:1 #1e88e5\n"
"        );\n"
"        padding: 8px 16px;\n"
"        min-width: 154px;\n"
"        min-height: 68px;\n"
"        font-size: 16px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #81d4fa,\n"
"           "
                        " stop:1 #1976d2\n"
"        );\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #1e88e5,\n"
"            stop:1 #1565c0\n"
"        );\n"
"    }\n"
"   "));
        label_healthtestoutcome = new QLabel(healthtestoutcome);
        label_healthtestoutcome->setObjectName(QString::fromUtf8("label_healthtestoutcome"));
        label_healthtestoutcome->setGeometry(QRect(190, 10, 241, 51));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label_healthtestoutcome->setFont(font);
        label_healthtestoutcome->setAlignment(Qt::AlignCenter);
        testoutcome_info = new QTextEdit(healthtestoutcome);
        testoutcome_info->setObjectName(QString::fromUtf8("testoutcome_info"));
        testoutcome_info->setGeometry(QRect(50, 70, 541, 371));
        testoutcome = new QPushButton(healthtestoutcome);
        testoutcome->setObjectName(QString::fromUtf8("testoutcome"));
        testoutcome->setGeometry(QRect(210, 460, 199, 51));
        testoutcome->setMinimumSize(QSize(199, 50));

        retranslateUi(healthtestoutcome);

        QMetaObject::connectSlotsByName(healthtestoutcome);
    } // setupUi

    void retranslateUi(QWidget *healthtestoutcome)
    {
        healthtestoutcome->setWindowTitle(QApplication::translate("healthtestoutcome", "\345\201\245\345\272\267\346\265\213\350\257\225\347\273\223\346\236\234", nullptr));
        label_healthtestoutcome->setText(QApplication::translate("healthtestoutcome", "\345\201\245\345\272\267\346\265\213\350\257\225\347\273\223\346\236\234", nullptr));
        testoutcome->setText(QApplication::translate("healthtestoutcome", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class healthtestoutcome: public Ui_healthtestoutcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEALTHTESTOUTCOME_H
