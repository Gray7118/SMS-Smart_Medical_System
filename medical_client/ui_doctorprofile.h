/********************************************************************************
** Form generated from reading UI file 'doctorprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORPROFILE_H
#define UI_DOCTORPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doctorProfile
{
public:
    QVBoxLayout *mainVerticalLayout;
    QHBoxLayout *titleLayout;
    QLabel *logoLabel;
    QLabel *titleLabel;
    QHBoxLayout *mainContentLayout;
    QLabel *doctorPhotoLabel;
    QVBoxLayout *buttonVBoxLayout;
    QPushButton *scheduleButton;
    QPushButton *appointmentCaseButton;
    QPushButton *profileButton;
    QPushButton *chatButton;
    QPushButton *emailPatientButton;
    QSpacerItem *verticalSpacerButtons;
    QHBoxLayout *quitButtonLayout;
    QSpacerItem *leftSpacer;
    QPushButton *quitButton;
    QSpacerItem *rightSpacer;

    void setupUi(QWidget *doctorProfile)
    {
        if (doctorProfile->objectName().isEmpty())
            doctorProfile->setObjectName(QString::fromUtf8("doctorProfile"));
        doctorProfile->resize(700, 600);
        doctorProfile->setStyleSheet(QString::fromUtf8("\n"
"    QWidget#doctorProfile {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #e3f2fd,\n"
"            stop:1 #ffffff\n"
"        );\n"
"        font-family: \"Microsoft YaHei\";\n"
"    }\n"
"    QLabel#doctorPhotoLabel {\n"
"        border: 2px solid #64b5f6;\n"
"        border-radius: 12px;\n"
"        background-color: #ffffff;\n"
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
"        padding: 8px 16px;\n"
"        min-width: 180px;\n"
"        min-height: 50px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #81d4fa,\n"
"            stop:1 #1976d2\n"
"        );\n"
""
                        "    }\n"
"    QPushButton:pressed {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #1e88e5,\n"
"            stop:1 #1565c0\n"
"        );\n"
"    }\n"
"    /* \345\217\252\344\277\256\346\224\271\351\200\200\345\207\272\346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"    #quitButton {\n"
"        background-color: #e74c3c;\n"
"    }\n"
"    #quitButton:hover { background-color: #c0392b; }\n"
"   "));
        mainVerticalLayout = new QVBoxLayout(doctorProfile);
        mainVerticalLayout->setSpacing(20);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        titleLayout = new QHBoxLayout();
        titleLayout->setObjectName(QString::fromUtf8("titleLayout"));
        logoLabel = new QLabel(doctorProfile);
        logoLabel->setObjectName(QString::fromUtf8("logoLabel"));
        logoLabel->setMinimumSize(QSize(80, 80));
        logoLabel->setMaximumSize(QSize(80, 80));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        logoLabel->setScaledContents(true);

        titleLayout->addWidget(logoLabel);

        titleLabel = new QLabel(doctorProfile);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignVCenter|Qt::AlignLeft);

        titleLayout->addWidget(titleLabel);


        mainVerticalLayout->addLayout(titleLayout);

        mainContentLayout = new QHBoxLayout();
        mainContentLayout->setSpacing(30);
        mainContentLayout->setObjectName(QString::fromUtf8("mainContentLayout"));
        doctorPhotoLabel = new QLabel(doctorProfile);
        doctorPhotoLabel->setObjectName(QString::fromUtf8("doctorPhotoLabel"));
        doctorPhotoLabel->setMinimumSize(QSize(240, 320));
        doctorPhotoLabel->setMaximumSize(QSize(240, 320));
        doctorPhotoLabel->setPixmap(QPixmap(QString::fromUtf8("doctor.png")));
        doctorPhotoLabel->setAlignment(Qt::AlignCenter);
        doctorPhotoLabel->setScaledContents(true);

        mainContentLayout->addWidget(doctorPhotoLabel);

        buttonVBoxLayout = new QVBoxLayout();
        buttonVBoxLayout->setSpacing(15);
        buttonVBoxLayout->setObjectName(QString::fromUtf8("buttonVBoxLayout"));
        scheduleButton = new QPushButton(doctorProfile);
        scheduleButton->setObjectName(QString::fromUtf8("scheduleButton"));

        buttonVBoxLayout->addWidget(scheduleButton);

        appointmentCaseButton = new QPushButton(doctorProfile);
        appointmentCaseButton->setObjectName(QString::fromUtf8("appointmentCaseButton"));

        buttonVBoxLayout->addWidget(appointmentCaseButton);

        profileButton = new QPushButton(doctorProfile);
        profileButton->setObjectName(QString::fromUtf8("profileButton"));

        buttonVBoxLayout->addWidget(profileButton);

        chatButton = new QPushButton(doctorProfile);
        chatButton->setObjectName(QString::fromUtf8("chatButton"));

        buttonVBoxLayout->addWidget(chatButton);

        emailPatientButton = new QPushButton(doctorProfile);
        emailPatientButton->setObjectName(QString::fromUtf8("emailPatientButton"));

        buttonVBoxLayout->addWidget(emailPatientButton);

        verticalSpacerButtons = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        buttonVBoxLayout->addItem(verticalSpacerButtons);


        mainContentLayout->addLayout(buttonVBoxLayout);


        mainVerticalLayout->addLayout(mainContentLayout);

        quitButtonLayout = new QHBoxLayout();
        quitButtonLayout->setObjectName(QString::fromUtf8("quitButtonLayout"));
        leftSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        quitButtonLayout->addItem(leftSpacer);

        quitButton = new QPushButton(doctorProfile);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setMinimumSize(QSize(200, 50));

        quitButtonLayout->addWidget(quitButton);

        rightSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        quitButtonLayout->addItem(rightSpacer);


        mainVerticalLayout->addLayout(quitButtonLayout);


        retranslateUi(doctorProfile);

        QMetaObject::connectSlotsByName(doctorProfile);
    } // setupUi

    void retranslateUi(QWidget *doctorProfile)
    {
        doctorProfile->setWindowTitle(QApplication::translate("doctorProfile", "\345\214\273\347\224\237\344\270\273\351\241\265", nullptr));
        titleLabel->setText(QApplication::translate("doctorProfile", "\345\214\273\347\224\237\344\270\273\351\241\265", nullptr));
        scheduleButton->setText(QApplication::translate("doctorProfile", "\346\237\245\347\234\213\346\211\200\346\234\211\346\214\202\345\217\267\345\222\214\347\227\205\344\276\213", nullptr));
        appointmentCaseButton->setText(QApplication::translate("doctorProfile", "\347\274\226\350\276\221\347\227\205\344\276\213\345\222\214\345\244\204\346\226\271", nullptr));
        profileButton->setText(QApplication::translate("doctorProfile", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        chatButton->setText(QApplication::translate("doctorProfile", "\345\214\273\346\202\243\346\262\237\351\200\232\345\271\263\345\217\260", nullptr));
        emailPatientButton->setText(QApplication::translate("doctorProfile", "\345\217\221\351\200\201\351\202\256\344\273\266\347\273\231\346\202\243\350\200\205", nullptr));
        quitButton->setText(QApplication::translate("doctorProfile", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class doctorProfile: public Ui_doctorProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORPROFILE_H
