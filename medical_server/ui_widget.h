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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *mainLayout;
    QLabel *titleLabel;
    QHBoxLayout *contentLayout;
    QGroupBox *leftGroupBox;
    QVBoxLayout *leftLayout;
    QLabel *networkInfoLabel;
    QTextEdit *textEdit;
    QSpacerItem *verticalSpacer_1;
    QLabel *allUserLabel;
    QTextEdit *allUserTextEdit;
    QGroupBox *rightGroupBox;
    QVBoxLayout *rightLayout;
    QLabel *allDoctorLabel;
    QTextEdit *allDoctorTextEdit;
    QSpacerItem *verticalSpacer_2;
    QLabel *allPatientLabel;
    QTextEdit *allPatientTextEdit;
    QGroupBox *caseGroupBox;
    QVBoxLayout *caseLayout;
    QLabel *allCaseLabel;
    QTextEdit *allCaseTextEdit;
    QLabel *statusBar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1200, 900);
        Widget->setMinimumSize(QSize(1000, 800));
        Widget->setStyleSheet(QString::fromUtf8("\n"
"    /* \344\270\273\347\252\227\345\217\243\346\240\267\345\274\217 */\n"
"    QWidget {\n"
"        background-color: #f0f5ff;\n"
"        font-family: 'Microsoft YaHei';\n"
"    }\n"
"\n"
"    /* \351\235\242\346\235\277\346\240\267\345\274\217 */\n"
"    QGroupBox {\n"
"        background-color: white;\n"
"        border: 1px solid #d1e3f8;\n"
"        border-radius: 8px;\n"
"        padding: 15px;\n"
"        margin-top: 10px;\n"
"    }\n"
"\n"
"    QGroupBox::title {\n"
"        subcontrol-origin: margin;\n"
"        left: 10px;\n"
"        padding: 0 3px;\n"
"        color: #2b5876;\n"
"        font-weight: bold;\n"
"        font-size: 14px;\n"
"    }\n"
"\n"
"    /* \346\240\207\347\255\276\346\240\267\345\274\217 */\n"
"    QLabel {\n"
"        color: #2b5876;\n"
"        font-size: 14px;\n"
"        font-weight: bold;\n"
"        margin-bottom: 5px;\n"
"    }\n"
"\n"
"    /* \346\226\207\346\234\254\347\274\226\350\276\221\346\241\206\346\240\267\345\274\217 */\n"
"    QTextEdit {\n"
"        bac"
                        "kground-color: white;\n"
"        border: 1px solid #d1e3f8;\n"
"        border-radius: 6px;\n"
"        padding: 10px;\n"
"        font-size: 13px;\n"
"        color: #333333;\n"
"        selection-background-color: #4a90e2;\n"
"        selection-color: white;\n"
"    }\n"
"\n"
"    /* \347\212\266\346\200\201\346\240\217\346\240\267\345\274\217 */\n"
"    QLabel#statusBar {\n"
"        background-color: #e6f0ff;\n"
"        border-top: 1px solid #d1e3f8;\n"
"        padding: 8px;\n"
"        font-size: 12px;\n"
"    }\n"
"   "));
        mainLayout = new QVBoxLayout(Widget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        titleLabel = new QLabel(Widget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setStyleSheet(QString::fromUtf8("\n"
"       font-size: 18px;\n"
"       font-weight: bold;\n"
"       color: #2b5876;\n"
"       qproperty-alignment: AlignCenter;\n"
"       margin-bottom: 15px;\n"
"      "));

        mainLayout->addWidget(titleLabel);

        contentLayout = new QHBoxLayout();
        contentLayout->setObjectName(QString::fromUtf8("contentLayout"));
        leftGroupBox = new QGroupBox(Widget);
        leftGroupBox->setObjectName(QString::fromUtf8("leftGroupBox"));
        leftLayout = new QVBoxLayout(leftGroupBox);
        leftLayout->setObjectName(QString::fromUtf8("leftLayout"));
        networkInfoLabel = new QLabel(leftGroupBox);
        networkInfoLabel->setObjectName(QString::fromUtf8("networkInfoLabel"));

        leftLayout->addWidget(networkInfoLabel);

        textEdit = new QTextEdit(leftGroupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(0, 180));
        textEdit->setReadOnly(true);

        leftLayout->addWidget(textEdit);

        verticalSpacer_1 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        leftLayout->addItem(verticalSpacer_1);

        allUserLabel = new QLabel(leftGroupBox);
        allUserLabel->setObjectName(QString::fromUtf8("allUserLabel"));

        leftLayout->addWidget(allUserLabel);

        allUserTextEdit = new QTextEdit(leftGroupBox);
        allUserTextEdit->setObjectName(QString::fromUtf8("allUserTextEdit"));
        allUserTextEdit->setMinimumSize(QSize(0, 150));
        allUserTextEdit->setReadOnly(true);

        leftLayout->addWidget(allUserTextEdit);


        contentLayout->addWidget(leftGroupBox);

        rightGroupBox = new QGroupBox(Widget);
        rightGroupBox->setObjectName(QString::fromUtf8("rightGroupBox"));
        rightLayout = new QVBoxLayout(rightGroupBox);
        rightLayout->setObjectName(QString::fromUtf8("rightLayout"));
        allDoctorLabel = new QLabel(rightGroupBox);
        allDoctorLabel->setObjectName(QString::fromUtf8("allDoctorLabel"));

        rightLayout->addWidget(allDoctorLabel);

        allDoctorTextEdit = new QTextEdit(rightGroupBox);
        allDoctorTextEdit->setObjectName(QString::fromUtf8("allDoctorTextEdit"));
        allDoctorTextEdit->setMinimumSize(QSize(0, 200));
        allDoctorTextEdit->setReadOnly(true);

        rightLayout->addWidget(allDoctorTextEdit);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        rightLayout->addItem(verticalSpacer_2);

        allPatientLabel = new QLabel(rightGroupBox);
        allPatientLabel->setObjectName(QString::fromUtf8("allPatientLabel"));

        rightLayout->addWidget(allPatientLabel);

        allPatientTextEdit = new QTextEdit(rightGroupBox);
        allPatientTextEdit->setObjectName(QString::fromUtf8("allPatientTextEdit"));
        allPatientTextEdit->setMinimumSize(QSize(0, 200));
        allPatientTextEdit->setReadOnly(true);

        rightLayout->addWidget(allPatientTextEdit);


        contentLayout->addWidget(rightGroupBox);

        caseGroupBox = new QGroupBox(Widget);
        caseGroupBox->setObjectName(QString::fromUtf8("caseGroupBox"));
        caseLayout = new QVBoxLayout(caseGroupBox);
        caseLayout->setObjectName(QString::fromUtf8("caseLayout"));
        allCaseLabel = new QLabel(caseGroupBox);
        allCaseLabel->setObjectName(QString::fromUtf8("allCaseLabel"));

        caseLayout->addWidget(allCaseLabel);

        allCaseTextEdit = new QTextEdit(caseGroupBox);
        allCaseTextEdit->setObjectName(QString::fromUtf8("allCaseTextEdit"));
        allCaseTextEdit->setMinimumSize(QSize(0, 500));
        allCaseTextEdit->setReadOnly(true);

        caseLayout->addWidget(allCaseTextEdit);


        contentLayout->addWidget(caseGroupBox);


        mainLayout->addLayout(contentLayout);

        statusBar = new QLabel(Widget);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));

        mainLayout->addWidget(statusBar);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\345\214\273\347\226\227\344\277\241\346\201\257\347\233\221\346\216\247\345\271\263\345\217\260", nullptr));
        titleLabel->setText(QApplication::translate("Widget", "\345\214\273\347\226\227\344\277\241\346\201\257\347\233\221\346\216\247\345\271\263\345\217\260", nullptr));
        leftGroupBox->setTitle(QApplication::translate("Widget", "\347\263\273\347\273\237\344\277\241\346\201\257", nullptr));
        networkInfoLabel->setText(QApplication::translate("Widget", "\347\275\221\347\273\234\350\277\236\346\216\245\344\277\241\346\201\257", nullptr));
        allUserLabel->setText(QApplication::translate("Widget", "\346\211\200\346\234\211\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        rightGroupBox->setTitle(QApplication::translate("Widget", "\345\214\273\347\226\227\346\225\260\346\215\256", nullptr));
        allDoctorLabel->setText(QApplication::translate("Widget", "\346\211\200\346\234\211\345\214\273\347\224\237\344\277\241\346\201\257", nullptr));
        allPatientLabel->setText(QApplication::translate("Widget", "\346\211\200\346\234\211\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        caseGroupBox->setTitle(QApplication::translate("Widget", "\347\227\205\344\276\213\344\277\241\346\201\257", nullptr));
        allCaseLabel->setText(QApplication::translate("Widget", "\346\211\200\346\234\211\347\227\205\344\276\213\344\277\241\346\201\257", nullptr));
        statusBar->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250\350\277\220\350\241\214\344\270\255 | IP: 127.0.0.1 | \347\253\257\345\217\243: 8888 | \345\234\250\347\272\277\347\224\250\346\210\267: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
