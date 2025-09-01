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
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label2_2;
    QLabel *label2_3;
    QLabel *label2_6;
    QLabel *label2_7;
    QLabel *label2_8;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label2;
    QLineEdit *lineEdit2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 600);
        MainWindow->setMinimumSize(QSize(1200, 600));
        MainWindow->setMaximumSize(QSize(1200, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(810, 150, 91, 31));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(910, 150, 256, 201));
        pushButton2 = new QPushButton(centralwidget);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));
        pushButton2->setGeometry(QRect(810, 390, 91, 31));
        textBrowser2 = new QTextBrowser(centralwidget);
        textBrowser2->setObjectName(QString::fromUtf8("textBrowser2"));
        textBrowser2->setGeometry(QRect(910, 390, 256, 121));
        pushButton3 = new QPushButton(centralwidget);
        pushButton3->setObjectName(QString::fromUtf8("pushButton3"));
        pushButton3->setGeometry(QRect(840, 530, 151, 41));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(810, 39, 304, 31));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setContextMenuPolicy(Qt::DefaultContextMenu);

        horizontalLayout_2->addWidget(lineEdit);

        label2_2 = new QLabel(centralwidget);
        label2_2->setObjectName(QString::fromUtf8("label2_2"));
        label2_2->setGeometry(QRect(820, 180, 71, 41));
        label2_3 = new QLabel(centralwidget);
        label2_3->setObjectName(QString::fromUtf8("label2_3"));
        label2_3->setGeometry(QRect(830, 210, 61, 21));
        label2_6 = new QLabel(centralwidget);
        label2_6->setObjectName(QString::fromUtf8("label2_6"));
        label2_6->setGeometry(QRect(840, 450, 61, 21));
        label2_7 = new QLabel(centralwidget);
        label2_7->setObjectName(QString::fromUtf8("label2_7"));
        label2_7->setGeometry(QRect(820, 420, 71, 41));
        label2_8 = new QLabel(centralwidget);
        label2_8->setObjectName(QString::fromUtf8("label2_8"));
        label2_8->setGeometry(QRect(1000, 540, 161, 21));
        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(810, 90, 295, 31));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label2 = new QLabel(widget1);
        label2->setObjectName(QString::fromUtf8("label2"));

        horizontalLayout->addWidget(label2);

        lineEdit2 = new QLineEdit(widget1);
        lineEdit2->setObjectName(QString::fromUtf8("lineEdit2"));

        horizontalLayout->addWidget(lineEdit2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 32));
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
        label2_2->setText(QApplication::translate("MainWindow", "Optional  ", nullptr));
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
