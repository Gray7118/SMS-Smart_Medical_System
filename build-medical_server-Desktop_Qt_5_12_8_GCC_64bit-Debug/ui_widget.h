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
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *textEdit;
    QLabel *label;
    QTextEdit *allUserTextEdit;
    QLabel *label_2;
    QTextEdit *allDoctorTextEdit;
    QLabel *label_3;
    QTextEdit *allPatientTextEdit;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *allCaseTextEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1409, 1150);
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 80, 571, 201));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 511, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        label->setFont(font);
        allUserTextEdit = new QTextEdit(Widget);
        allUserTextEdit->setObjectName(QString::fromUtf8("allUserTextEdit"));
        allUserTextEdit->setGeometry(QRect(40, 400, 561, 161));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 330, 511, 51));
        label_2->setFont(font);
        allDoctorTextEdit = new QTextEdit(Widget);
        allDoctorTextEdit->setObjectName(QString::fromUtf8("allDoctorTextEdit"));
        allDoctorTextEdit->setGeometry(QRect(40, 670, 561, 161));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 600, 511, 51));
        label_3->setFont(font);
        allPatientTextEdit = new QTextEdit(Widget);
        allPatientTextEdit->setObjectName(QString::fromUtf8("allPatientTextEdit"));
        allPatientTextEdit->setGeometry(QRect(40, 940, 561, 161));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 870, 511, 51));
        label_4->setFont(font);
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(740, 10, 511, 51));
        label_5->setFont(font);
        allCaseTextEdit = new QTextEdit(Widget);
        allCaseTextEdit->setObjectName(QString::fromUtf8("allCaseTextEdit"));
        allCaseTextEdit->setGeometry(QRect(740, 80, 571, 441));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\347\275\221\347\273\234\350\277\236\346\216\245\344\277\241\346\201\257", nullptr));
        label_2->setText(QApplication::translate("Widget", "\346\211\200\346\234\211\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        label_3->setText(QApplication::translate("Widget", "\346\211\200\346\234\211\345\214\273\347\224\237\344\277\241\346\201\257", nullptr));
        label_4->setText(QApplication::translate("Widget", "\346\211\200\346\234\211\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        label_5->setText(QApplication::translate("Widget", "\346\211\200\346\234\211\347\227\205\344\276\213\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
