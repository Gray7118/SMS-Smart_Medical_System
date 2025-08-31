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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientProfile
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *buttonContainer;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QPushButton *scheduleButton;
    QSpacerItem *verticalSpacer_1;
    QPushButton *appointmentCaseButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *profileButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *doctorButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *healthButton;
    QSpacerItem *verticalSpacer_5;
    QPushButton *chatButton;
    QSpacerItem *verticalSpacer_6;
    QPushButton *quitButton;
    QSpacerItem *verticalSpacer_7;

    void setupUi(QWidget *PatientProfile)
    {
        if (PatientProfile->objectName().isEmpty())
            PatientProfile->setObjectName(QString::fromUtf8("PatientProfile"));
        PatientProfile->resize(850, 900);
        PatientProfile->setMinimumSize(QSize(850, 900));
        PatientProfile->setStyleSheet(QString::fromUtf8("\n"
"    /* \344\270\273\347\252\227\345\217\243\346\240\267\345\274\217 */\n"
"    QWidget {\n"
"        background-color: #f5f9ff;\n"
"        font-family: 'Microsoft YaHei';\n"
"    }\n"
"\n"
"    /* \346\214\211\351\222\256\351\200\232\347\224\250\346\240\267\345\274\217 */\n"
"    QPushButton {\n"
"        background-color: #4a90e2;\n"
"        color: white;\n"
"        border: none;\n"
"        border-radius: 8px;\n"
"        padding: 12px 0;\n"
"        font-size: 16px;\n"
"        font-weight: bold;\n"
"        min-width: 240px;\n"
"        min-height: 60px;\n"
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
"    /* \351\200\200\345\207\272\346\214\211\351\222\256\347\211\271\346\256\212\346\240\267\345\274\217 */\n"
"    #quitButton {\n"
"        background-color: #e74c3c;\n"
"        margin-top: 20px;\n"
"    }\n"
"\n"
"    #quitButton:hover {\n"
"        background-col"
                        "or: #c0392b;\n"
"    }\n"
"\n"
"    /* \346\214\211\351\222\256\345\256\271\345\231\250\346\240\267\345\274\217 */\n"
"    #buttonContainer {\n"
"        background-color: white;\n"
"        border-radius: 12px;\n"
"        padding: 30px;\n"
"        margin: 30px;\n"
"        box-shadow: 0 4px 8px rgba(0,0,0,0.1);\n"
"    }\n"
"\n"
"    /* \346\240\207\351\242\230\346\240\267\345\274\217 */\n"
"    #titleLabel {\n"
"        color: #2b5876;\n"
"        font-size: 24px;\n"
"        font-weight: bold;\n"
"        qproperty-alignment: AlignCenter;\n"
"        margin-bottom: 30px;\n"
"    }\n"
"\n"
"    /* \346\273\232\345\212\250\345\214\272\345\237\237\346\240\267\345\274\217 */\n"
"    QScrollArea {\n"
"        border: none;\n"
"        background: transparent;\n"
"    }\n"
"   "));
        scrollArea = new QScrollArea(PatientProfile);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 850, 900));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 850, 1200));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        buttonContainer = new QWidget(scrollAreaWidgetContents);
        buttonContainer->setObjectName(QString::fromUtf8("buttonContainer"));
        buttonContainer->setMinimumSize(QSize(0, 800));
        verticalLayout = new QVBoxLayout(buttonContainer);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(buttonContainer);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        verticalLayout->addWidget(titleLabel);

        scheduleButton = new QPushButton(buttonContainer);
        scheduleButton->setObjectName(QString::fromUtf8("scheduleButton"));

        verticalLayout->addWidget(scheduleButton);

        verticalSpacer_1 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_1);

        appointmentCaseButton = new QPushButton(buttonContainer);
        appointmentCaseButton->setObjectName(QString::fromUtf8("appointmentCaseButton"));

        verticalLayout->addWidget(appointmentCaseButton);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        profileButton = new QPushButton(buttonContainer);
        profileButton->setObjectName(QString::fromUtf8("profileButton"));

        verticalLayout->addWidget(profileButton);

        verticalSpacer_3 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        doctorButton = new QPushButton(buttonContainer);
        doctorButton->setObjectName(QString::fromUtf8("doctorButton"));

        verticalLayout->addWidget(doctorButton);

        verticalSpacer_4 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        healthButton = new QPushButton(buttonContainer);
        healthButton->setObjectName(QString::fromUtf8("healthButton"));

        verticalLayout->addWidget(healthButton);

        verticalSpacer_5 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        chatButton = new QPushButton(buttonContainer);
        chatButton->setObjectName(QString::fromUtf8("chatButton"));

        verticalLayout->addWidget(chatButton);

        verticalSpacer_6 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        quitButton = new QPushButton(buttonContainer);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        verticalLayout->addWidget(quitButton);

        verticalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);


        verticalLayout_2->addWidget(buttonContainer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(PatientProfile);

        QMetaObject::connectSlotsByName(PatientProfile);
    } // setupUi

    void retranslateUi(QWidget *PatientProfile)
    {
        PatientProfile->setWindowTitle(QApplication::translate("PatientProfile", "\346\202\243\350\200\205\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
        titleLabel->setText(QApplication::translate("PatientProfile", "\346\202\243\350\200\205\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
        scheduleButton->setText(QApplication::translate("PatientProfile", "\346\214\202\345\217\267\351\242\204\347\272\246", nullptr));
        appointmentCaseButton->setText(QApplication::translate("PatientProfile", "\346\237\245\347\234\213\347\227\205\345\216\206\344\270\216\345\244\204\346\226\271", nullptr));
        profileButton->setText(QApplication::translate("PatientProfile", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        doctorButton->setText(QApplication::translate("PatientProfile", "\346\237\245\347\234\213\345\214\273\347\224\237\344\277\241\346\201\257", nullptr));
        healthButton->setText(QApplication::translate("PatientProfile", "\345\201\245\345\272\267\350\257\204\344\274\260", nullptr));
        chatButton->setText(QApplication::translate("PatientProfile", "\345\214\273\346\202\243\346\262\237\351\200\232\345\271\263\345\217\260", nullptr));
        quitButton->setText(QApplication::translate("PatientProfile", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientProfile: public Ui_PatientProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTPROFILE_H
