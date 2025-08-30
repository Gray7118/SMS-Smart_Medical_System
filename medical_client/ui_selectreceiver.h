/********************************************************************************
** Form generated from reading UI file 'selectreceiver.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTRECEIVER_H
#define UI_SELECTRECEIVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectReceiver
{
public:
    QTextEdit *receiverTextEdit;
    QLabel *Label1;
    QLabel *Label2;
    QLineEdit *msgLineEdit;
    QPushButton *confirmButton;
    QPushButton *quitButton;
    QComboBox *receiverComboBox;
    QLabel *Label1_2;

    void setupUi(QWidget *SelectReceiver)
    {
        if (SelectReceiver->objectName().isEmpty())
            SelectReceiver->setObjectName(QString::fromUtf8("SelectReceiver"));
        SelectReceiver->resize(636, 535);
        receiverTextEdit = new QTextEdit(SelectReceiver);
        receiverTextEdit->setObjectName(QString::fromUtf8("receiverTextEdit"));
        receiverTextEdit->setGeometry(QRect(60, 60, 511, 151));
        Label1 = new QLabel(SelectReceiver);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(60, 30, 501, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        Label1->setFont(font);
        Label2 = new QLabel(SelectReceiver);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(60, 320, 411, 31));
        Label2->setFont(font);
        msgLineEdit = new QLineEdit(SelectReceiver);
        msgLineEdit->setObjectName(QString::fromUtf8("msgLineEdit"));
        msgLineEdit->setGeometry(QRect(60, 360, 511, 41));
        confirmButton = new QPushButton(SelectReceiver);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(140, 440, 100, 50));
        confirmButton->setMinimumSize(QSize(100, 50));
        confirmButton->setMaximumSize(QSize(100, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        confirmButton->setFont(font1);
        quitButton = new QPushButton(SelectReceiver);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(370, 440, 100, 50));
        quitButton->setMinimumSize(QSize(100, 50));
        quitButton->setMaximumSize(QSize(100, 50));
        quitButton->setFont(font1);
        receiverComboBox = new QComboBox(SelectReceiver);
        receiverComboBox->setObjectName(QString::fromUtf8("receiverComboBox"));
        receiverComboBox->setGeometry(QRect(340, 240, 231, 51));
        Label1_2 = new QLabel(SelectReceiver);
        Label1_2->setObjectName(QString::fromUtf8("Label1_2"));
        Label1_2->setGeometry(QRect(60, 250, 311, 31));
        Label1_2->setFont(font);

        retranslateUi(SelectReceiver);

        QMetaObject::connectSlotsByName(SelectReceiver);
    } // setupUi

    void retranslateUi(QWidget *SelectReceiver)
    {
        SelectReceiver->setWindowTitle(QApplication::translate("SelectReceiver", "Form", nullptr));
        Label1->setText(QApplication::translate("SelectReceiver", "<html><head/><body><p><span style=\" font-weight:600;\">\344\273\245\344\270\213\346\230\257\346\202\250\345\217\257\344\273\245\350\201\224\347\263\273\347\232\204\347\224\250\346\210\267\357\274\232</span></p></body></html>", nullptr));
        Label2->setText(QApplication::translate("SelectReceiver", "<html><head/><body><p><span style=\" font-weight:600;\">\350\257\267\350\276\223\345\205\245\346\202\250\346\203\263\350\246\201\350\201\224\347\263\273\347\232\204\345\257\271\350\261\241\357\274\232</span></p></body></html>", nullptr));
        msgLineEdit->setPlaceholderText(QApplication::translate("SelectReceiver", "\350\257\267\350\276\223\345\205\245\346\202\250\346\203\263\350\246\201\350\201\224\347\263\273\347\232\204\345\257\271\350\261\241", nullptr));
        confirmButton->setText(QApplication::translate("SelectReceiver", "\347\241\256\345\256\232", nullptr));
        quitButton->setText(QApplication::translate("SelectReceiver", "\345\217\226\346\266\210", nullptr));
        Label1_2->setText(QApplication::translate("SelectReceiver", "<html><head/><body><p><span style=\" font-weight:600;\">\346\202\250\344\271\237\345\217\257\344\273\245\345\234\250\350\277\231\351\207\214\351\200\211\346\213\251\357\274\232</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectReceiver: public Ui_SelectReceiver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTRECEIVER_H
