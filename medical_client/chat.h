#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QDebug>
#include <QCameraInfo>


#include "user.h"
#include "message.h"
#include "messagetype.h"
#include "simplevideocall.h"  // 在其他include之后添加

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

    void startVideoCall();

    // 新增的消息处理槽函数
    void handleSocketReadyRead();
    void handleReceiveMessage(const Message &msg);
    void handleSendSuccess(const Message &msg);
    void handleReceiverOffline(const Message &msg);
    void handleRetHistory(const Message &msg);
    void handleUpdateIsReadSuccess(const Message &msg);
    void handleVideoCallRequest(const Message &msg);
    void handleVideoCallAccept(const Message &msg);
    void handleVideoCallReject(const Message &msg);
    void handleVideoCallEnd(const Message &msg);
    void handleVideoData(const Message &msg);

private:
    Ui::Chat *ui;
    User *user;
    QTcpSocket *socket;
    QString receiver;

    SimpleVideoCall *m_videoCallWindow;
    QNetworkAccessManager *manager;  // 网络请求管理器
};

#endif // CHAT_H
