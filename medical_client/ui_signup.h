/********************************************************************************
** Form generated from reading UI file 'signUp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QVBoxLayout *requiredVBox;
    QLabel *tip1Label;
    QFormLayout *formLayout_required;
    QLabel *label_username;
    QLineEdit *usernameLineEdit;
    QLabel *label_password;
    QLineEdit *passwordLineEdit;
    QLabel *label_usertype;
    QHBoxLayout *hLayout_userType;
    QRadioButton *doctorRadioButton;
    QRadioButton *patientRadioButton;
    QSpacerItem *horizontalSpacer1;
    QVBoxLayout *optionalVBox;
    QLabel *tip2Label;
    QFormLayout *formLayout_optional;
    QLabel *label_gender;
    QLineEdit *genderLineEdit;
    QLabel *label_age;
    QLineEdit *ageLineEdit;
    QLabel *label_phone;
    QLineEdit *phoneNumberLineEdit;
    QLabel *label_email;
    QLineEdit *emailLineEdit;
    QHBoxLayout *hLayout_buttons;
    QSpacerItem *horizontalSpacer2;
    QPushButton *signupButton;
    QSpacerItem *buttonSpacer;
    QPushButton *quitButton;
    QSpacerItem *horizontalSpacer3;

    void setupUi(QWidget *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName(QString::fromUtf8("SignUp"));
        SignUp->resize(640, 650);
        SignUp->setStyleSheet(QString::fromUtf8("\n"
"    /* \344\270\273\347\252\227\345\217\243\346\270\220\345\217\230\350\203\214\346\231\257 & \345\237\272\346\234\254\346\226\207\345\255\227 */\n"
"    QWidget#SignUp {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #d0f0ff,\n"
"            stop:1 #ffffff\n"
"        );\n"
"        font-family: \"Microsoft YaHei\";\n"
"    }\n"
"\n"
"/* \346\240\207\351\242\230\346\224\271\344\270\272\351\273\221\350\211\262 */\n"
"#label_title {\n"
"    color: #000000; /* \351\273\221\350\211\262 */\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* \345\217\226\346\266\210\346\214\211\351\222\256\346\224\271\344\270\272\347\272\242\350\211\262\351\243\216\346\240\274\357\274\214\345\205\266\344\275\231\344\277\235\346\214\201\345\216\237\346\240\267 */\n"
"#quitButton {\n"
"    border-radius: 12px;\n"
"    border: 1px solid #e53935;\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"    background-color: qlineargradient(\n"
"        "
                        "x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #ef5350,\n"
"        stop:1 #d32f2f\n"
"    );\n"
"}\n"
"\n"
"#quitButton:hover {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #e57373,\n"
"        stop:1 #c62828\n"
"    );\n"
"}\n"
"\n"
"#quitButton:pressed {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #d32f2f,\n"
"        stop:1 #b71c1c\n"
"    );\n"
"}\n"
"\n"
"    /* \346\217\220\347\244\272\346\240\207\347\255\276\357\274\210\344\277\235\347\225\231\345\216\237\345\220\215tip1Label/tip2Label\357\274\211 */\n"
"    QLabel {\n"
"        color: #0f2b4a;\n"
"    }\n"
"    #tip1Label, #tip2Label {\n"
"        color: #1e88e5;\n"
"        font-weight: 600;\n"
"    }\n"
"\n"
"    /* \350\276\223\345\205\245\346\241\206\346\240\267\345\274\217\357\274\210\344\270\216\347\231\273\345\275\225\351\241\265\344\270\200\350\207\264\357\274\211 */\n"
"    QLineEdit {\n"
"        border: 2px solid #81d4fa;\n"
"        borde"
                        "r-radius: 12px;\n"
"        padding: 8px 10px;\n"
"        background-color: #ffffff;\n"
"        color: #0f1f38;\n"
"    }\n"
"    QLineEdit:focus {\n"
"        border: 2px solid #1e88e5;\n"
"    }\n"
"\n"
"    /* \345\215\225\351\200\211\346\214\211\351\222\256\351\242\234\350\211\262 */\n"
"    QRadioButton {\n"
"        color: #1e88e5;\n"
"        spacing: 6px;\n"
"    }\n"
"\n"
"    /* \346\214\211\351\222\256\346\240\267\345\274\217\357\274\210\344\270\216\347\231\273\345\275\225\351\241\265\344\270\200\350\207\264\357\274\211 */\n"
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
"    }\n"
"    QPushButton:hover {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"     "
                        "       stop:0 #81d4fa,\n"
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
"\n"
"    /* \345\260\217\346\216\247\344\273\266\347\232\204\346\234\200\345\260\217\351\253\230\345\272\246\344\277\235\350\257\201\346\230\276\347\244\272\357\274\210\344\277\235\347\225\231\345\216\237\346\234\211\345\203\217\347\264\240\346\204\237\357\274\211 */\n"
"    QLineEdit {\n"
"        min-height: 36px;\n"
"    }\n"
"    QPushButton {\n"
"        min-height: 40px;\n"
"        min-width: 90px;\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(SignUp);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_title = new QLabel(SignUp);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setMinimumSize(QSize(0, 48));
        label_title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_title);

        requiredVBox = new QVBoxLayout();
        requiredVBox->setObjectName(QString::fromUtf8("requiredVBox"));
        tip1Label = new QLabel(SignUp);
        tip1Label->setObjectName(QString::fromUtf8("tip1Label"));

        requiredVBox->addWidget(tip1Label);

        formLayout_required = new QFormLayout();
        formLayout_required->setObjectName(QString::fromUtf8("formLayout_required"));
        label_username = new QLabel(SignUp);
        label_username->setObjectName(QString::fromUtf8("label_username"));

        formLayout_required->setWidget(0, QFormLayout::LabelRole, label_username);

        usernameLineEdit = new QLineEdit(SignUp);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));
        usernameLineEdit->setMinimumSize(QSize(191, 56));

        formLayout_required->setWidget(0, QFormLayout::FieldRole, usernameLineEdit);

        label_password = new QLabel(SignUp);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        formLayout_required->setWidget(1, QFormLayout::LabelRole, label_password);

        passwordLineEdit = new QLineEdit(SignUp);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setMinimumSize(QSize(191, 56));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout_required->setWidget(1, QFormLayout::FieldRole, passwordLineEdit);

        label_usertype = new QLabel(SignUp);
        label_usertype->setObjectName(QString::fromUtf8("label_usertype"));

        formLayout_required->setWidget(2, QFormLayout::LabelRole, label_usertype);

        hLayout_userType = new QHBoxLayout();
        hLayout_userType->setObjectName(QString::fromUtf8("hLayout_userType"));
        doctorRadioButton = new QRadioButton(SignUp);
        doctorRadioButton->setObjectName(QString::fromUtf8("doctorRadioButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        doctorRadioButton->setFont(font);
        doctorRadioButton->setChecked(true);

        hLayout_userType->addWidget(doctorRadioButton);

        patientRadioButton = new QRadioButton(SignUp);
        patientRadioButton->setObjectName(QString::fromUtf8("patientRadioButton"));
        patientRadioButton->setFont(font);

        hLayout_userType->addWidget(patientRadioButton);

        horizontalSpacer1 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout_userType->addItem(horizontalSpacer1);


        formLayout_required->setLayout(2, QFormLayout::FieldRole, hLayout_userType);


        requiredVBox->addLayout(formLayout_required);


        verticalLayout->addLayout(requiredVBox);

        optionalVBox = new QVBoxLayout();
        optionalVBox->setObjectName(QString::fromUtf8("optionalVBox"));
        tip2Label = new QLabel(SignUp);
        tip2Label->setObjectName(QString::fromUtf8("tip2Label"));

        optionalVBox->addWidget(tip2Label);

        formLayout_optional = new QFormLayout();
        formLayout_optional->setObjectName(QString::fromUtf8("formLayout_optional"));
        label_gender = new QLabel(SignUp);
        label_gender->setObjectName(QString::fromUtf8("label_gender"));

        formLayout_optional->setWidget(0, QFormLayout::LabelRole, label_gender);

        genderLineEdit = new QLineEdit(SignUp);
        genderLineEdit->setObjectName(QString::fromUtf8("genderLineEdit"));
        genderLineEdit->setMinimumSize(QSize(191, 56));

        formLayout_optional->setWidget(0, QFormLayout::FieldRole, genderLineEdit);

        label_age = new QLabel(SignUp);
        label_age->setObjectName(QString::fromUtf8("label_age"));

        formLayout_optional->setWidget(1, QFormLayout::LabelRole, label_age);

        ageLineEdit = new QLineEdit(SignUp);
        ageLineEdit->setObjectName(QString::fromUtf8("ageLineEdit"));
        ageLineEdit->setMinimumSize(QSize(191, 56));

        formLayout_optional->setWidget(1, QFormLayout::FieldRole, ageLineEdit);

        label_phone = new QLabel(SignUp);
        label_phone->setObjectName(QString::fromUtf8("label_phone"));

        formLayout_optional->setWidget(2, QFormLayout::LabelRole, label_phone);

        phoneNumberLineEdit = new QLineEdit(SignUp);
        phoneNumberLineEdit->setObjectName(QString::fromUtf8("phoneNumberLineEdit"));
        phoneNumberLineEdit->setMinimumSize(QSize(191, 56));

        formLayout_optional->setWidget(2, QFormLayout::FieldRole, phoneNumberLineEdit);

        label_email = new QLabel(SignUp);
        label_email->setObjectName(QString::fromUtf8("label_email"));

        formLayout_optional->setWidget(3, QFormLayout::LabelRole, label_email);

        emailLineEdit = new QLineEdit(SignUp);
        emailLineEdit->setObjectName(QString::fromUtf8("emailLineEdit"));
        emailLineEdit->setMinimumSize(QSize(191, 56));

        formLayout_optional->setWidget(3, QFormLayout::FieldRole, emailLineEdit);


        optionalVBox->addLayout(formLayout_optional);


        verticalLayout->addLayout(optionalVBox);

        hLayout_buttons = new QHBoxLayout();
        hLayout_buttons->setObjectName(QString::fromUtf8("hLayout_buttons"));
        horizontalSpacer2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout_buttons->addItem(horizontalSpacer2);

        signupButton = new QPushButton(SignUp);
        signupButton->setObjectName(QString::fromUtf8("signupButton"));
        signupButton->setMinimumSize(QSize(124, 58));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        signupButton->setFont(font1);

        hLayout_buttons->addWidget(signupButton);

        buttonSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout_buttons->addItem(buttonSpacer);

        quitButton = new QPushButton(SignUp);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setMinimumSize(QSize(124, 58));
        quitButton->setFont(font1);

        hLayout_buttons->addWidget(quitButton);

        horizontalSpacer3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout_buttons->addItem(horizontalSpacer3);


        verticalLayout->addLayout(hLayout_buttons);


        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QWidget *SignUp)
    {
        SignUp->setWindowTitle(QApplication::translate("SignUp", "\346\263\250\345\206\214", nullptr));
        label_title->setText(QApplication::translate("SignUp", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        tip1Label->setText(QApplication::translate("SignUp", "<html><body><p><span style=\" font-weight:600;\">\345\277\205\345\241\253\344\277\241\346\201\257\357\274\232</span></p></body></html>", nullptr));
        label_username->setText(QApplication::translate("SignUp", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        usernameLineEdit->setPlaceholderText(QApplication::translate("SignUp", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_password->setText(QApplication::translate("SignUp", "\345\257\206\347\240\201\357\274\232", nullptr));
        passwordLineEdit->setPlaceholderText(QApplication::translate("SignUp", "\345\257\206\347\240\201", nullptr));
        label_usertype->setText(QApplication::translate("SignUp", "\347\224\250\346\210\267\347\261\273\345\236\213\357\274\232", nullptr));
        doctorRadioButton->setText(QApplication::translate("SignUp", "\345\214\273\347\224\237", nullptr));
        patientRadioButton->setText(QApplication::translate("SignUp", "\346\202\243\350\200\205", nullptr));
        tip2Label->setText(QApplication::translate("SignUp", "<html><body><p><span style=\" font-weight:600;\">\351\200\211\345\241\253\344\277\241\346\201\257\357\274\232</span></p></body></html>", nullptr));
        label_gender->setText(QApplication::translate("SignUp", "\346\200\247\345\210\253\357\274\232", nullptr));
        genderLineEdit->setPlaceholderText(QApplication::translate("SignUp", "\346\200\247\345\210\253", nullptr));
        label_age->setText(QApplication::translate("SignUp", "\345\271\264\351\276\204\357\274\232", nullptr));
        ageLineEdit->setPlaceholderText(QApplication::translate("SignUp", "\345\271\264\351\276\204", nullptr));
        label_phone->setText(QApplication::translate("SignUp", "\347\224\265\350\257\235\357\274\232", nullptr));
        phoneNumberLineEdit->setPlaceholderText(QApplication::translate("SignUp", "\347\224\265\350\257\235", nullptr));
        label_email->setText(QApplication::translate("SignUp", "\351\202\256\347\256\261\357\274\232", nullptr));
        emailLineEdit->setPlaceholderText(QApplication::translate("SignUp", "\351\202\256\347\256\261", nullptr));
        signupButton->setText(QApplication::translate("SignUp", "\346\263\250\345\206\214", nullptr));
        quitButton->setText(QApplication::translate("SignUp", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
