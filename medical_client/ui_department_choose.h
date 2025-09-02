/********************************************************************************
** Form generated from reading UI file 'department_choose.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENT_CHOOSE_H
#define UI_DEPARTMENT_CHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_department_choose
{
public:
    QLabel *label_d_choose;
    QComboBox *combo_d_choose;
    QPushButton *department_choose_return;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *department_choose_sure;
    QPushButton *department_choose_sure_2;

    void setupUi(QWidget *department_choose)
    {
        if (department_choose->objectName().isEmpty())
            department_choose->setObjectName(QString::fromUtf8("department_choose"));
        department_choose->resize(630, 484);
        department_choose->setStyleSheet(QString::fromUtf8("\n"
"    QWidget#department_choose {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #e3f2fd,\n"
"            stop:1 #ffffff\n"
"        );\n"
"        font-family: \"Microsoft YaHei\";\n"
"    }\n"
"    QLabel {\n"
"        color: #000000;\n"
"        font-weight: bold;\n"
"    }\n"
"    QComboBox {\n"
"        border: 2px solid #64b5f6;\n"
"        border-radius: 8px;\n"
"        padding: 8px 30px 8px 10px;\n"
"        background-color: #ffffff;\n"
"        font-weight: bold;\n"
"        min-height: 50px;\n"
"        color: #333333;\n"
"    }\n"
"    QComboBox:focus {\n"
"        border: 2px solid #1e88e5;\n"
"    }\n"
"    /* \344\270\213\346\213\211\347\256\255\345\244\264\351\203\250\345\210\206 */\n"
"    QComboBox::drop-down {\n"
"        subcontrol-origin: padding;\n"
"        subcontrol-position: top right;\n"
"        width: 30px;\n"
"        border-left: none;\n"
"        background: transparent;\n"
"    }\n"
"\n"
"    /* \344\275\277\347"
                        "\224\250\344\270\211\350\247\222\345\275\242\347\273\230\345\210\266\347\256\255\345\244\264\357\274\214\351\242\234\350\211\262\344\270\216\346\214\211\351\222\256\346\270\220\345\217\230\347\233\270\350\277\221 */\n"
"    QComboBox::down-arrow {\n"
"        width: 12px;\n"
"        height: 12px;\n"
"        border-left: 6px solid transparent;\n"
"        border-right: 6px solid transparent;\n"
"        border-top: 8px solid #1e88e5; /* \350\223\235\350\211\262\357\274\214\345\222\214\346\214\211\351\222\256\345\272\225\350\211\262\344\270\200\350\207\264 */\n"
"    }\n"
"\n"
"    /* \346\214\211\344\270\213\346\227\266\347\256\255\345\244\264\351\242\234\350\211\262\345\212\240\346\267\261 */\n"
"    QComboBox::down-arrow:on {\n"
"        border-top-color: #1565c0; /* \346\214\211\351\222\256\346\214\211\344\270\213\346\270\220\345\217\230\347\232\204\345\272\225\350\211\262 */\n"
"    }\n"
"    QComboBox QAbstractItemView {\n"
"        border: 2px solid #64b5f6;\n"
"        border-radius: 6px;\n"
"        b"
                        "ackground-color: #ffffff;\n"
"        selection-background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #6ec6ff,\n"
"            stop:1 #1e88e5\n"
"        );\n"
"        selection-color: white;\n"
"        outline: none;\n"
"        padding: 5px;\n"
"        font-weight: bold;\n"
"    }\n"
"    QComboBox QAbstractItemView::item {\n"
"        height: 40px;\n"
"        padding-left: 10px;\n"
"    }\n"
"    QComboBox QAbstractItemView::item:hover {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #81d4fa,\n"
"            stop:1 #1976d2\n"
"        );\n"
"        color: white;\n"
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
"        m"
                        "in-width: 154px;\n"
"        min-height: 68px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
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
"    #department_choose_return {\n"
"        border-radius: 14px;\n"
"        border: 1px solid #e74c3c;\n"
"        color: #ffffff;\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #ff7f7f,\n"
"            stop:1 #e53935\n"
"        );\n"
"    }\n"
"    #department_choose_return:hover {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #ff8a80,\n"
"            stop:1 #f44336\n"
"        );\n"
"    }\n"
"    #department_choose_retur"
                        "n:pressed {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #e53935,\n"
"            stop:1 #c62828\n"
"        );\n"
"    }\n"
"   "));
        label_d_choose = new QLabel(department_choose);
        label_d_choose->setObjectName(QString::fromUtf8("label_d_choose"));
        label_d_choose->setGeometry(QRect(215, 40, 200, 50));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_d_choose->setFont(font);
        label_d_choose->setAlignment(Qt::AlignCenter);
        combo_d_choose = new QComboBox(department_choose);
        combo_d_choose->setObjectName(QString::fromUtf8("combo_d_choose"));
        combo_d_choose->setGeometry(QRect(185, 120, 261, 81));
        department_choose_return = new QPushButton(department_choose);
        department_choose_return->setObjectName(QString::fromUtf8("department_choose_return"));
        department_choose_return->setGeometry(QRect(180, 380, 261, 70));
        layoutWidget = new QWidget(department_choose);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 300, 481, 72));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        department_choose_sure = new QPushButton(layoutWidget);
        department_choose_sure->setObjectName(QString::fromUtf8("department_choose_sure"));

        horizontalLayout->addWidget(department_choose_sure);

        department_choose_sure_2 = new QPushButton(layoutWidget);
        department_choose_sure_2->setObjectName(QString::fromUtf8("department_choose_sure_2"));

        horizontalLayout->addWidget(department_choose_sure_2);


        retranslateUi(department_choose);

        QMetaObject::connectSlotsByName(department_choose);
    } // setupUi

    void retranslateUi(QWidget *department_choose)
    {
        department_choose->setWindowTitle(QApplication::translate("department_choose", "\351\200\211\346\213\251\347\247\221\345\256\244", nullptr));
        label_d_choose->setText(QApplication::translate("department_choose", "\351\200\211\346\213\251\347\247\221\345\256\244", nullptr));
        department_choose_return->setText(QApplication::translate("department_choose", "\350\277\224\345\233\236", nullptr));
        department_choose_sure->setText(QApplication::translate("department_choose", "\346\214\211\346\216\222\347\217\255\346\227\266\351\227\264\346\243\200\347\264\242", nullptr));
        department_choose_sure_2->setText(QApplication::translate("department_choose", "\346\214\211\345\214\273\347\224\237\346\243\200\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class department_choose: public Ui_department_choose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENT_CHOOSE_H
