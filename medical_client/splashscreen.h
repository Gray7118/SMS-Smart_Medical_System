#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QWidget>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QColor>
#include <QPointF>
#include <QKeyEvent>

class SplashScreen : public QWidget
{
    Q_OBJECT

public:
    explicit SplashScreen(QWidget *parent = nullptr);
    ~SplashScreen();

    void setDisplayTime(int ms);
    void setSkipEnabled(bool enabled) { m_canSkip = enabled; }

signals:
    void finished();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onAnimationFinished();
    void updateProgress();

private:
    void initUI();
    void initAnimation();
    void drawProgressBar(QPainter &painter);
    void drawAnimatedElements(QPainter &painter);
    void drawMedicalSymbol(QPainter &painter, const QPointF &center, float size);
    void skipAnimation();

    QTimer *m_timer;
    QTimer *m_progressTimer;
    QPropertyAnimation *m_fadeIn;
    QPropertyAnimation *m_fadeOut;
    QGraphicsOpacityEffect *m_opacityEffect;
    int m_displayTime;
    int m_progress;
    int m_angle;
    QColor m_primaryColor;
    QColor m_secondaryColor;
    QList<QPointF> m_particles;
    QWidget *m_topWidget;
    QWidget *m_bottomWidget;
    bool m_canSkip;
};

#endif // SPLASHSCREEN_H
