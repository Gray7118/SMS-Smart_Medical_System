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
        SendEmail->resize(710, 556);
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
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        auth = new QCheckBox(SendEmail);
        auth->setObjectName(QString::fromUtf8("auth"));
        auth->setMinimumSize(QSize(21, 21));
        auth->setMaximumSize(QSize(21, 21));
        auth->setTristate(false);

        horizontalLayout_3->addWidget(auth);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(SendEmail);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        username = new QLineEdit(SendEmail);
        username->setObjectName(QString::fromUtf8("username"));
        username->setMinimumSize(QSize(211, 27));
        username->setMaximumSize(QSize(211, 27));

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
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_7->setFont(font1);

        verticalLayout_2->addWidget(label_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(SendEmail);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(81, 0));
        label_8->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(label_8);

        sender = new QLineEdit(SendEmail);
        sender->setObjectName(QString::fromUtf8("sender"));

        horizontalLayout_2->addWidget(sender);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_9 = new QLabel(SendEmail);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(81, 0));
        label_9->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(label_9);

        recipients = new QLineEdit(SendEmail);
        recipients->setObjectName(QString::fromUtf8("recipients"));

        horizontalLayout_5->addWidget(recipients);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_10 = new QLabel(SendEmail);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(81, 0));
        label_10->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(label_10);

        subject = new QLineEdit(SendEmail);
        subject->setObjectName(QString::fromUtf8("subject"));

        horizontalLayout_6->addWidget(subject);


        verticalLayout_2->addLayout(horizontalLayout_6);

        texteditor = new QTextEdit(SendEmail);
        texteditor->setObjectName(QString::fromUtf8("texteditor"));
        texteditor->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_2->addWidget(texteditor);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(SendEmail);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3);

        addAttachment = new QPushButton(SendEmail);
        addAttachment->setObjectName(QString::fromUtf8("addAttachment"));
        addAttachment->setMinimumSize(QSize(97, 0));
        addAttachment->setMaximumSize(QSize(200, 16777215));

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
        SendEmail->setWindowTitle(QApplication::translate("SendEmail", "Form", nullptr));
        label->setText(QApplication::translate("SendEmail", "SMTP \346\234\215\345\212\241\345\231\250(SMTP server):", nullptr));
        label_2->setText(QApplication::translate("SendEmail", "\347\253\257\345\217\243(Port):", nullptr));
        ssl->setText(QApplication::translate("SendEmail", "SSL", nullptr));
        label_4->setText(QApplication::translate("SendEmail", "\345\220\257\347\224\250\347\224\250\346\210\267\350\256\244\350\257\201(User Authentication):", nullptr));
        auth->setText(QString());
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
