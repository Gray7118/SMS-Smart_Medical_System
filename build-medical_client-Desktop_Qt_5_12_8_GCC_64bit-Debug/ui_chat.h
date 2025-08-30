/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QLineEdit *msgLineEdit;
    QPushButton *sendButton;
    QPushButton *returnButton;
    QTextEdit *chatTextEdit;
    QLabel *recerverLabel;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(636, 875);
        msgLineEdit = new QLineEdit(Chat);
        msgLineEdit->setObjectName(QString::fromUtf8("msgLineEdit"));
        msgLineEdit->setGeometry(QRect(40, 720, 561, 51));
        sendButton = new QPushButton(Chat);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(330, 790, 100, 50));
        sendButton->setMinimumSize(QSize(100, 50));
        sendButton->setMaximumSize(QSize(100, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        sendButton->setFont(font);
        returnButton = new QPushButton(Chat);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(500, 790, 100, 50));
        returnButton->setMinimumSize(QSize(100, 50));
        returnButton->setMaximumSize(QSize(100, 50));
        returnButton->setFont(font);
        chatTextEdit = new QTextEdit(Chat);
        chatTextEdit->setObjectName(QString::fromUtf8("chatTextEdit"));
        chatTextEdit->setGeometry(QRect(50, 80, 531, 601));
        recerverLabel = new QLabel(Chat);
        recerverLabel->setObjectName(QString::fromUtf8("recerverLabel"));
        recerverLabel->setGeometry(QRect(50, 30, 481, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        recerverLabel->setFont(font1);

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Form", nullptr));
        msgLineEdit->setText(QString());
        msgLineEdit->setPlaceholderText(QApplication::translate("Chat", "\350\257\267\350\276\223\345\205\245", nullptr));
        sendButton->setText(QApplication::translate("Chat", "\345\217\221\351\200\201", nullptr));
        returnButton->setText(QApplication::translate("Chat", "\350\277\224\345\233\236", nullptr));
        recerverLabel->setText(QApplication::translate("Chat", "<html><head/><body><p><span style=\" font-weight:600;\">\346\202\250\346\255\243\345\234\250\345\222\214 xxx (xx) \346\262\237\351\200\232\357\274\232</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
