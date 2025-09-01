// simplevideocall.cpp
#include "simplevideocall.h"
#include <QMessageBox>
#include <QDebug>
#include <QCameraInfo>


SimpleVideoCall::SimpleVideoCall(QTcpSocket *socket, User *user, QString partnerName, QWidget *parent)
    : QWidget(parent), m_socket(socket), m_user(user), m_partnerName(partnerName),
      m_camera(nullptr), m_isCallActive(false)
{
    setupUI();
    initializeCamera();


    // 每2秒捕获一次图像（帧率较低以减少数据量）
    m_captureTimer = new QTimer(this);
    connect(m_captureTimer, &QTimer::timeout, this, &SimpleVideoCall::captureAndSendImage);

    setWindowTitle(QString("简易视频通话 - %1").arg(partnerName));
    resize(800, 600);

    // 开始通话
    m_captureTimer->start(200); // 0.2秒一帧
    m_isCallActive = true;
}

SimpleVideoCall::~SimpleVideoCall()
{
    if (m_camera) {
        m_camera->stop();
        delete m_camera;
    }
}

void SimpleVideoCall::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 状态标签
    m_statusLabel = new QLabel("视频通话中...");
    m_statusLabel->setAlignment(Qt::AlignCenter);
    m_statusLabel->setStyleSheet("font-size: 14px; font-weight: bold; padding: 10px;");
    mainLayout->addWidget(m_statusLabel);

    // 视频显示区域
    QHBoxLayout *videoLayout = new QHBoxLayout();

    // 本地视频区域
    QVBoxLayout *localLayout = new QVBoxLayout();
    QLabel *localTitle = new QLabel("我的画面");
    localTitle->setAlignment(Qt::AlignCenter);
    localTitle->setStyleSheet("font-weight: bold;");
    localLayout->addWidget(localTitle);

    m_localImageLabel = new QLabel();
    m_localImageLabel->setFixedSize(300, 225);
    m_localImageLabel->setStyleSheet("border: 2px solid gray; background-color: black;");
    m_localImageLabel->setAlignment(Qt::AlignCenter);
    m_localImageLabel->setText("摄像头启动中...");
    m_localImageLabel->setScaledContents(true);
    localLayout->addWidget(m_localImageLabel);

    // 远程视频区域
    QVBoxLayout *remoteLayout = new QVBoxLayout();
    QLabel *remoteTitle = new QLabel(QString("%1的画面").arg(m_partnerName));
    remoteTitle->setAlignment(Qt::AlignCenter);
    remoteTitle->setStyleSheet("font-weight: bold;");
    remoteLayout->addWidget(remoteTitle);

    m_remoteImageLabel = new QLabel();
    m_remoteImageLabel->setFixedSize(400, 300);
    m_remoteImageLabel->setStyleSheet("border: 2px solid blue; background-color: black;");
    m_remoteImageLabel->setAlignment(Qt::AlignCenter);
    m_remoteImageLabel->setText("等待对方画面...");
    m_remoteImageLabel->setScaledContents(true);
    remoteLayout->addWidget(m_remoteImageLabel);

    videoLayout->addLayout(localLayout);
    videoLayout->addLayout(remoteLayout);
    mainLayout->addLayout(videoLayout);

    // 控制按钮
    QHBoxLayout *controlLayout = new QHBoxLayout();
    controlLayout->addStretch();

    m_hangupButton = new QPushButton("结束通话");
    m_hangupButton->setStyleSheet(
        "QPushButton {"
        "background-color: #ff4444; color: white; font-weight: bold; "
        "padding: 10px 20px; border-radius: 5px; font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "background-color: #cc0000;"
        "}"
    );
    connect(m_hangupButton, &QPushButton::clicked, this, &SimpleVideoCall::onHangupClicked);
    controlLayout->addWidget(m_hangupButton);

    controlLayout->addStretch();
    mainLayout->addLayout(controlLayout);
}

void SimpleVideoCall::initializeCamera()
{
    qDebug() << "使用成功的ffplay参数启动摄像头...";

    m_ffmpegProcess = new QProcess(this);

    // 使用与你成功的ffplay命令完全相同的参数
    QStringList args;
    args << "-f" << "v4l2"
         << "-input_format" << "mjpeg"  // 关键：明确指定输入格式为mjpeg
         << "-video_size" << "640x480"  // 使用你测试成功的分辨率
         << "-i" << "/dev/video0"
         << "-f" << "image2pipe"        // 输出格式：图像管道
         << "-vcodec" << "copy"         // 直接复制mjpeg数据，不重新编码
         << "-";

    qDebug() << "FFmpeg命令:" << "ffmpeg" << args.join(" ");

    m_ffmpegProcess->setProcessChannelMode(QProcess::SeparateChannels);

    connect(m_ffmpegProcess, &QProcess::readyReadStandardOutput,
            this, &SimpleVideoCall::readCameraData);

    connect(m_ffmpegProcess, &QProcess::readyReadStandardError, this, [this](){
        QByteArray errorData = m_ffmpegProcess->readAllStandardError();
        QString errorStr = QString::fromUtf8(errorData);
        qDebug() << "FFmpeg stderr:" << errorStr;
    });

    connect(m_ffmpegProcess, &QProcess::started, this, [this](){
        qDebug() << "FFmpeg摄像头进程启动成功";
        m_localImageLabel->setText("摄像头启动成功，等待画面...");
    });

    connect(m_ffmpegProcess, &QProcess::errorOccurred, this, [this](QProcess::ProcessError err){
        qDebug() << "FFmpeg进程错误:" << err;
        m_localImageLabel->setText("摄像头进程启动失败");
    });

    m_ffmpegProcess->start("ffmpeg", args);

    if (!m_ffmpegProcess->waitForStarted(3000)) {
        qDebug() << "FFmpeg启动失败";
        m_localImageLabel->setText("摄像头启动超时");
    }
}

void SimpleVideoCall::readCameraData()
{
    m_ffmpegBuffer.append(m_ffmpegProcess->readAllStandardOutput());

    while (true) {
        int start = m_ffmpegBuffer.indexOf("\xFF\xD8"); // JPEG 起始
        int end   = m_ffmpegBuffer.indexOf("\xFF\xD9"); // JPEG 结束

        if (start == -1 || end == -1 || end <= start)
            break;

        QByteArray jpegData = m_ffmpegBuffer.mid(start, end - start + 2); // +2 包含 0xFFD9
        m_ffmpegBuffer.remove(0, end + 2);

        QImage image;
        if (image.loadFromData(jpegData, "JPEG")) {
            m_localImageLabel->setPixmap(QPixmap::fromImage(image)
                                         .scaled(m_localImageLabel->size(),
                                                 Qt::KeepAspectRatio,
                                                 Qt::SmoothTransformation));
        }
    }
}



void SimpleVideoCall::captureAndSendImage()
{
    if (!m_isCallActive)
        return;

    const QPixmap* pixmapPtr = m_localImageLabel->pixmap();
    if (!pixmapPtr || pixmapPtr->isNull()) {
        return;
    }

    // 大幅缩小图像尺寸以提高传输速度
    QImage scaledImage = pixmapPtr->toImage().scaled(160, 120, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // 压缩成JPEG，降低质量以减小数据量
    QByteArray imageData;
    QBuffer buffer(&imageData);
    buffer.open(QIODevice::WriteOnly);
    scaledImage.save(&buffer, "JPEG", 30); // 降低质量到30%

    sendImage(imageData);

    // 只保留关键日志，减少输出
    if (imageData.size() > 0) {
        qDebug() << "发送帧，大小:" << imageData.size() << "字节";
    }
}



void SimpleVideoCall::onImageCaptured(int id, const QImage &image)
{
    Q_UNUSED(id)

    if (image.isNull()) {
        return;
    }

    // 显示本地图像
    QPixmap pixmap = QPixmap::fromImage(image);
    m_localImageLabel->setPixmap(pixmap.scaled(m_localImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // 压缩图像并发送
    QByteArray imageData;
    QBuffer buffer(&imageData);
    buffer.open(QIODevice::WriteOnly);

    // 缩放图像以减少数据量（320x240）
    QImage scaledImage = image.scaled(320, 240, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    scaledImage.save(&buffer, "JPEG", 70); // 70%质量压缩

    sendImage(imageData);
}

void SimpleVideoCall::sendImage(const QByteArray &imageData)
{
    QString base64Data = imageData.toBase64();

    Message msg(m_user, new User(m_partnerName, "", m_user->role == 0 ? 1 : 0),
                base64Data, VIDEO_DATA);

    qint64 bytesWritten = m_socket->write(Message::messageToByteArray(msg));

    // 强制立即发送数据
    m_socket->flush();

    // 简化日志输出
    static int frameCount = 0;
    if (++frameCount % 10 == 0) { // 每10帧输出一次日志
        qDebug() << "已发送" << frameCount << "帧";
    }
}

void SimpleVideoCall::handleIncomingImage(const QByteArray &imageData)
{
    QByteArray actualImageData = QByteArray::fromBase64(imageData);

    QImage image;
    if (image.loadFromData(actualImageData, "JPEG")) {
        QPixmap pixmap = QPixmap::fromImage(image);
        m_remoteImageLabel->setPixmap(pixmap.scaled(m_remoteImageLabel->size(),
                                                   Qt::KeepAspectRatio,
                                                   Qt::SmoothTransformation));

        // 简化日志
        static int receiveCount = 0;
        if (++receiveCount % 10 == 0) {
            qDebug() << "已接收" << receiveCount << "帧";
        }
    }
}

void SimpleVideoCall::onHangupClicked()
{
    m_isCallActive = false;
    m_captureTimer->stop();

    if (m_camera) {
        m_camera->stop();
    }

    // 发送结束通话消息
    Message msg(m_user, new User(m_partnerName, "", m_user->role == 0 ? 1 : 0),
                "", VIDEO_CALL_END);
    m_socket->write(Message::messageToByteArray(msg));

    m_statusLabel->setText("通话已结束");

    // 延迟关闭窗口
    QTimer::singleShot(1000, this, &QWidget::close);
}
