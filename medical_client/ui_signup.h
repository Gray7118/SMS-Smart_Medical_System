/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *doctorRadioButton;
    QRadioButton *patientRadioButton;
    QLabel *tip1Label;
    QLabel *tip2Label;
    QLineEdit *genderLineEdit;
    QLineEdit *ageLineEdit;
    QLineEdit *phoneNumberLineEdit;
    QLineEdit *emailLineEdit;
    QPushButton *signupButton;
    QPushButton *quitButton;

    void setupUi(QWidget *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName(QString::fromUtf8("SignUp"));
        SignUp->resize(640, 600);
        usernameLineEdit = new QLineEdit(SignUp);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));
        usernameLineEdit->setGeometry(QRect(50, 110, 191, 41));
        passwordLineEdit = new QLineEdit(SignUp);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(50, 160, 191, 41));
        layoutWidget = new QWidget(SignUp);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 210, 161, 64));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        doctorRadioButton = new QRadioButton(layoutWidget);
        doctorRadioButton->setObjectName(QString::fromUtf8("doctorRadioButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        doctorRadioButton->setFont(font);
        doctorRadioButton->setChecked(true);

        verticalLayout->addWidget(doctorRadioButton);

        patientRadioButton = new QRadioButton(layoutWidget);
        patientRadioButton->setObjectName(QString::fromUtf8("patientRadioButton"));
        patientRadioButton->setFont(font);
        patientRadioButton->setChecked(false);

        verticalLayout->addWidget(patientRadioButton);

        tip1Label = new QLabel(SignUp);
        tip1Label->setObjectName(QString::fromUtf8("tip1Label"));
        tip1Label->setGeometry(QRect(50, 70, 181, 31));
        tip1Label->setFont(font);
        tip2Label = new QLabel(SignUp);
        tip2Label->setObjectName(QString::fromUtf8("tip2Label"));
        tip2Label->setGeometry(QRect(50, 300, 181, 31));
        tip2Label->setFont(font);
        genderLineEdit = new QLineEdit(SignUp);
        genderLineEdit->setObjectName(QString::fromUtf8("genderLineEdit"));
        genderLineEdit->setGeometry(QRect(50, 340, 191, 41));
        ageLineEdit = new QLineEdit(SignUp);
        ageLineEdit->setObjectName(QString::fromUtf8("ageLineEdit"));
        ageLineEdit->setGeometry(QRect(50, 390, 191, 41));
        phoneNumberLineEdit = new QLineEdit(SignUp);
        phoneNumberLineEdit->setObjectName(QString::fromUtf8("phoneNumberLineEdit"));
        phoneNumberLineEdit->setGeometry(QRect(50, 440, 191, 41));
        emailLineEdit = new QLineEdit(SignUp);
        emailLineEdit->setObjectName(QString::fromUtf8("emailLineEdit"));
        emailLineEdit->setGeometry(QRect(50, 490, 191, 41));
        signupButton = new QPushButton(SignUp);
        signupButton->setObjectName(QString::fromUtf8("signupButton"));
        signupButton->setGeometry(QRect(340, 460, 100, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        signupButton->setFont(font1);
        quitButton = new QPushButton(SignUp);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(500, 460, 100, 50));
        quitButton->setFont(font1);

        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QWidget *SignUp)
    {
        SignUp->setWindowTitle(QApplication::translate("SignUp", "Form", nullptr));
        usernameLineEdit->setPlaceholderText(QApplication::translate("SignUp", "\347\224\250\346\210\267\345\220\215", nullptr));
        passwordLineEdit->setPlaceholderText(QApplication::translate("SignUp", "\345\257\206\347\240\201", nullptr));
        doctorRadioButton->setText(QApplication::translate("SignUp", "\345\214\273\347\224\237", nullptr));
        patientRadioButton->setText(QApplication::translate("SignUp", "\347\227\205\344\272\272", nullptr));
        tip1Label->setText(QApplication::translate("SignUp", "<html><head/><body><p><span style=\" font-weight:600;\">\345\277\205\345\241\253\344\277\241\346\201\257\357\274\232</span></p></body></html>", nullptr));
        tip2Label->setText(QApplication::translate("SignUp", "<html><head/><body><p><span style=\" font-weight:600;\">\351\200\211\345\241\253\344\277\241\346\201\257\357\274\232</span></p></body></html>", nullptr));
        genderLineEdit->setPlaceholderText(QApplication::translate("SignUp", "\346\200\247\345\210\253", nullptr));
        ageLineEdit->setPlaceholderText(QApplication::translate("SignUp", "\345\271\264\351\276\204", nullptr));
        phoneNumberLineEdit->setPlaceholderText(QApplication::translate("SignUp", "\347\224\265\350\257\235", nullptr));
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
