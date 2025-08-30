#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QDebug>

#include "user.h"
#include "message.h"
#include "messagetype.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QCryptographicHash>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QTcpSocket *socket, User *user, QString receiver, QWidget *parent = nullptr);
    ~Chat();

    QString getFullname(QString username, int role);

    QString getTextLine(QString line);

    QString getLine(QString content, QString chatDate, QString isRead, QString sender);

    void translateText(const QString &text, const QString &from, const QString &to, std::function<void(QString)> callback);

signals:
    void returnToProfile();

private slots:
    void on_returnButton_clicked();

    void on_sendButton_clicked();

private:
    Ui::Chat *ui;
    User *user;
    QTcpSocket *socket;
    QString receiver;

    QNetworkAccessManager *manager;  // 网络请求管理器
};

#endif // CHAT_H
