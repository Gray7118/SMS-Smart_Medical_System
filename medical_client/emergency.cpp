#include "emergency.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

EmergencySymptoms::EmergencySymptoms(QTcpSocket *socket, User *user, QWidget *parent)
    : QWidget(parent), socket(socket), user(user)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    
    QLabel *titleLabel = new QLabel("请选择您的症状（可多选）:", this);
    layout->addWidget(titleLabel);
    
    // 添加症状选项
    QStringList symptoms = {"高热", "外伤", "昏迷", "头疼", "皮疹", "出血"};
    for (const QString &symptom : symptoms) {
        QCheckBox *checkbox = new QCheckBox(symptom, this);
        symptomCheckboxes.append(checkbox);
        layout->addWidget(checkbox);
    }
    
    QPushButton *confirmButton = new QPushButton("确认", this);
    connect(confirmButton, &QPushButton::clicked, this, &EmergencySymptoms::onConfirmClicked);
    layout->addWidget(confirmButton);
    
    this->setWindowTitle("急诊症状选择");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);
}

void EmergencySymptoms::onConfirmClicked()
{
    // 收集选中的症状
    QString selectedSymptoms;
    for (QCheckBox *checkbox : symptomCheckboxes) {
        if (checkbox->isChecked()) {
            if (!selectedSymptoms.isEmpty()) {
                selectedSymptoms += "、";
            }
            selectedSymptoms += checkbox->text();
        }
    }
    
    if (selectedSymptoms.isEmpty()) {
        QMessageBox::warning(this, "警告", "请至少选择一种症状");
        return;
    }
    
/*    // 发送症状信息到服务器
    Message msg(user, new User, selectedSymptoms, MessageType::EMERGENCY);
    socket->write(Message::messageToByteArray(msg));*/
    
    // 跳转到选人页面
    this->hide();
    SelectReceiver *selectReceiver = new SelectReceiver(socket, user);
    selectReceiver->show();
}
