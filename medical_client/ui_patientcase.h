/********************************************************************************
** Form generated from reading UI file 'patientcase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTCASE_H
#define UI_PATIENTCASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_patientcase
{
public:
    QTextEdit *seecase;
    QPushButton *patientcase_sure;
    QLabel *label_seecase;
    QPushButton *patientcase_return;

    void setupUi(QWidget *patientcase)
    {
        if (patientcase->objectName().isEmpty())
            patientcase->setObjectName(QString::fromUtf8("patientcase"));
        patientcase->resize(641, 537);
        patientcase->setStyleSheet(QString::fromUtf8("\n"
"    QWidget#patientcase {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #e3f2fd,\n"
"            stop:1 #ffffff\n"
"        );\n"
"        font-family: \"Microsoft YaHei\";\n"
"    }\n"
"    QTextEdit#seecase {\n"
"        border: 2px solid #64b5f6;\n"
"        border-radius: 8px;\n"
"        background-color: #ffffff;\n"
"    }\n"
"    /* \346\231\256\351\200\232\350\223\235\350\211\262\346\214\211\351\222\256\346\240\267\345\274\217 */\n"
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
"        min-width: 120px;\n"
"        min-height: 50px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: qlineargradient(\n"
"            x1:0"
                        ", y1:0, x2:0, y2:1,\n"
"            stop:0 #81d4fa,\n"
"            stop:1 #1976d2\n"
"        );\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #1e88e5,\n"
"            stop:1 #1565c0\n"
"        );\n"
"    }\n"
"    /* \350\277\224\345\233\236\346\214\211\351\222\256\345\215\225\347\213\254\346\240\267\345\274\217\357\274\210\347\272\242\350\211\262\346\270\220\345\217\230\357\274\211 */\n"
"    #patientcase_return {\n"
"        border-radius: 14px;\n"
"        border: 1px solid #e74c3c;\n"
"        color: #ffffff;\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #ff7f7f,\n"
"            stop:1 #e53935\n"
"        );\n"
"    }\n"
"    #patientcase_return:hover {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #ff8a80,\n"
"            stop:1 #f44336\n"
"        );\n"
"    }\n"
"    #pati"
                        "entcase_return:pressed {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #e53935,\n"
"            stop:1 #c62828\n"
"        );\n"
"    }\n"
"   "));
        seecase = new QTextEdit(patientcase);
        seecase->setObjectName(QString::fromUtf8("seecase"));
        seecase->setGeometry(QRect(50, 70, 541, 331));
        seecase->setReadOnly(true);
        patientcase_sure = new QPushButton(patientcase);
        patientcase_sure->setObjectName(QString::fromUtf8("patientcase_sure"));
        patientcase_sure->setGeometry(QRect(110, 420, 154, 68));
        label_seecase = new QLabel(patientcase);
        label_seecase->setObjectName(QString::fromUtf8("label_seecase"));
        label_seecase->setGeometry(QRect(230, 10, 181, 51));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_seecase->setFont(font);
        patientcase_return = new QPushButton(patientcase);
        patientcase_return->setObjectName(QString::fromUtf8("patientcase_return"));
        patientcase_return->setGeometry(QRect(380, 420, 154, 68));

        retranslateUi(patientcase);

        QMetaObject::connectSlotsByName(patientcase);
    } // setupUi

    void retranslateUi(QWidget *patientcase)
    {
        patientcase->setWindowTitle(QApplication::translate("patientcase", "\347\227\205\345\216\206\346\237\245\347\234\213", nullptr));
        patientcase_sure->setText(QApplication::translate("patientcase", "\347\241\256\345\256\232", nullptr));
        label_seecase->setText(QApplication::translate("patientcase", "\347\227\205\345\216\206\344\270\216\345\244\204\346\226\271", nullptr));
        patientcase_return->setText(QApplication::translate("patientcase", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class patientcase: public Ui_patientcase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTCASE_H
