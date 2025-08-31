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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QWidget *chatContainer;
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QLabel *recerverLabel;
    QSpacerItem *verticalSpacer_1;
    QTextEdit *chatTextEdit;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *msgLineEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *buttonLayout;
    QPushButton *sendButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *returnButton;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(850, 1000);
        Chat->setMinimumSize(QSize(850, 1000));
        Chat->setStyleSheet(QString::fromUtf8("\n"
"    /* \344\270\273\347\252\227\345\217\243\346\240\267\345\274\217 */\n"
"    QWidget {\n"
"        background-color: #f0f5ff;\n"
"        font-family: 'Microsoft YaHei';\n"
"    }\n"
"\n"
"    /* \346\240\207\351\242\230\346\240\267\345\274\217 */\n"
"    #headerLabel {\n"
"        color: #1a3a5a;\n"
"        font-size: 24px;\n"
"        font-weight: bold;\n"
"        qproperty-alignment: AlignCenter;\n"
"    }\n"
"\n"
"    /* \350\201\212\345\244\251\346\230\276\347\244\272\345\214\272\345\237\237 */\n"
"    QTextEdit#chatTextEdit {\n"
"        background-color: white;\n"
"        border: 2px solid #c5d9f1;\n"
"        border-radius: 10px;\n"
"        padding: 15px;\n"
"        font-size: 16px;\n"
"        color: #333333;\n"
"        selection-background-color: #4a90e2;\n"
"        selection-color: white;\n"
"        min-height: 500px;\n"
"    }\n"
"\n"
"    /* \346\266\210\346\201\257\350\276\223\345\205\245\346\241\206 */\n"
"    QLineEdit#msgLineEdit {\n"
"        border: 2px solid #c5d9f1;\n"
"    "
                        "    border-radius: 10px;\n"
"        padding: 15px;\n"
"        font-size: 16px;\n"
"        color: #222222;\n"
"        background-color: white;\n"
"    }\n"
"\n"
"    QLineEdit#msgLineEdit:focus {\n"
"        border: 2px solid #4a90e2;\n"
"    }\n"
"\n"
"    /* \346\214\211\351\222\256\351\200\232\347\224\250\346\240\267\345\274\217 */\n"
"    QPushButton {\n"
"        background-color: #4a90e2;\n"
"        color: white;\n"
"        border: none;\n"
"        border-radius: 10px;\n"
"        padding: 14px 28px;\n"
"        font-size: 18px;\n"
"        font-weight: bold;\n"
"        min-width: 120px;\n"
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
"    /* \350\277\224\345\233\236\346\214\211\351\222\256\347\211\271\346\256\212\346\240\267\345\274\217 */\n"
"    #returnButton {\n"
"        background-color: #8a8a8a;\n"
"    }\n"
"\n"
"    #returnButton:hover {\n"
"        backg"
                        "round-color: #7a7a8a;\n"
"    }\n"
"\n"
"    /* \350\201\212\345\244\251\345\256\271\345\231\250\346\240\267\345\274\217 */\n"
"    #chatContainer {\n"
"        background-color: white;\n"
"        border-radius: 15px;\n"
"        padding: 25px;\n"
"        margin: 25px;\n"
"        box-shadow: 0 6px 12px rgba(0,0,0,0.12);\n"
"    }\n"
"   "));
        chatContainer = new QWidget(Chat);
        chatContainer->setObjectName(QString::fromUtf8("chatContainer"));
        chatContainer->setGeometry(QRect(50, 30, 750, 900));
        verticalLayout = new QVBoxLayout(chatContainer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        headerLabel = new QLabel(chatContainer);
        headerLabel->setObjectName(QString::fromUtf8("headerLabel"));

        verticalLayout->addWidget(headerLabel);

        recerverLabel = new QLabel(chatContainer);
        recerverLabel->setObjectName(QString::fromUtf8("recerverLabel"));
        recerverLabel->setStyleSheet(QString::fromUtf8("\n"
"        font-size: 18px;\n"
"        color: #444444;\n"
"        qproperty-alignment: AlignCenter;\n"
"       "));

        verticalLayout->addWidget(recerverLabel);

        verticalSpacer_1 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_1);

        chatTextEdit = new QTextEdit(chatContainer);
        chatTextEdit->setObjectName(QString::fromUtf8("chatTextEdit"));
        chatTextEdit->setLineWrapMode(QTextEdit::WidgetWidth);
        chatTextEdit->setReadOnly(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(chatTextEdit->sizePolicy().hasHeightForWidth());
        chatTextEdit->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(chatTextEdit);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        msgLineEdit = new QLineEdit(chatContainer);
        msgLineEdit->setObjectName(QString::fromUtf8("msgLineEdit"));

        verticalLayout->addWidget(msgLineEdit);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        sendButton = new QPushButton(chatContainer);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        buttonLayout->addWidget(sendButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        returnButton = new QPushButton(chatContainer);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setStyleSheet(QString::fromUtf8("#returnButton"));

        buttonLayout->addWidget(returnButton);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "\345\215\263\346\227\266\350\201\212\345\244\251\345\271\263\345\217\260", nullptr));
        headerLabel->setText(QApplication::translate("Chat", "\345\215\263\346\227\266\350\201\212\345\244\251\345\271\263\345\217\260", nullptr));
        recerverLabel->setText(QApplication::translate("Chat", "\346\202\250\346\255\243\345\234\250\345\222\214 xxx (xx) \346\262\237\351\200\232\357\274\232", nullptr));
        msgLineEdit->setPlaceholderText(QApplication::translate("Chat", "\350\257\267\350\276\223\345\205\245\346\266\210\346\201\257\345\206\205\345\256\271...", nullptr));
        sendButton->setText(QApplication::translate("Chat", "\345\217\221\351\200\201", nullptr));
        returnButton->setText(QApplication::translate("Chat", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
