/********************************************************************************
** Form generated from reading UI file 'chatmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATMAINWINDOW_H
#define UI_CHATMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatMainWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *contactListWidget;
    QWidget *chatContainer;
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QSpacerItem *verticalSpacer_1;
    QLabel *currentChatLabel;
    QSpacerItem *verticalSpacer_0;
    QTextEdit *chatTextEdit;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *msgLineEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *buttonLayout;
    QPushButton *sendButton;
    QSpacerItem *horizontalSpacer_1;
    QPushButton *videoCallButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *returnButton;

    void setupUi(QWidget *ChatMainWindow)
    {
        if (ChatMainWindow->objectName().isEmpty())
            ChatMainWindow->setObjectName(QString::fromUtf8("ChatMainWindow"));
        ChatMainWindow->resize(1200, 800);
        ChatMainWindow->setMinimumSize(QSize(1200, 800));
        ChatMainWindow->setStyleSheet(QString::fromUtf8("/* \344\270\273\347\252\227\345\217\243\346\270\220\345\217\230\350\203\214\346\231\257 */\n"
"QWidget#ChatMainWindow {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #d0f0ff,\n"
"        stop:1 #ffffff\n"
"    );\n"
"}\n"
"\n"
"/* \346\240\207\351\242\230\346\240\267\345\274\217 */\n"
"#headerLabel {\n"
"    color: #1e88e5;\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    text-shadow: 1px 1px 3px #81d4fa;\n"
"    qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"/* \345\275\223\345\211\215\350\201\212\345\244\251\346\240\207\347\255\276 */\n"
"#currentChatLabel {\n"
"    color: #1e88e5;\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background-color: rgba(255, 255, 255, 0.8);\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"    margin: 10px;\n"
"}\n"
"\n"
"/* \350\201\224\347\263\273\344\272\272\345\210\227\350\241\250\346\240\267\345\274\217 */\n"
"QListWidget#contactListWidget {\n"
"   "
                        " background-color: rgba(255, 255, 255, 0.9);\n"
"    border: 2px solid #81d4fa;\n"
"    border-radius: 12px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    color: #0f1f38;\n"
"    outline: none;\n"
"}\n"
"\n"
"QListWidget#contactListWidget::item {\n"
"    padding: 12px;\n"
"    border-bottom: 1px solid #e3f2fd;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QListWidget#contactListWidget::item:selected {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #6ec6ff,\n"
"        stop:1 #1e88e5\n"
"    );\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QListWidget#contactListWidget::item:hover {\n"
"    background-color: #e3f2fd;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"/* \350\201\212\345\244\251\346\230\276\347\244\272\345\214\272\345\237\237 */\n"
"QTextEdit#chatTextEdit {\n"
"    background-color: rgba(255, 255, 255, 0.95);\n"
"    border: 2px solid #81d4fa;\n"
"    border-radius: 12px;\n"
"    padding: 15px;\n"
"    font-size: 14p"
                        "x;\n"
"    color: #0f1f38;\n"
"    selection-background-color: #4fc3f7;\n"
"    selection-color: #ffffff;\n"
"    min-height: 450px;\n"
"}\n"
"\n"
"/* \346\266\210\346\201\257\350\276\223\345\205\245\346\241\206 */\n"
"QLineEdit#msgLineEdit {\n"
"    border: 2px solid #81d4fa;\n"
"    border-radius: 12px;\n"
"    padding: 12px;\n"
"    font-size: 14px;\n"
"    background-color: #ffffff;\n"
"    color: #0f1f38;\n"
"    selection-background-color: #4fc3f7;\n"
"    selection-color: #ffffff;\n"
"}\n"
"\n"
"QLineEdit#msgLineEdit:focus {\n"
"    border: 2px solid #1e88e5;\n"
"}\n"
"\n"
"QLineEdit#msgLineEdit:disabled {\n"
"    background-color: #f5f5f5;\n"
"    color: #9e9e9e;\n"
"}\n"
"\n"
"/* \346\214\211\351\222\256\351\253\230\347\272\247\346\270\220\345\217\230\347\247\221\346\212\200\351\243\216 */\n"
"QPushButton {\n"
"    border-radius: 14px;\n"
"    border: 1px solid #64b5f6;\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"    font-size: 16px;\n"
"    padding: 12px 24px;\n"
"    background-color: qli"
                        "neargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #6ec6ff,\n"
"        stop:1 #1e88e5\n"
"    );\n"
"    text-shadow: 1px 1px 2px rgba(0,0,0,0.2);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #81d4fa,\n"
"        stop:1 #1976d2\n"
"    );\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #1e88e5,\n"
"        stop:1 #1565c0\n"
"    );\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #bdbdbd;\n"
"    border-color: #9e9e9e;\n"
"    color: #757575;\n"
"}\n"
"\n"
"/* \350\247\206\351\242\221\351\200\232\350\257\235\346\214\211\351\222\256\347\211\271\346\256\212\346\240\267\345\274\217 */\n"
"#videoCallButton {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #4caf50,\n"
"        stop:1 #2e7d32\n"
"    );\n"
"    border-color: #66bb6a;\n"
"}\n"
"\n"
"#videoCallBut"
                        "ton:hover {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #66bb6a,\n"
"        stop:1 #1b5e20\n"
"    );\n"
"}\n"
"\n"
"/* \350\277\224\345\233\236\346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"#returnButton {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #ff7f7f,\n"
"        stop:1 #e53935\n"
"    );\n"
"    border-color: #e57373;\n"
"}\n"
"\n"
"#returnButton:hover {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #ff8a80,\n"
"        stop:1 #f44336\n"
"    );\n"
"}\n"
"\n"
"/* \350\201\212\345\244\251\345\256\271\345\231\250\346\240\267\345\274\217 */\n"
"#chatContainer {\n"
"    background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 18px;\n"
"    padding: 25px;\n"
"    margin: 20px;\n"
"    border: 1px solid #bbdefb;\n"
"}\n"
"\n"
"/* \345\210\206\345\211\262\347\272\277\346\240\267\345\274\217 */\n"
"QSplitter::handle {\n"
"    backgr"
                        "ound-color: #bbdefb;\n"
"    width: 2px;\n"
"}\n"
"\n"
"/* \346\273\232\345\212\250\346\235\241\346\240\267\345\274\217 */\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #e3f2fd;\n"
"    width: 10px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #64b5f6;\n"
"    border-radius: 5px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #1e88e5;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(ChatMainWindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        contactListWidget = new QListWidget(ChatMainWindow);
        contactListWidget->setObjectName(QString::fromUtf8("contactListWidget"));
        contactListWidget->setMinimumSize(QSize(250, 0));
        contactListWidget->setMaximumSize(QSize(300, 16777215));

        horizontalLayout->addWidget(contactListWidget);

        chatContainer = new QWidget(ChatMainWindow);
        chatContainer->setObjectName(QString::fromUtf8("chatContainer"));
        verticalLayout = new QVBoxLayout(chatContainer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        headerLabel = new QLabel(chatContainer);
        headerLabel->setObjectName(QString::fromUtf8("headerLabel"));

        verticalLayout->addWidget(headerLabel);

        verticalSpacer_1 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_1);

        currentChatLabel = new QLabel(chatContainer);
        currentChatLabel->setObjectName(QString::fromUtf8("currentChatLabel"));

        verticalLayout->addWidget(currentChatLabel);

        verticalSpacer_0 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_0);

        chatTextEdit = new QTextEdit(chatContainer);
        chatTextEdit->setObjectName(QString::fromUtf8("chatTextEdit"));
        chatTextEdit->setReadOnly(true);

        verticalLayout->addWidget(chatTextEdit);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        msgLineEdit = new QLineEdit(chatContainer);
        msgLineEdit->setObjectName(QString::fromUtf8("msgLineEdit"));

        verticalLayout->addWidget(msgLineEdit);

        verticalSpacer_3 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        sendButton = new QPushButton(chatContainer);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        buttonLayout->addWidget(sendButton);

        horizontalSpacer_1 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_1);

        videoCallButton = new QPushButton(chatContainer);
        videoCallButton->setObjectName(QString::fromUtf8("videoCallButton"));

        buttonLayout->addWidget(videoCallButton);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_2);

        returnButton = new QPushButton(chatContainer);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));

        buttonLayout->addWidget(returnButton);


        verticalLayout->addLayout(buttonLayout);


        horizontalLayout->addWidget(chatContainer);


        retranslateUi(ChatMainWindow);

        QMetaObject::connectSlotsByName(ChatMainWindow);
    } // setupUi

    void retranslateUi(QWidget *ChatMainWindow)
    {
        ChatMainWindow->setWindowTitle(QApplication::translate("ChatMainWindow", "\345\257\260\345\256\207\345\214\273\346\241\245 - \345\214\273\346\202\243\346\262\237\351\200\232\345\271\263\345\217\260", nullptr));
        headerLabel->setText(QApplication::translate("ChatMainWindow", "\345\257\260\345\256\207\345\214\273\346\241\245 - \345\214\273\346\202\243\346\262\237\351\200\232\345\271\263\345\217\260", nullptr));
        currentChatLabel->setText(QApplication::translate("ChatMainWindow", "\345\275\223\345\211\215\350\201\212\345\244\251\357\274\232\346\235\216\345\214\273\347\224\237", nullptr));
        msgLineEdit->setPlaceholderText(QApplication::translate("ChatMainWindow", "\350\257\267\350\276\223\345\205\245\346\266\210\346\201\257\345\206\205\345\256\271...", nullptr));
        sendButton->setText(QApplication::translate("ChatMainWindow", "\345\217\221\351\200\201", nullptr));
        videoCallButton->setText(QApplication::translate("ChatMainWindow", "\350\247\206\351\242\221\351\200\232\350\257\235", nullptr));
        returnButton->setText(QApplication::translate("ChatMainWindow", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatMainWindow: public Ui_ChatMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATMAINWINDOW_H
