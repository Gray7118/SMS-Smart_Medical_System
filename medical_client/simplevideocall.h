// simplevideocall.h
#ifndef SIMPLEVIDEOCALL_H
#define SIMPLEVIDEOCALL_H

#include <QWidget>
#include <QProcess>
#include <QByteArray>
#include <QTcpSocket>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QPixmap>
#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>
#include <QBuffer>
#include <QImageReader>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QCameraInfo>


#include "user.h"
#include "message.h"
#include "messagetype.h"

class SimpleVideoCall : public QWidget
{
    Q_OBJECT

public:
    explicit SimpleVideoCall(QTcpSocket *socket, User *user, QString partnerName, QWidget *parent = nullptr);
    ~SimpleVideoCall();

    void handleIncomingImage(const QByteArray &imageData);

private slots:
    void captureAndSendImage();
    void onHangupClicked();
    void onImageCaptured(int id, const QImage &image);
    void readCameraData();  // 新增，用于解析 ffmpeg pipe 输出

private:
    void setupUI();
    void initializeCamera();
    void sendImage(const QByteArray &imageData);

private:
    // 网络和用户信息
    QTcpSocket *m_socket;
    User *m_user;
    QString m_partnerName;

    // 摄像头相关
    QCamera *m_camera;
    QCameraViewfinder *m_viewfinder;
    QCameraImageCapture *m_imageCapture;
    QProcess *m_ffmpegProcess;  // 读取摄像头
    QByteArray m_ffmpegBuffer;  // 保存未完整的 JPEG 数据

    // UI组件
    QLabel *m_localImageLabel;      // 显示本地图像
    QLabel *m_remoteImageLabel;     // 显示远程图像
    QPushButton *m_hangupButton;
    QLabel *m_statusLabel;

    // 定时器
    QTimer *m_captureTimer;

    bool m_isCallActive;
};

#endif // SIMPLEVIDEOCALL_H
