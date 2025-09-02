#include "splashscreen.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPainter>
#include <QApplication>
#include <QDesktopWidget>
#include <QLinearGradient>
#include <QtMath>
#include <QRandomGenerator>

SplashScreen::SplashScreen(QWidget *parent)
    : QWidget(parent),
      m_timer(nullptr),
      m_progressTimer(nullptr),
      m_fadeIn(nullptr),
      m_fadeOut(nullptr),
      m_opacityEffect(nullptr),
      m_displayTime(3800),
      m_progress(0),
      m_angle(0),
      m_primaryColor(30, 144, 255),   // DodgerBlue
      m_secondaryColor(100, 230, 255),
      m_topWidget(nullptr),
      m_bottomWidget(nullptr),
      m_canSkip(true)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground, false); // 禁用透明背景

    initUI();
    initAnimation();

    // 初始化粒子，分布在整个窗口上半部分
    for (int i = 0; i < 80; ++i) {
        m_particles.append(QPointF(
            QRandomGenerator::global()->bounded(width()),
            QRandomGenerator::global()->bounded(m_topWidget->height())
        ));
    }

    // 居中显示
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    move((screenGeometry.width() - width()) / 2,
         (screenGeometry.height() - height()) / 2);
}

SplashScreen::~SplashScreen()
{
    if (m_timer) m_timer->deleteLater();
    if (m_progressTimer) m_progressTimer->deleteLater();
    if (m_fadeIn) m_fadeIn->deleteLater();
    if (m_fadeOut) m_fadeOut->deleteLater();
    if (m_opacityEffect) m_opacityEffect->deleteLater();
}

void SplashScreen::setDisplayTime(int ms)
{
    m_displayTime = ms;
    if (m_timer) m_timer->start(m_displayTime);
}

void SplashScreen::initUI()
{
    // 主窗口设置
    resize(650, 500);
    setStyleSheet("background-color: white;"); // 纯白色不透明背景

    // 主布局（上下分区）
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    // 上部区域 - 动画展示
    m_topWidget = new QWidget(this);
    m_topWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_topWidget->setStyleSheet("background: transparent;");

    // 下部区域 - 文字信息
    m_bottomWidget = new QWidget(this);
    m_bottomWidget->setStyleSheet("background: transparent;");
    m_bottomWidget->setFixedHeight(200); // 固定高度确保文字区域稳定

    QVBoxLayout *bottomLayout = new QVBoxLayout(m_bottomWidget);
    bottomLayout->setContentsMargins(40, 10, 40, 30);

    // 标题标签
    QLabel *titleLabel = new QLabel("智能医疗系统", m_bottomWidget);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("QLabel { "
                             "color: #1E3A8A; "
                             "font-size: 36px; "
                             "font-weight: bold; "
                             "}");

    // 副标题
    QLabel *subTitleLabel = new QLabel("正在初始化医疗组件...", m_bottomWidget);
    subTitleLabel->setAlignment(Qt::AlignCenter);
    subTitleLabel->setStyleSheet("QLabel { "
                               "color: #1E40AF; "
                               "font-size: 18px; "
                               "}");

    // 添加跳过提示
    QLabel *skipHint = new QLabel("按空格键跳过", m_bottomWidget);
    skipHint->setAlignment(Qt::AlignCenter);
    skipHint->setStyleSheet("QLabel { "
                           "color: #666666; "
                           "font-size: 14px; "
                           "}");

    bottomLayout->addStretch();
    bottomLayout->addWidget(titleLabel);
    bottomLayout->addSpacing(8);
    bottomLayout->addWidget(subTitleLabel);
    bottomLayout->addSpacing(15);
    bottomLayout->addWidget(skipHint);
    bottomLayout->addStretch();

    // 组装主布局
    mainLayout->addWidget(m_topWidget);
    mainLayout->addWidget(m_bottomWidget);
}

void SplashScreen::initAnimation()
{
    m_opacityEffect = new QGraphicsOpacityEffect(this);
    m_opacityEffect->setOpacity(0);
    setGraphicsEffect(m_opacityEffect);

    // 淡入动画
    m_fadeIn = new QPropertyAnimation(m_opacityEffect, "opacity");
    m_fadeIn->setDuration(1200);
    m_fadeIn->setStartValue(0);
    m_fadeIn->setEndValue(1);
    m_fadeIn->setEasingCurve(QEasingCurve::OutCubic);

    // 淡出动画
    m_fadeOut = new QPropertyAnimation(m_opacityEffect, "opacity");
    m_fadeOut->setDuration(1000);
    m_fadeOut->setStartValue(1);
    m_fadeOut->setEndValue(0);
    m_fadeOut->setEasingCurve(QEasingCurve::InCubic);

    connect(m_fadeOut, &QPropertyAnimation::finished, this, &SplashScreen::onAnimationFinished);

    // 进度定时器
    m_progressTimer = new QTimer(this);
    connect(m_progressTimer, &QTimer::timeout, this, &SplashScreen::updateProgress);
    m_progressTimer->start(30);

    // 显示时间定时器
    m_timer = new QTimer(this);
    m_timer->setSingleShot(true);
    connect(m_timer, &QTimer::timeout, [this](){
        m_fadeOut->start();
        m_progressTimer->stop();
    });

    m_fadeIn->start();
    m_timer->start(m_displayTime);
}

void SplashScreen::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 创建圆角路径
    QPainterPath path;
    path.addRoundedRect(rect(), 20, 20);

    // 设置剪裁区域，确保所有内容都在圆角区域内
    painter.setClipPath(path);

    // 绘制白色背景（确保完全不透明）
    painter.fillPath(path, Qt::white);

    // 绘制边框
    painter.setPen(QPen(QColor(200, 200, 210), 2));
    painter.setBrush(Qt::NoBrush);
    painter.drawPath(path);

    // 绘制动画元素（覆盖整个窗口上半部分）
    painter.save();
    painter.translate(0, 0);
    drawAnimatedElements(painter);
    painter.restore();

    // 在底部区域上方绘制进度条
    painter.save();
    painter.translate(0, m_bottomWidget->y() - 30);
    drawProgressBar(painter);
    painter.restore();
}

void SplashScreen::drawProgressBar(QPainter &painter)
{
    int barHeight = 6;
    int barWidth = width() - 120;
    int x = (width() - barWidth) / 2;
    int y = 10; // 相对于底部区域上方

    // 背景
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(230, 230, 230));
    painter.drawRoundedRect(x, y, barWidth, barHeight, 3, 3);

    // 进度条
    int progressWidth = barWidth * m_progress / 100;
    QLinearGradient gradient(x, y, x + progressWidth, y);
    gradient.setColorAt(0, m_primaryColor);
    gradient.setColorAt(1, m_secondaryColor);
    painter.setBrush(gradient);
    painter.drawRoundedRect(x, y, progressWidth, barHeight, 3, 3);

    // 进度文本
    painter.setPen(m_primaryColor.darker());
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.drawText(QRect(x, y - 25, barWidth, 20), Qt::AlignCenter,
                    QString("加载进度: %1%").arg(m_progress));
}

void SplashScreen::drawAnimatedElements(QPainter &painter)
{
    int centerX = width() / 2;
    int centerY = m_topWidget->height() / 2;

    // 医疗十字标志
    drawMedicalSymbol(painter, QPointF(centerX, centerY), 70);

    // 旋转光环
    painter.save();
    painter.translate(centerX, centerY);
    painter.rotate(m_angle);

    QConicalGradient gradient(0, 0, 0);
    gradient.setColorAt(0.0, Qt::transparent);
    gradient.setColorAt(0.2, m_primaryColor);
    gradient.setColorAt(0.5, m_secondaryColor);
    gradient.setColorAt(0.8, m_primaryColor);
    gradient.setColorAt(1.0, Qt::transparent);

    painter.setPen(QPen(QBrush(gradient), 5));
    painter.setBrush(Qt::NoBrush);
    painter.drawEllipse(QPoint(0, 0), 80, 80);
    painter.restore();

    // 粒子效果 - 覆盖整个窗口上半部分
    painter.setPen(Qt::NoPen);
    for (QPointF &particle : m_particles) {
        float size = 2 + qSin(m_angle * M_PI / 180 + particle.x() * 0.01) * 2;
        QColor color = m_primaryColor;
        color.setAlphaF(0.6 + qCos(particle.y() * 0.01) * 0.2);
        painter.setBrush(color);
        painter.drawEllipse(particle, size, size);
    }
}

void SplashScreen::drawMedicalSymbol(QPainter &painter, const QPointF &center, float size)
{
    painter.save();
    painter.setRenderHint(QPainter::Antialiasing);

    float crossWidth = size * 0.15;

    // 垂直部分
    QRectF verticalRect(center.x() - crossWidth/2, center.y() - size/2, crossWidth, size);
    // 水平部分
    QRectF horizontalRect(center.x() - size/2, center.y() - crossWidth/2, size, crossWidth);

    QLinearGradient grad(center.x(), center.y() - size/2, center.x(), center.y() + size/2);
    grad.setColorAt(0, m_primaryColor.lighter(120));
    grad.setColorAt(1, m_primaryColor.darker(120));

    painter.setPen(Qt::NoPen);
    painter.setBrush(grad);
    painter.drawRect(verticalRect);
    painter.drawRect(horizontalRect);

    // 中心圆点
    painter.setBrush(m_secondaryColor);
    painter.drawEllipse(center, crossWidth*1.5, crossWidth*1.5);

    painter.restore();
}

void SplashScreen::updateProgress()
{
    m_progress = qMin(m_progress + 1, 100);
    m_angle = (m_angle + 3) % 360;

    // 更新粒子位置 - 在整个窗口上半部分移动
    for (QPointF &particle : m_particles) {
        particle += QPointF(
            QRandomGenerator::global()->bounded(1.5) - 0.75,
            QRandomGenerator::global()->bounded(1.5) - 0.75
        );

        // 限制在整个窗口上半部分
        particle.setX(qBound(0.0, particle.x(), (double)width()));
        particle.setY(qBound(0.0, particle.y(), (double)m_topWidget->height()));
    }

    update();
}

void SplashScreen::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space && m_canSkip) {
        skipAnimation();
    } else {
        QWidget::keyPressEvent(event);
    }
}

void SplashScreen::skipAnimation()
{
    m_canSkip = false; // 防止重复触发
    if (m_fadeOut->state() != QPropertyAnimation::Running) {
        m_fadeOut->start();
        m_progressTimer->stop();
        m_timer->stop();
    }
}

void SplashScreen::onAnimationFinished()
{
    emit finished();
    close();
}
