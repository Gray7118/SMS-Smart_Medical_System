/*#ifndef EMERGENCY_H
#define EMERGENCY_H

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include "user.h"
#include "message.h"
#include "qtcpsocket.h"
#include "selectreceiver.h"

class EmergencySymptoms : public QWidget
{
    Q_OBJECT
public:
    explicit EmergencySymptoms(QTcpSocket *socket, User *user, QWidget *parent = nullptr);
    
private slots:
    void onConfirmClicked();
    
private:
    QTcpSocket *socket;
    User *user;
    QList<QCheckBox*> symptomCheckboxes;
};

#endif // EMERGENCY_H
*/


#ifndef EMERGENCY_H
#define EMERGENCY_H

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include "user.h"
#include "message.h"
#include "qtcpsocket.h"
#include "selectreceiver.h"

class EmergencySymptoms : public QWidget
{
    Q_OBJECT
public:
    explicit EmergencySymptoms(QTcpSocket *socket, User *user, QWidget *parent = nullptr);

private slots:
    void onConfirmClicked();

private:
    QTcpSocket *socket;
    User *user;
    QList<QCheckBox*> symptomCheckboxes;

    // 疾病症状映射
    QMap<QString, QStringList> diseaseSymptoms;

    // 检查疑似疾病
    QString checkSuspectedDiseases(const QStringList &selectedSymptoms);
};

#endif // EMERGENCY_H
