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
    QLabel *label;
    QComboBox *choose_schedule;
    QLabel *label_2;
    QLineEdit *inputdocname;
    QTextEdit *see_schedule;
    QPushButton *surebutton;
    QPushButton *returnbutton;

    void setupUi(QWidget *schedule_choose)
    {
        if (schedule_choose->objectName().isEmpty())
            schedule_choose->setObjectName(QString::fromUtf8("schedule_choose"));
        schedule_choose->resize(751, 570);
        schedule_choose->setStyleSheet(QString::fromUtf8("\n"
"QWidget#schedule_choose {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #e3f2fd,\n"
"        stop:1 #ffffff\n"
"    );\n"
"    font-family: \"Microsoft YaHei\";\n"
"}\n"
"QLabel {\n"
"    color: #000000;\n"
"    font-weight: bold;\n"
"}\n"
"QComboBox {\n"
"    border: 2px solid #64b5f6;\n"
"    border-radius: 8px;\n"
"    padding: 8px 30px 8px 10px;\n"
"    background-color: #ffffff;\n"
"    font-weight: bold;\n"
"    min-height: 50px;\n"
"    color: #333333;\n"
"}\n"
"QComboBox:focus {\n"
"    border: 2px solid #1e88e5;\n"
"}\n"
"QComboBox::drop-down { subcontrol-origin: padding; subcontrol-position: top right; width: 30px; border-left: none; background: transparent; }\n"
"QComboBox::down-arrow { width:12px; height:12px; border-left:6px solid transparent; border-right:6px solid transparent; border-top:8px solid #1e88e5; }\n"
"QComboBox::down-arrow:on { border-top-color: #1565c0; }\n"
"QComboBox QAbstractItemView {\n"
"    border: 2px solid #64b5f6;\n"
""
                        "    border-radius: 6px;\n"
"    background-color: #ffffff;\n"
"    selection-background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #6ec6ff, stop:1 #1e88e5);\n"
"    selection-color: white;\n"
"    outline: none;\n"
"    padding: 5px;\n"
"    font-weight: bold;\n"
"}\n"
"QComboBox QAbstractItemView::item { height: 40px; padding-left: 10px; }\n"
"QComboBox QAbstractItemView::item:hover { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #81d4fa, stop:1 #1976d2); color: white; }\n"
"QLineEdit {\n"
"    border: 2px solid #64b5f6;\n"
"    border-radius: 8px;\n"
"    padding: 8px;\n"
"    background-color: #ffffff;\n"
"    font-weight: bold;\n"
"    min-height: 50px;\n"
"}\n"
"QLineEdit:focus { border: 2px solid #1e88e5; }\n"
"QTextEdit {\n"
"    border: 2px solid #64b5f6;\n"
"    border-radius: 8px;\n"
"    background-color: #ffffff;\n"
"    font-weight: bold;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton {\n"
"    border-radius: 12px;\n"
"    border: 1px solid #64b5f6;\n"
"    color: #fffff"
                        "f;\n"
"    font-weight: bold;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #6ec6ff, stop:1 #1e88e5);\n"
"    min-width: 154px;\n"
"    min-height: 68px;\n"
"}\n"
"QPushButton:hover { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #81d4fa, stop:1 #1976d2); }\n"
"QPushButton:pressed { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1e88e5, stop:1 #1565c0); }\n"
"#returnbutton {\n"
"    border-radius: 14px;\n"
"    border: 1px solid #e74c3c;\n"
"    color: #ffffff;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #ff7f7f, stop:1 #e53935);\n"
"}\n"
"#returnbutton:hover { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #ff8a80, stop:1 #f44336); }\n"
"#returnbutton:pressed { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #e53935, stop:1 #c62828); }\n"
"   "));
        label = new QLabel(schedule_choose);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 181, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        choose_schedule = new QComboBox(schedule_choose);
        choose_schedule->setObjectName(QString::fromUtf8("choose_schedule"));
        choose_schedule->setGeometry(QRect(40, 80, 201, 70));
        label_2 = new QLabel(schedule_choose);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 190, 191, 71));
        label_2->setFont(font);
        inputdocname = new QLineEdit(schedule_choose);
        inputdocname->setObjectName(QString::fromUtf8("inputdocname"));
        inputdocname->setGeometry(QRect(40, 260, 201, 70));
        see_schedule = new QTextEdit(schedule_choose);
        see_schedule->setObjectName(QString::fromUtf8("see_schedule"));
        see_schedule->setGeometry(QRect(280, 30, 441, 361));
        see_schedule->setReadOnly(true);
        surebutton = new QPushButton(schedule_choose);
        surebutton->setObjectName(QString::fromUtf8("surebutton"));
        surebutton->setGeometry(QRect(110, 420, 161, 70));
        returnbutton = new QPushButton(schedule_choose);
        returnbutton->setObjectName(QString::fromUtf8("returnbutton"));
        returnbutton->setGeometry(QRect(440, 420, 161, 70));

        retranslateUi(schedule_choose);

        QMetaObject::connectSlotsByName(schedule_choose);
    } // setupUi

    void retranslateUi(QWidget *schedule_choose)
    {
        schedule_choose->setWindowTitle(QApplication::translate("schedule_choose", "\351\242\204\347\272\246\346\227\266\351\227\264\351\200\211\346\213\251", nullptr));
        label->setText(QApplication::translate("schedule_choose", "\350\257\267\351\200\211\346\213\251\351\242\204\347\272\246\346\227\266\351\227\264", nullptr));
        label_2->setText(QApplication::translate("schedule_choose", "\350\257\267\350\276\223\345\205\245\345\214\273\347\224\237\345\247\223\345\220\215", nullptr));
        surebutton->setText(QApplication::translate("schedule_choose", "\347\241\256\350\256\244\346\214\202\345\217\267", nullptr));
        returnbutton->setText(QApplication::translate("schedule_choose", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class schedule_choose: public Ui_schedule_choose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULE_CHOOSE_H
