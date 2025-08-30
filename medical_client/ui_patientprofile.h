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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientProfile
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *scheduleButton;
    QPushButton *appointmentCaseButton;
    QPushButton *profileButton;
    QPushButton *doctorButton;
    QPushButton *healthButton;
    QPushButton *chatButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *quitButton;

    void setupUi(QWidget *PatientProfile)
    {
        if (PatientProfile->objectName().isEmpty())
            PatientProfile->setObjectName(QString::fromUtf8("PatientProfile"));
        PatientProfile->resize(648, 583);
        layoutWidget = new QWidget(PatientProfile);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 202, 552));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scheduleButton = new QPushButton(layoutWidget);
        scheduleButton->setObjectName(QString::fromUtf8("scheduleButton"));
        scheduleButton->setMinimumSize(QSize(200, 60));
        scheduleButton->setMaximumSize(QSize(200, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        scheduleButton->setFont(font);

        verticalLayout->addWidget(scheduleButton);

        appointmentCaseButton = new QPushButton(layoutWidget);
        appointmentCaseButton->setObjectName(QString::fromUtf8("appointmentCaseButton"));
        appointmentCaseButton->setMinimumSize(QSize(200, 60));
        appointmentCaseButton->setMaximumSize(QSize(200, 60));
        appointmentCaseButton->setFont(font);

        verticalLayout->addWidget(appointmentCaseButton);

        profileButton = new QPushButton(layoutWidget);
        profileButton->setObjectName(QString::fromUtf8("profileButton"));
        profileButton->setMinimumSize(QSize(200, 60));
        profileButton->setMaximumSize(QSize(200, 60));
        profileButton->setFont(font);

        verticalLayout->addWidget(profileButton);

        doctorButton = new QPushButton(layoutWidget);
        doctorButton->setObjectName(QString::fromUtf8("doctorButton"));
        doctorButton->setMinimumSize(QSize(200, 60));
        doctorButton->setMaximumSize(QSize(200, 60));
        doctorButton->setFont(font);

        verticalLayout->addWidget(doctorButton);

        healthButton = new QPushButton(layoutWidget);
        healthButton->setObjectName(QString::fromUtf8("healthButton"));
        healthButton->setMinimumSize(QSize(200, 60));
        healthButton->setMaximumSize(QSize(200, 60));
        healthButton->setFont(font);

        verticalLayout->addWidget(healthButton);

        chatButton = new QPushButton(layoutWidget);
        chatButton->setObjectName(QString::fromUtf8("chatButton"));
        chatButton->setMinimumSize(QSize(200, 60));
        chatButton->setMaximumSize(QSize(200, 60));
        chatButton->setFont(font);

        verticalLayout->addWidget(chatButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        quitButton = new QPushButton(layoutWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setMinimumSize(QSize(200, 60));
        quitButton->setMaximumSize(QSize(200, 60));
        quitButton->setFont(font);

        verticalLayout->addWidget(quitButton);


        retranslateUi(PatientProfile);

        QMetaObject::connectSlotsByName(PatientProfile);
    } // setupUi

    void retranslateUi(QWidget *PatientProfile)
    {
        PatientProfile->setWindowTitle(QApplication::translate("PatientProfile", "Form", nullptr));
        scheduleButton->setText(QApplication::translate("PatientProfile", "\346\214\202\345\217\267", nullptr));
        appointmentCaseButton->setText(QApplication::translate("PatientProfile", "\346\237\245\347\234\213\347\227\205\344\276\213\345\222\214\345\244\204\346\226\271", nullptr));
        profileButton->setText(QApplication::translate("PatientProfile", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        doctorButton->setText(QApplication::translate("PatientProfile", "\346\237\245\347\234\213\345\214\273\347\224\237\344\277\241\346\201\257", nullptr));
        healthButton->setText(QApplication::translate("PatientProfile", "\345\201\245\345\272\267\350\257\204\344\274\260", nullptr));
        chatButton->setText(QApplication::translate("PatientProfile", "\345\214\273\346\202\243\346\262\237\351\200\232\345\271\263\345\217\260", nullptr));
        quitButton->setText(QApplication::translate("PatientProfile", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientProfile: public Ui_PatientProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTPROFILE_H
