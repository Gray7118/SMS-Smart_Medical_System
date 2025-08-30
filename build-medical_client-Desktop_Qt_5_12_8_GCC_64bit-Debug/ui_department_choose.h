/********************************************************************************
** Form generated from reading UI file 'department_choose.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENT_CHOOSE_H
#define UI_DEPARTMENT_CHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_department_choose
{
public:
    QComboBox *combo_d_choose;
    QLabel *label_d_choose;
    QPushButton *department_choose_return;
    QPushButton *department_choose_sure;
    QPushButton *department_choose_sure_2;

    void setupUi(QWidget *department_choose)
    {
        if (department_choose->objectName().isEmpty())
            department_choose->setObjectName(QString::fromUtf8("department_choose"));
        department_choose->resize(630, 484);
        combo_d_choose = new QComboBox(department_choose);
        combo_d_choose->setObjectName(QString::fromUtf8("combo_d_choose"));
        combo_d_choose->setGeometry(QRect(170, 130, 261, 51));
        label_d_choose = new QLabel(department_choose);
        label_d_choose->setObjectName(QString::fromUtf8("label_d_choose"));
        label_d_choose->setGeometry(QRect(250, 70, 201, 81));
        QFont font;
        font.setPointSize(15);
        label_d_choose->setFont(font);
        department_choose_return = new QPushButton(department_choose);
        department_choose_return->setObjectName(QString::fromUtf8("department_choose_return"));
        department_choose_return->setGeometry(QRect(20, 30, 121, 41));
        department_choose_sure = new QPushButton(department_choose);
        department_choose_sure->setObjectName(QString::fromUtf8("department_choose_sure"));
        department_choose_sure->setGeometry(QRect(60, 390, 221, 51));
        department_choose_sure_2 = new QPushButton(department_choose);
        department_choose_sure_2->setObjectName(QString::fromUtf8("department_choose_sure_2"));
        department_choose_sure_2->setGeometry(QRect(340, 390, 221, 51));

        retranslateUi(department_choose);

        QMetaObject::connectSlotsByName(department_choose);
    } // setupUi

    void retranslateUi(QWidget *department_choose)
    {
        department_choose->setWindowTitle(QApplication::translate("department_choose", "Form", nullptr));
        label_d_choose->setText(QApplication::translate("department_choose", "\351\200\211\346\213\251\347\247\221\345\256\244", nullptr));
        department_choose_return->setText(QApplication::translate("department_choose", "\350\277\224\345\233\236", nullptr));
        department_choose_sure->setText(QApplication::translate("department_choose", "\346\214\211\346\216\222\347\217\255\346\227\266\351\227\264\346\243\200\347\264\242", nullptr));
        department_choose_sure_2->setText(QApplication::translate("department_choose", "\346\214\211\345\214\273\347\224\237\346\243\200\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class department_choose: public Ui_department_choose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENT_CHOOSE_H
