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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *titleLabel;
    QWidget *formContainer;
    QVBoxLayout *verticalLayout;
    QLabel *welcomeLabel;
    QSpacerItem *verticalSpacer_1;
    QLineEdit *usernameLineEdit;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *passwordLineEdit;
    QSpacerItem *verticalSpacer_3;
    QLabel *roleLabel;
    QHBoxLayout *horizontalLayout;
    QRadioButton *doctorRadioButton;
    QRadioButton *patientRadioButton;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *buttonLayout;
    QPushButton *loginButton;
    QPushButton *signupButton;
    QSpacerItem *verticalSpacer_5;
    QPushButton *emergencyButton;
    QSpacerItem *verticalSpacer_6;
    QPushButton *quitButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        Widget->setMinimumSize(QSize(800, 600));
        Widget->setStyleSheet(QString::fromUtf8("\n"
"    /* \344\270\273\347\252\227\345\217\243\346\240\267\345\274\217 */\n"
"    QWidget {\n"
"        background-color: #f0f8ff; /* \346\265\205\350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"        font-family: 'Microsoft YaHei';\n"
"    }\n"
"\n"
"    /* \346\240\207\351\242\230\346\240\267\345\274\217 */\n"
"    #titleLabel {\n"
"        color: #2b5876;\n"
"        font-size: 28px;\n"
"        font-weight: bold;\n"
"        qproperty-alignment: AlignCenter;\n"
"    }\n"
"\n"
"    /* \350\276\223\345\205\245\346\241\206\346\240\267\345\274\217 */\n"
"    QLineEdit {\n"
"        border: 2px solid #a0c6e8;\n"
"        border-radius: 8px;\n"
"        padding: 10px;\n"
"        font-size: 14px;\n"
"        background-color: white;\n"
"        min-width: 250px;\n"
"    }\n"
"\n"
"    QLineEdit:focus {\n"
"        border: 2px solid #4a90e2;\n"
"    }\n"
"\n"
"    /* \346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"    QPushButton {\n"
"        background-color: #4a90e2;\n"
"        color: white"
                        ";\n"
"        border: none;\n"
"        border-radius: 8px;\n"
"        padding: 12px 24px;\n"
"        font-size: 16px;\n"
"        font-weight: bold;\n"
"        min-width: 120px;\n"
"    }\n"
"\n"
"    QPushButton:hover {\n"
"        background-color: #3a7bc8;\n"
"    }\n"
"\n"
"    QPushButton:pressed {\n"
"        background-color: #2c6bb6;\n"
"    }\n"
"\n"
"    /* \346\200\245\350\257\212\346\214\211\351\222\256\347\211\271\346\256\212\346\240\267\345\274\217 */\n"
"    #emergencyButton {\n"
"        background-color: #ff5555;\n"
"    }\n"
"\n"
"    #emergencyButton:hover {\n"
"        background-color: #e64545;\n"
"    }\n"
"\n"
"    /* \345\215\225\351\200\211\346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"    QRadioButton {\n"
"        font-size: 14px;\n"
"        spacing: 8px;\n"
"    }\n"
"\n"
"    /* \350\241\250\345\215\225\345\256\271\345\231\250\346\240\267\345\274\217 */\n"
"    #formContainer {\n"
"        background-color: white;\n"
"        border-radius: 12px;\n"
"        padding: "
                        "30px;\n"
"        margin: 20px;\n"
"        box-shadow: 0 4px 8px rgba(0,0,0,0.1);\n"
"    }\n"
"   "));
        titleLabel = new QLabel(Widget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(0, 30, 800, 60));
        formContainer = new QWidget(Widget);
        formContainer->setObjectName(QString::fromUtf8("formContainer"));
        formContainer->setGeometry(QRect(200, 120, 400, 400));
        verticalLayout = new QVBoxLayout(formContainer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        welcomeLabel = new QLabel(formContainer);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));
        welcomeLabel->setStyleSheet(QString::fromUtf8("\n"
"        font-size: 20px;\n"
"        font-weight: bold;\n"
"        color: #2b5876;\n"
"        qproperty-alignment: AlignCenter;\n"
"       "));

        verticalLayout->addWidget(welcomeLabel);

        verticalSpacer_1 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_1);

        usernameLineEdit = new QLineEdit(formContainer);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));

        verticalLayout->addWidget(usernameLineEdit);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        passwordLineEdit = new QLineEdit(formContainer);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordLineEdit);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        roleLabel = new QLabel(formContainer);
        roleLabel->setObjectName(QString::fromUtf8("roleLabel"));
        roleLabel->setStyleSheet(QString::fromUtf8("\n"
"        font-size: 14px;\n"
"        font-weight: bold;\n"
"       "));

        verticalLayout->addWidget(roleLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        doctorRadioButton = new QRadioButton(formContainer);
        doctorRadioButton->setObjectName(QString::fromUtf8("doctorRadioButton"));
        doctorRadioButton->setChecked(true);

        horizontalLayout->addWidget(doctorRadioButton);

        patientRadioButton = new QRadioButton(formContainer);
        patientRadioButton->setObjectName(QString::fromUtf8("patientRadioButton"));

        horizontalLayout->addWidget(patientRadioButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        loginButton = new QPushButton(formContainer);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        buttonLayout->addWidget(loginButton);

        signupButton = new QPushButton(formContainer);
        signupButton->setObjectName(QString::fromUtf8("signupButton"));

        buttonLayout->addWidget(signupButton);


        verticalLayout->addLayout(buttonLayout);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        emergencyButton = new QPushButton(formContainer);
        emergencyButton->setObjectName(QString::fromUtf8("emergencyButton"));
        emergencyButton->setStyleSheet(QString::fromUtf8("#emergencyButton"));

        verticalLayout->addWidget(emergencyButton);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        quitButton = new QPushButton(formContainer);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        verticalLayout->addWidget(quitButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\344\270\255\345\233\275\346\227\240\345\233\275\347\225\214\345\214\273\347\226\227\345\271\263\345\217\260", nullptr));
        titleLabel->setText(QApplication::translate("Widget", "\344\270\255\345\233\275\346\227\240\345\233\275\347\225\214\345\214\273\347\226\227\345\271\263\345\217\260", nullptr));
        welcomeLabel->setText(QApplication::translate("Widget", "\346\254\242\350\277\216\347\231\273\345\275\225", nullptr));
        usernameLineEdit->setPlaceholderText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        passwordLineEdit->setPlaceholderText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        roleLabel->setText(QApplication::translate("Widget", "\350\257\267\351\200\211\346\213\251\347\224\250\346\210\267\347\261\273\345\236\213\357\274\232", nullptr));
        doctorRadioButton->setText(QApplication::translate("Widget", "\345\214\273\347\224\237", nullptr));
        patientRadioButton->setText(QApplication::translate("Widget", "\346\202\243\350\200\205", nullptr));
        loginButton->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        signupButton->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        emergencyButton->setText(QApplication::translate("Widget", "\346\200\245\350\257\212\351\200\232\351\201\223", nullptr));
        quitButton->setText(QApplication::translate("Widget", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
