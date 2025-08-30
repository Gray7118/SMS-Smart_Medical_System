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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doctorProfile
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *scheduleButton;
    QPushButton *appointmentCaseButton;
    QPushButton *profileButton;
    QPushButton *chatButton;
    QSpacerItem *verticalSpacer;
    QPushButton *quitButton;

    void setupUi(QWidget *doctorProfile)
    {
        if (doctorProfile->objectName().isEmpty())
            doctorProfile->setObjectName(QString::fromUtf8("doctorProfile"));
        doctorProfile->resize(627, 530);
        layoutWidget = new QWidget(doctorProfile);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 50, 202, 422));
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

        chatButton = new QPushButton(layoutWidget);
        chatButton->setObjectName(QString::fromUtf8("chatButton"));
        chatButton->setMinimumSize(QSize(200, 60));
        chatButton->setMaximumSize(QSize(200, 60));
        chatButton->setFont(font);

        verticalLayout->addWidget(chatButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        quitButton = new QPushButton(layoutWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setMinimumSize(QSize(200, 60));
        quitButton->setMaximumSize(QSize(200, 60));
        quitButton->setFont(font);

        verticalLayout->addWidget(quitButton);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 5);
        verticalLayout->setStretch(5, 1);

        retranslateUi(doctorProfile);

        QMetaObject::connectSlotsByName(doctorProfile);
    } // setupUi

    void retranslateUi(QWidget *doctorProfile)
    {
        doctorProfile->setWindowTitle(QApplication::translate("doctorProfile", "Form", nullptr));
        scheduleButton->setText(QApplication::translate("doctorProfile", "\346\237\245\347\234\213\346\211\200\346\234\211\346\214\202\345\217\267\345\222\214\347\227\205\344\276\213", nullptr));
        appointmentCaseButton->setText(QApplication::translate("doctorProfile", "\347\274\226\350\276\221\347\227\205\344\276\213\345\222\214\345\244\204\346\226\271", nullptr));
        profileButton->setText(QApplication::translate("doctorProfile", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        chatButton->setText(QApplication::translate("doctorProfile", "\345\214\273\346\202\243\346\262\237\351\200\232\345\271\263\345\217\260", nullptr));
        quitButton->setText(QApplication::translate("doctorProfile", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class doctorProfile: public Ui_doctorProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORPROFILE_H
