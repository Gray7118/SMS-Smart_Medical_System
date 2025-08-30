/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *loginButton;
    QPushButton *signupButton;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *quitButton;
    QLabel *tipLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *doctorRadioButton;
    QRadioButton *patientRadioButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(631, 525);
        loginButton = new QPushButton(Widget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(70, 350, 100, 50));
        loginButton->setMinimumSize(QSize(100, 50));
        loginButton->setMaximumSize(QSize(100, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        loginButton->setFont(font);
        signupButton = new QPushButton(Widget);
        signupButton->setObjectName(QString::fromUtf8("signupButton"));
        signupButton->setGeometry(QRect(240, 350, 100, 50));
        signupButton->setMinimumSize(QSize(100, 50));
        signupButton->setMaximumSize(QSize(100, 50));
        signupButton->setFont(font);
        usernameLineEdit = new QLineEdit(Widget);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));
        usernameLineEdit->setGeometry(QRect(110, 160, 191, 41));
        passwordLineEdit = new QLineEdit(Widget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(110, 240, 191, 41));
        quitButton = new QPushButton(Widget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(450, 420, 100, 50));
        quitButton->setMinimumSize(QSize(100, 50));
        quitButton->setMaximumSize(QSize(100, 50));
        quitButton->setFont(font);
        tipLabel = new QLabel(Widget);
        tipLabel->setObjectName(QString::fromUtf8("tipLabel"));
        tipLabel->setGeometry(QRect(390, 200, 181, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        tipLabel->setFont(font1);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(390, 240, 161, 64));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        doctorRadioButton = new QRadioButton(layoutWidget);
        doctorRadioButton->setObjectName(QString::fromUtf8("doctorRadioButton"));
        doctorRadioButton->setFont(font1);
        doctorRadioButton->setStyleSheet(QString::fromUtf8(""));
        doctorRadioButton->setChecked(true);

        verticalLayout->addWidget(doctorRadioButton);

        patientRadioButton = new QRadioButton(layoutWidget);
        patientRadioButton->setObjectName(QString::fromUtf8("patientRadioButton"));
        patientRadioButton->setFont(font1);
        patientRadioButton->setStyleSheet(QString::fromUtf8(""));
        patientRadioButton->setChecked(false);

        verticalLayout->addWidget(patientRadioButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        loginButton->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        signupButton->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        usernameLineEdit->setPlaceholderText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
        passwordLineEdit->setPlaceholderText(QApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        quitButton->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        tipLabel->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-weight:600;\">\351\200\211\346\213\251\347\224\250\346\210\267\347\261\273\345\236\213\357\274\232</span></p></body></html>", nullptr));
        doctorRadioButton->setText(QApplication::translate("Widget", "\345\214\273\347\224\237", nullptr));
        patientRadioButton->setText(QApplication::translate("Widget", "\346\202\243\350\200\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
