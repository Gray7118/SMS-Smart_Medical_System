/********************************************************************************
** Form generated from reading UI file 'patientcase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTCASE_H
#define UI_PATIENTCASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_patientcase
{
public:
    QTextEdit *seecase;
    QPushButton *patientcase_sure;
    QLabel *label_seecase;
    QPushButton *patientcase_return;

    void setupUi(QWidget *patientcase)
    {
        if (patientcase->objectName().isEmpty())
            patientcase->setObjectName(QString::fromUtf8("patientcase"));
        patientcase->resize(641, 537);
        seecase = new QTextEdit(patientcase);
        seecase->setObjectName(QString::fromUtf8("seecase"));
        seecase->setGeometry(QRect(40, 70, 541, 331));
        patientcase_sure = new QPushButton(patientcase);
        patientcase_sure->setObjectName(QString::fromUtf8("patientcase_sure"));
        patientcase_sure->setGeometry(QRect(110, 420, 131, 51));
        label_seecase = new QLabel(patientcase);
        label_seecase->setObjectName(QString::fromUtf8("label_seecase"));
        label_seecase->setGeometry(QRect(280, 10, 171, 51));
        QFont font;
        font.setPointSize(13);
        label_seecase->setFont(font);
        patientcase_return = new QPushButton(patientcase);
        patientcase_return->setObjectName(QString::fromUtf8("patientcase_return"));
        patientcase_return->setGeometry(QRect(380, 420, 131, 51));

        retranslateUi(patientcase);

        QMetaObject::connectSlotsByName(patientcase);
    } // setupUi

    void retranslateUi(QWidget *patientcase)
    {
        patientcase->setWindowTitle(QApplication::translate("patientcase", "Form", nullptr));
        patientcase_sure->setText(QApplication::translate("patientcase", "\346\237\245\347\234\213\347\227\205\345\216\206", nullptr));
        label_seecase->setText(QApplication::translate("patientcase", "\346\237\245\347\234\213\347\227\205\345\216\206", nullptr));
        patientcase_return->setText(QApplication::translate("patientcase", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class patientcase: public Ui_patientcase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTCASE_H
