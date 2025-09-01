/********************************************************************************
** Form generated from reading UI file 'patientprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTPROFILE_H
#define UI_PATIENTPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientProfile
{
public:
    QVBoxLayout *mainVerticalLayout;
    QHBoxLayout *titleLayout;
    QLabel *logoLabel;
    QLabel *titleLabel;
    QHBoxLayout *mainContentLayout;
    QLabel *patientPhotoLabel;
    QVBoxLayout *buttonVBoxLayout;
    QPushButton *scheduleButton;
    QPushButton *appointmentCaseButton;
    QPushButton *profileButton;
    QPushButton *doctorButton;
    QPushButton *emailDoctorButton;
    QSpacerItem *verticalSpacerButtons;
    QHBoxLayout *quitButtonLayout;
    QSpacerItem *leftSpacer;
    QPushButton *quitButton;
    QSpacerItem *rightSpacer;

    void setupUi(QWidget *PatientProfile)
    {
        if (PatientProfile->objectName().isEmpty())
            PatientProfile->setObjectName(QString::fromUtf8("PatientProfile"));
        PatientProfile->resize(700, 600);
        PatientProfile->setStyleSheet(QString::fromUtf8("\n"
"    QWidget#PatientProfile {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #e3f2fd,\n"
"            stop:1 #ffffff\n"
"        );\n"
"        font-family: \"Microsoft YaHei\";\n"
"    }\n"
"    QLabel#patientPhotoLabel {\n"
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
"    #quitButton {\n"
"        background-color: #e74c3c;\n"
"    }\n"
"    #quitButton:hover { background-color: #c0392b; }\n"
"   "));
        mainVerticalLayout = new QVBoxLayout(PatientProfile);
        mainVerticalLayout->setSpacing(20);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        titleLayout = new QHBoxLayout();
        titleLayout->setObjectName(QString::fromUtf8("titleLayout"));
        logoLabel = new QLabel(PatientProfile);
        logoLabel->setObjectName(QString::fromUtf8("logoLabel"));
        logoLabel->setMinimumSize(QSize(80, 80));
        logoLabel->setMaximumSize(QSize(80, 80));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        logoLabel->setScaledContents(true);

        titleLayout->addWidget(logoLabel);

        titleLabel = new QLabel(PatientProfile);
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
        patientPhotoLabel = new QLabel(PatientProfile);
        patientPhotoLabel->setObjectName(QString::fromUtf8("patientPhotoLabel"));
        patientPhotoLabel->setMinimumSize(QSize(240, 320));
        patientPhotoLabel->setMaximumSize(QSize(240, 320));
        patientPhotoLabel->setPixmap(QPixmap(QString::fromUtf8("patient.png")));
        patientPhotoLabel->setAlignment(Qt::AlignCenter);
        patientPhotoLabel->setScaledContents(true);

        mainContentLayout->addWidget(patientPhotoLabel);

        buttonVBoxLayout = new QVBoxLayout();
        buttonVBoxLayout->setSpacing(15);
        buttonVBoxLayout->setObjectName(QString::fromUtf8("buttonVBoxLayout"));
        scheduleButton = new QPushButton(PatientProfile);
        scheduleButton->setObjectName(QString::fromUtf8("scheduleButton"));

        buttonVBoxLayout->addWidget(scheduleButton);

        appointmentCaseButton = new QPushButton(PatientProfile);
        appointmentCaseButton->setObjectName(QString::fromUtf8("appointmentCaseButton"));

        buttonVBoxLayout->addWidget(appointmentCaseButton);

        profileButton = new QPushButton(PatientProfile);
        profileButton->setObjectName(QString::fromUtf8("profileButton"));

        buttonVBoxLayout->addWidget(profileButton);

        doctorButton = new QPushButton(PatientProfile);
        doctorButton->setObjectName(QString::fromUtf8("doctorButton"));

        buttonVBoxLayout->addWidget(doctorButton);

        emailDoctorButton = new QPushButton(PatientProfile);
        emailDoctorButton->setObjectName(QString::fromUtf8("emailDoctorButton"));

        buttonVBoxLayout->addWidget(emailDoctorButton);

        verticalSpacerButtons = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        buttonVBoxLayout->addItem(verticalSpacerButtons);


        mainContentLayout->addLayout(buttonVBoxLayout);


        mainVerticalLayout->addLayout(mainContentLayout);

        quitButtonLayout = new QHBoxLayout();
        quitButtonLayout->setObjectName(QString::fromUtf8("quitButtonLayout"));
        leftSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        quitButtonLayout->addItem(leftSpacer);

        quitButton = new QPushButton(PatientProfile);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setMinimumSize(QSize(200, 50));

        quitButtonLayout->addWidget(quitButton);

        rightSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        quitButtonLayout->addItem(rightSpacer);


        mainVerticalLayout->addLayout(quitButtonLayout);


        retranslateUi(PatientProfile);

        QMetaObject::connectSlotsByName(PatientProfile);
    } // setupUi

    void retranslateUi(QWidget *PatientProfile)
    {
        PatientProfile->setWindowTitle(QApplication::translate("PatientProfile", "\346\202\243\350\200\205\344\270\273\351\241\265", nullptr));
        titleLabel->setText(QApplication::translate("PatientProfile", "\346\202\243\350\200\205\344\270\273\351\241\265", nullptr));
        scheduleButton->setText(QApplication::translate("PatientProfile", "\346\214\202\345\217\267\351\242\204\347\272\246", nullptr));
        appointmentCaseButton->setText(QApplication::translate("PatientProfile", "\346\237\245\347\234\213\347\227\205\345\216\206\344\270\216\345\244\204\346\226\271", nullptr));
        profileButton->setText(QApplication::translate("PatientProfile", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        doctorButton->setText(QApplication::translate("PatientProfile", "\346\237\245\347\234\213\345\214\273\347\224\237\344\277\241\346\201\257", nullptr));
        emailDoctorButton->setText(QApplication::translate("PatientProfile", "\345\217\221\351\200\201\351\202\256\344\273\266\347\273\231\345\214\273\347\224\237", nullptr));
        quitButton->setText(QApplication::translate("PatientProfile", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientProfile: public Ui_PatientProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTPROFILE_H
