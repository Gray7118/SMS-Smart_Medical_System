/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QPushButton *pushButton2;
    QTextBrowser *textBrowser2;
    QPushButton *pushButton3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label2_2;
    QLabel *label2_3;
    QLabel *label2_6;
    QLabel *label2_7;
    QLabel *label2_8;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label2;
    QLineEdit *lineEdit2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1243, 600);
        MainWindow->setMinimumSize(QSize(1200, 600));
        MainWindow->setMaximumSize(QSize(4000, 700));
        MainWindow->setStyleSheet(QString::fromUtf8(" /* \346\214\211\351\222\256\351\253\230\347\272\247\346\270\220\345\217\230\347\247\221\346\212\200\351\243\216 */ QPushButton { border-radius: 14px; border: 1px solid #64b5f6; color: #ffffff; font-weight: bold; font-size: 16px; padding: 10px 20px; background-color: qlineargradient( x1:0, y1:0, x2:0, y2:1, stop:0 #6ec6ff, stop:1 #1e88e5 ); } QPushButton:hover { background-color: qlineargradient( x1:0, y1:0, x2:0, y2:1, stop:0 #81d4fa, stop:1 #1976d2 ); } QPushButton:pressed { background-color: qlineargradient( x1:0, y1:0, x2:0, y2:1, stop:0 #1e88e5, stop:1 #1565c0 ); } QPushButton { text-shadow: 1px 1px 2px rgba(0,0,0,0.2); } /* \350\276\223\345\205\245\346\241\206\346\240\267\345\274\217 */ QLineEdit { border: 2px solid #81d4fa; border-radius: 12px; padding: 10px; font-size: 14px; background-color: #ffffff; color: #0f1f38; selection-background-color: #4fc3f7; selection-color: #ffffff; } QLineEdit:focus { border: 2px solid #1e88e5; } /* \346\226\207\346\234\254\346\265\217\350\247\210\346\241\206 */ QTextBrow"
                        "ser { border: 2px solid #81d4fa; border-radius: 12px; padding: 8px; background-color: #ffffff; font-size: 14px; color: #0f1f38; } "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(810, 150, 131, 41));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(950, 150, 256, 201));
        pushButton2 = new QPushButton(centralwidget);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));
        pushButton2->setGeometry(QRect(810, 370, 131, 41));
        textBrowser2 = new QTextBrowser(centralwidget);
        textBrowser2->setObjectName(QString::fromUtf8("textBrowser2"));
        textBrowser2->setGeometry(QRect(950, 370, 256, 121));
        pushButton3 = new QPushButton(centralwidget);
        pushButton3->setObjectName(QString::fromUtf8("pushButton3"));
        pushButton3->setGeometry(QRect(840, 520, 151, 41));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(810, 39, 304, 46));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        label2_2 = new QLabel(centralwidget);
        label2_2->setObjectName(QString::fromUtf8("label2_2"));
        label2_2->setGeometry(QRect(810, 190, 71, 41));
        label2_3 = new QLabel(centralwidget);
        label2_3->setObjectName(QString::fromUtf8("label2_3"));
        label2_3->setGeometry(QRect(890, 200, 61, 21));
        label2_6 = new QLabel(centralwidget);
        label2_6->setObjectName(QString::fromUtf8("label2_6"));
        label2_6->setGeometry(QRect(890, 420, 61, 21));
        label2_7 = new QLabel(centralwidget);
        label2_7->setObjectName(QString::fromUtf8("label2_7"));
        label2_7->setGeometry(QRect(810, 410, 71, 41));
        label2_8 = new QLabel(centralwidget);
        label2_8->setObjectName(QString::fromUtf8("label2_8"));
        label2_8->setGeometry(QRect(1000, 530, 161, 21));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(810, 90, 295, 46));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label2 = new QLabel(layoutWidget1);
        label2->setObjectName(QString::fromUtf8("label2"));

        horizontalLayout->addWidget(label2);

        lineEdit2 = new QLineEdit(layoutWidget1);
        lineEdit2->setObjectName(QString::fromUtf8("lineEdit2"));

        horizontalLayout->addWidget(lineEdit2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1243, 32));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Guide", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\345\217\257\351\200\211\350\267\257\345\276\204", nullptr));
        pushButton2->setText(QApplication::translate("MainWindow", "\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
        pushButton3->setText(QApplication::translate("MainWindow", "\345\214\273\351\231\242\347\256\200\344\273\213", nullptr));
        label->setText(QApplication::translate("MainWindow", "\350\265\267\347\202\271(Start Point)", nullptr));
        label2_2->setText(QApplication::translate("MainWindow", "Optional ", nullptr));
        label2_3->setText(QApplication::translate("MainWindow", "Routes", nullptr));
        label2_6->setText(QApplication::translate("MainWindow", "Route", nullptr));
        label2_7->setText(QApplication::translate("MainWindow", "Shortest ", nullptr));
        label2_8->setText(QApplication::translate("MainWindow", "Hospital Overview", nullptr));
        label2->setText(QApplication::translate("MainWindow", "\347\273\210\347\202\271(End Point)  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
