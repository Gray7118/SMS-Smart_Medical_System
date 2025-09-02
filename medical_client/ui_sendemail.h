/********************************************************************************
** Form generated from reading UI file 'sendemail.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDEMAIL_H
#define UI_SENDEMAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SendEmail
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *host;
    QLabel *label_2;
    QSpinBox *port;
    QCheckBox *ssl;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QCheckBox *auth;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *username;
    QLabel *label_6;
    QLineEdit *password;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLineEdit *sender;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QLineEdit *recipients;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    QLineEdit *subject;
    QTextEdit *texteditor;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QPushButton *addAttachment;
    QListWidget *attachments;
    QPushButton *sendEmail;

    void setupUi(QWidget *SendEmail)
    {
        if (SendEmail->objectName().isEmpty())
            SendEmail->setObjectName(QString::fromUtf8("SendEmail"));
        SendEmail->resize(710, 616);
        SendEmail->setStyleSheet(QString::fromUtf8("\n"
"    /* \344\270\273\347\252\227\345\217\243\346\270\220\345\217\230\350\203\214\346\231\257 */\n"
"    QWidget#SendEmail {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #d0f0ff,\n"
"            stop:1 #ffffff\n"
"        );\n"
"    }\n"
"\n"
"    /* \346\214\211\351\222\256\351\253\230\347\272\247\346\270\220\345\217\230\347\247\221\346\212\200\351\243\216 */\n"
"    QPushButton {\n"
"        border-radius: 14px;\n"
"        border: 1px solid #64b5f6;\n"
"        color: #ffffff;\n"
"        font-weight: bold;\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #6ec6ff,\n"
"            stop:1 #1e88e5\n"
"        );\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #81d4fa,\n"
"            stop:1 #1976d2\n"
"        );\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: qli"
                        "neargradient(\n"
"            x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #1e88e5,\n"
"            stop:1 #1565c0\n"
"        );\n"
"    }\n"
"\n"
"    /* \350\276\223\345\205\245\346\241\206\346\240\267\345\274\217 */\n"
"    QLineEdit {\n"
"        border: 2px solid #81d4fa;\n"
"        border-radius: 12px;\n"
"        padding: 10px;\n"
"        background-color: #ffffff;\n"
"        color: #0f1f38;\n"
"        selection-background-color: #4fc3f7;\n"
"        selection-color: #ffffff;\n"
"    }\n"
"    QLineEdit:focus {\n"
"        border: 2px solid #1e88e5;\n"
"    }\n"
"\n"
"    /* \345\244\232\350\241\214\346\226\207\346\234\254\346\241\206 */\n"
"    QTextEdit, QTextBrowser {\n"
"        border: 2px solid #81d4fa;\n"
"        border-radius: 12px;\n"
"        padding: 8px;\n"
"        background-color: #ffffff;\n"
"        color: #0f1f38;\n"
"    }\n"
"\n"
"    /* \345\210\227\350\241\250\346\216\247\344\273\266 */\n"
"    QListWidget {\n"
"        border: 2px solid #81d4fa;\n"
"        border-radius: "
                        "12px;\n"
"        padding: 5px;\n"
"        background-color: #ffffff;\n"
"        color: #0f1f38;\n"
"    }\n"
"\n"
"    /* \345\244\215\351\200\211\346\241\206\347\273\237\344\270\200\346\240\267\345\274\217 */\n"
"    QCheckBox {\n"
"        spacing: 5px;\n"
"    }\n"
"   "));
        verticalLayout_2 = new QVBoxLayout(SendEmail);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(SendEmail);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(221, 17));
        label->setMaximumSize(QSize(300, 17));

        horizontalLayout->addWidget(label);

        host = new QLineEdit(SendEmail);
        host->setObjectName(QString::fromUtf8("host"));

        horizontalLayout->addWidget(host);

        label_2 = new QLabel(SendEmail);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(91, 17));
        label_2->setMaximumSize(QSize(200, 17));

        horizontalLayout->addWidget(label_2);

        port = new QSpinBox(SendEmail);
        port->setObjectName(QString::fromUtf8("port"));
        port->setMaximum(99999);

        horizontalLayout->addWidget(port);

        ssl = new QCheckBox(SendEmail);
        ssl->setObjectName(QString::fromUtf8("ssl"));

        horizontalLayout->addWidget(ssl);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(SendEmail);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        auth = new QCheckBox(SendEmail);
        auth->setObjectName(QString::fromUtf8("auth"));

        horizontalLayout_3->addWidget(auth);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(SendEmail);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        username = new QLineEdit(SendEmail);
        username->setObjectName(QString::fromUtf8("username"));

        horizontalLayout_4->addWidget(username);

        label_6 = new QLabel(SendEmail);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        password = new QLineEdit(SendEmail);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(password);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_7 = new QLabel(SendEmail);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);

        verticalLayout_2->addWidget(label_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(SendEmail);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        sender = new QLineEdit(SendEmail);
        sender->setObjectName(QString::fromUtf8("sender"));

        horizontalLayout_2->addWidget(sender);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_9 = new QLabel(SendEmail);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_5->addWidget(label_9);

        recipients = new QLineEdit(SendEmail);
        recipients->setObjectName(QString::fromUtf8("recipients"));

        horizontalLayout_5->addWidget(recipients);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_10 = new QLabel(SendEmail);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_6->addWidget(label_10);

        subject = new QLineEdit(SendEmail);
        subject->setObjectName(QString::fromUtf8("subject"));

        horizontalLayout_6->addWidget(subject);


        verticalLayout_2->addLayout(horizontalLayout_6);

        texteditor = new QTextEdit(SendEmail);
        texteditor->setObjectName(QString::fromUtf8("texteditor"));

        verticalLayout_2->addWidget(texteditor);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(SendEmail);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_7->addWidget(label_3);

        addAttachment = new QPushButton(SendEmail);
        addAttachment->setObjectName(QString::fromUtf8("addAttachment"));

        horizontalLayout_7->addWidget(addAttachment);


        verticalLayout->addLayout(horizontalLayout_7);

        attachments = new QListWidget(SendEmail);
        attachments->setObjectName(QString::fromUtf8("attachments"));
        attachments->setMaximumSize(QSize(16777215, 64));

        verticalLayout->addWidget(attachments);


        verticalLayout_2->addLayout(verticalLayout);

        sendEmail = new QPushButton(SendEmail);
        sendEmail->setObjectName(QString::fromUtf8("sendEmail"));

        verticalLayout_2->addWidget(sendEmail);


        retranslateUi(SendEmail);

        QMetaObject::connectSlotsByName(SendEmail);
    } // setupUi

    void retranslateUi(QWidget *SendEmail)
    {
        SendEmail->setWindowTitle(QApplication::translate("SendEmail", "\351\202\256\344\273\266\357\274\210Email\357\274\211", nullptr));
        label->setText(QApplication::translate("SendEmail", "SMTP \346\234\215\345\212\241\345\231\250(SMTP server):", nullptr));
        label_2->setText(QApplication::translate("SendEmail", "\347\253\257\345\217\243(Port):", nullptr));
        ssl->setText(QApplication::translate("SendEmail", "SSL", nullptr));
        label_4->setText(QApplication::translate("SendEmail", "\345\220\257\347\224\250\347\224\250\346\210\267\350\256\244\350\257\201(User Authentication):", nullptr));
        label_5->setText(QApplication::translate("SendEmail", "\347\224\250\346\210\267\345\220\215(Username):", nullptr));
        label_6->setText(QApplication::translate("SendEmail", "\345\257\206\347\240\201(Password):", nullptr));
        label_7->setText(QApplication::translate("SendEmail", "Mime E-mail", nullptr));
        label_8->setText(QApplication::translate("SendEmail", "\345\217\221\344\273\266\344\272\272(Sender):", nullptr));
        label_9->setText(QApplication::translate("SendEmail", "\346\224\266\344\273\266\344\272\272(Recipients):", nullptr));
        label_10->setText(QApplication::translate("SendEmail", "\344\270\273\351\242\230(Subject):", nullptr));
        label_3->setText(QApplication::translate("SendEmail", "\351\231\204\344\273\266(Attachments):", nullptr));
        addAttachment->setText(QApplication::translate("SendEmail", "\344\270\212\344\274\240(Add File)", nullptr));
        sendEmail->setText(QApplication::translate("SendEmail", "\345\217\221\351\200\201(Send Email)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendEmail: public Ui_SendEmail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDEMAIL_H
