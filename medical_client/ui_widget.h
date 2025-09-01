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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *formContainer;
    QVBoxLayout *verticalLayout;
    QLabel *welcomeLabel;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *roleLabel;
    QHBoxLayout *horizontalLayout;
    QRadioButton *doctorRadioButton;
    QRadioButton *patientRadioButton;
    QHBoxLayout *buttonLayout;
    QPushButton *loginButton;
    QPushButton *signupButton;
    QPushButton *emergencyButton;
    QPushButton *pushButton_navigation;
    QPushButton *quitButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *logoLabel;
    QLabel *titleLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        Widget->setMinimumSize(QSize(800, 600));
        Widget->setStyleSheet(QString::fromUtf8("\n"
"    /* \344\270\273\347\252\227\345\217\243\346\270\220\345\217\230\350\203\214\346\231\257 */\n"
"    QWidget#Widget {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #d0f0ff,\n"
"            stop:1 #ffffff\n"
"        );\n"
"    }\n"
"\n"
"    /* \346\240\207\351\242\230\346\240\267\345\274\217 */\n"
"    #titleLabel {\n"
"        color: #1e88e5;\n"
"        font-size: 36px;\n"
"        font-weight: bold;\n"
"        text-shadow: 1px 1px 3px #81d4fa;\n"
"    }\n"
"\n"
"    /* \346\254\242\350\277\216\346\240\207\347\255\276 */\n"
"    #welcomeLabel {\n"
"        color: #1e88e5;\n"
"        font-size: 20px;\n"
"        font-weight: bold;\n"
"        qproperty-alignment: AlignCenter;\n"
"    }\n"
"\n"
"    /* \350\276\223\345\205\245\346\241\206\346\240\267\345\274\217 */\n"
"    QLineEdit {\n"
"        border: 2px solid #81d4fa;\n"
"        border-radius: 12px;\n"
"        padding: 10px;\n"
"        font-size: 14px;\n"
"        background-colo"
                        "r: #ffffff;\n"
"        color: #0f1f38;\n"
"        selection-background-color: #4fc3f7;\n"
"        selection-color: #ffffff;\n"
"    }\n"
"    QLineEdit:focus {\n"
"        border: 2px solid #1e88e5;\n"
"    }\n"
"\n"
"    /* \346\214\211\351\222\256\351\253\230\347\272\247\346\270\220\345\217\230\347\247\221\346\212\200\351\243\216 */\n"
"    QPushButton {\n"
"        border-radius: 14px;\n"
"        border: 1px solid #64b5f6;\n"
"        color: #ffffff;\n"
"        font-weight: bold;\n"
"        font-size: 16px;\n"
"        padding: 10px 20px;\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #6ec6ff,\n"
"            stop:1 #1e88e5\n"
"        );\n"
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
"            "
                        "x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #1e88e5,\n"
"            stop:1 #1565c0\n"
"        );\n"
"    }\n"
"    QPushButton {\n"
"        text-shadow: 1px 1px 2px rgba(0,0,0,0.2);\n"
"    }\n"
"\n"
"    /* \346\200\245\350\257\212\346\214\211\351\222\256 */\n"
"    #emergencyButton {\n"
"        border-radius: 14px;\n"
"        border: 1px solid #e57373;\n"
"        color: #ffffff;\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #ff7f7f,\n"
"            stop:1 #e53935\n"
"        );\n"
"    }\n"
"    #emergencyButton:hover {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #ff8a80,\n"
"            stop:1 #f44336\n"
"        );\n"
"    }\n"
"    #emergencyButton:pressed {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #e53935,\n"
"            stop:1 #c62828\n"
"        );\n"
"    }\n"
"\n"
"    /* \345\215\225\351\200\211"
                        "\346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"    QRadioButton {\n"
"        font-size: 14px;\n"
"        spacing: 8px;\n"
"        color: #1e88e5;\n"
"    }\n"
"\n"
"    /* \350\241\250\345\215\225\345\256\271\345\231\250\346\240\267\345\274\217 */\n"
"    #formContainer {\n"
"        background-color: transparent;\n"
"        border-radius: 18px;\n"
"        padding: 20px;\n"
"        margin: 20px;\n"
"        border: 1px solid transparent;\n"
"    }\n"
"   "));
        formContainer = new QWidget(Widget);
        formContainer->setObjectName(QString::fromUtf8("formContainer"));
        formContainer->setGeometry(QRect(200, 120, 400, 481));
        verticalLayout = new QVBoxLayout(formContainer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        welcomeLabel = new QLabel(formContainer);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));

        verticalLayout->addWidget(welcomeLabel);

        usernameLineEdit = new QLineEdit(formContainer);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));

        verticalLayout->addWidget(usernameLineEdit);

        passwordLineEdit = new QLineEdit(formContainer);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordLineEdit);

        roleLabel = new QLabel(formContainer);
        roleLabel->setObjectName(QString::fromUtf8("roleLabel"));

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

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        loginButton = new QPushButton(formContainer);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        buttonLayout->addWidget(loginButton);

        signupButton = new QPushButton(formContainer);
        signupButton->setObjectName(QString::fromUtf8("signupButton"));

        buttonLayout->addWidget(signupButton);


        verticalLayout->addLayout(buttonLayout);

        emergencyButton = new QPushButton(formContainer);
        emergencyButton->setObjectName(QString::fromUtf8("emergencyButton"));

        verticalLayout->addWidget(emergencyButton);

        pushButton_navigation = new QPushButton(formContainer);
        pushButton_navigation->setObjectName(QString::fromUtf8("pushButton_navigation"));

        verticalLayout->addWidget(pushButton_navigation);

        quitButton = new QPushButton(formContainer);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        verticalLayout->addWidget(quitButton);

        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(270, 20, 243, 92));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        logoLabel = new QLabel(widget);
        logoLabel->setObjectName(QString::fromUtf8("logoLabel"));
        logoLabel->setMinimumSize(QSize(90, 90));
        logoLabel->setMaximumSize(QSize(90, 90));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        logoLabel->setScaledContents(true);
        logoLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(logoLabel);

        titleLabel = new QLabel(widget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy);
        titleLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(titleLabel);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\345\257\260\345\256\207\345\214\273\346\241\245", nullptr));
        welcomeLabel->setText(QApplication::translate("Widget", "\346\254\242\350\277\216\347\231\273\345\275\225", nullptr));
        usernameLineEdit->setPlaceholderText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        passwordLineEdit->setPlaceholderText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        roleLabel->setText(QApplication::translate("Widget", "\350\257\267\351\200\211\346\213\251\347\224\250\346\210\267\347\261\273\345\236\213\357\274\232", nullptr));
        doctorRadioButton->setText(QApplication::translate("Widget", "\345\214\273\347\224\237", nullptr));
        patientRadioButton->setText(QApplication::translate("Widget", "\346\202\243\350\200\205", nullptr));
        loginButton->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        signupButton->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        emergencyButton->setText(QApplication::translate("Widget", "\346\200\245\350\257\212\351\200\232\351\201\223", nullptr));
        pushButton_navigation->setText(QApplication::translate("Widget", "\345\214\273\351\231\242\345\257\274\350\210\252", nullptr));
        quitButton->setText(QApplication::translate("Widget", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        titleLabel->setText(QApplication::translate("Widget", "\345\257\260\345\256\207\345\214\273\346\241\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
