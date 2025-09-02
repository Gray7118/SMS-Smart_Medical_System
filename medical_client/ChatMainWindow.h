#ifndef CHATMAINWINDOW_H
#define CHATMAINWINDOW_H

#include <QWidget>
#include <QTcpSocket>
#include <QListWidgetItem>
#include <QHash>
#include "user.h"
#include "message.h"
#include "messagetype.h"
#include "simplevideocall.h"

namespace Ui {
class ChatMainWindow;
}

class ChatMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChatMainWindow(QTcpSocket *socket, User *user, QWidget *parent = nullptr);
    ~ChatMainWindow();

signals:
    void returnToProfile();

private slots:
    void on_sendButton_clicked();
    void on_videoCallButton_clicked();
    void on_returnButton_clicked();
    void on_contactListWidget_itemClicked(QListWidgetItem *item);
    void handleSocketReadyRead();

    // 消息处理函数
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
    void handleRetContacts(const Message &msg);

private:
    Ui::ChatMainWindow *ui;
    QTcpSocket *socket;
    User *user;
    QString currentReceiver;
    QHash<QString, int> contactTable; // 联系人列表
    SimpleVideoCall *m_videoCallWindow;

    // 工具函数
    QString getFullname(const QString &username, int role);
    QString getTextLine(const QString &line);
    void loadContactList();
    void switchChat(const QString &receiver);
};

#endif // CHATMAINWINDOW_H
