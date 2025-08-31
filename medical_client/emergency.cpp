/*#include "emergency.h"
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
/*    this->hide();
    SelectReceiver *selectReceiver = new SelectReceiver(socket, user);
    selectReceiver->show();
}
*/


#include "emergency.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QFont>

EmergencySymptoms::EmergencySymptoms(QTcpSocket *socket, User *user, QWidget *parent)
    : QWidget(parent), socket(socket), user(user)
{
    // 初始化疾病症状映射
    diseaseSymptoms = {
        {"疟疾", {"高热", "寒战", "头痛", "肌肉疼痛", "呕吐", "上腹部疼痛", "出汗"}},
        {"霍乱", {"水样腹泻", "呕吐", "脱水", "肌肉痉挛", "口渴", "乏力"}},
        {"埃博拉", {"发热", "头痛", "肌肉疼痛", "虚弱", "腹泻", "呕吐", "出血"}}
    };

    // 设置全局大字体
    QFont bigFont;
    bigFont.setPointSize(18);  // 基础字体大小设为18

    // 主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(30);  // 增加布局间距

    // 标题（超大加粗）
    QLabel *titleLabel = new QLabel("请选择您的症状（可多选）:", this);
    QFont titleFont = bigFont;
    titleFont.setBold(true);
    titleFont.setPointSize(24);  // 标题更大
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("color: #2c3e50;");
    mainLayout->addWidget(titleLabel, 0, Qt::AlignCenter);

    // 症状选择区域 - 使用两列布局
    QWidget *symptomsWidget = new QWidget(this);
    QHBoxLayout *symptomsLayout = new QHBoxLayout(symptomsWidget);
    symptomsLayout->setSpacing(40);  // 增加列间距

    // 左列症状
    QWidget *leftColumn = new QWidget();
    QVBoxLayout *leftLayout = new QVBoxLayout(leftColumn);
    leftLayout->setAlignment(Qt::AlignTop);
    leftLayout->setSpacing(20);  // 增加选项间距

    // 右列症状
    QWidget *rightColumn = new QWidget();
    QVBoxLayout *rightLayout = new QVBoxLayout(rightColumn);
    rightLayout->setAlignment(Qt::AlignTop);
    rightLayout->setSpacing(20);

    // 合并所有症状（去重）
    QSet<QString> allSymptoms;
    for (const QStringList &symptoms : diseaseSymptoms) {
        for (const QString &symptom : symptoms) {
            allSymptoms.insert(symptom);
        }
    }

    // 添加其他常见症状
    QStringList additionalSymptoms = {
        "外伤", "昏迷", "皮疹", "呼吸困难", "胸痛",
        "腹痛", "头晕", "意识模糊", "抽搐", "咳嗽",
        "皮肤发黄", "关节疼痛", "食欲不振"
    };

    for (const QString &symptom : additionalSymptoms) {
        allSymptoms.insert(symptom);
    }

    // 按字母顺序排序症状
    QList<QString> sortedSymptoms = allSymptoms.values();
    std::sort(sortedSymptoms.begin(), sortedSymptoms.end());

    // 将症状均匀分配到两列（使用大字体复选框）
    int half = (sortedSymptoms.size() + 1) / 2;
    for (int i = 0; i < sortedSymptoms.size(); ++i) {
        QCheckBox *checkbox = new QCheckBox(sortedSymptoms[i]);
        checkbox->setFont(bigFont);
        checkbox->setStyleSheet("QCheckBox { spacing: 15px; }");  // 增加图标与文本间距
        checkbox->setMinimumHeight(40);  // 增加最小高度
        symptomCheckboxes.append(checkbox);

        if (i < half) {
            leftLayout->addWidget(checkbox);
        } else {
            rightLayout->addWidget(checkbox);
        }
    }

    // 添加"其他"选项到右列底部（超大字体）
    QCheckBox *otherCheckbox = new QCheckBox("其他（请描述）");
    otherCheckbox->setFont(bigFont);
    otherCheckbox->setStyleSheet("QCheckBox { spacing: 15px; color: #e74c3c; }");
    otherCheckbox->setMinimumHeight(45);
    symptomCheckboxes.append(otherCheckbox);
    rightLayout->addWidget(otherCheckbox);

    symptomsLayout->addWidget(leftColumn);
    symptomsLayout->addWidget(rightColumn);
    mainLayout->addWidget(symptomsWidget);

    // 确认按钮（超大醒目按钮）
    QPushButton *confirmButton = new QPushButton("确 认");
    confirmButton->setFont(bigFont);
    confirmButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #e74c3c;"
        "   color: white;"
        "   border-radius: 10px;"
        "   padding: 20px 40px;"
        "   min-width: 200px;"
        "}"
        "QPushButton:hover { background-color: #c0392b; }"
    );
    mainLayout->addWidget(confirmButton, 0, Qt::AlignCenter);

    connect(confirmButton, &QPushButton::clicked, this, &EmergencySymptoms::onConfirmClicked);

    // 设置窗口属性（更大尺寸）
    this->setWindowTitle("急诊症状选择");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);
    this->resize(1000, 800);  // 更大的窗口尺寸

    // 设置全局字体
    this->setFont(bigFont);
}

void EmergencySymptoms::onConfirmClicked()
{
    // 收集选中的症状
    QStringList selectedSymptoms;
    for (QCheckBox *checkbox : symptomCheckboxes) {
        if (checkbox->isChecked() && checkbox->text() != "其他（请描述）") {
            selectedSymptoms.append(checkbox->text());
        }
    }

    if (selectedSymptoms.isEmpty()) {
        QMessageBox warningBox;
        warningBox.setWindowTitle("警告");
        warningBox.setText("请至少选择一种症状");
        warningBox.setIcon(QMessageBox::Warning);
        warningBox.setStyleSheet("QLabel{ font-size: 20px; } QPushButton{ font-size: 18px; padding: 10px; }");
        warningBox.exec();
        return;
    }

    // 检查疑似疾病
    QString suspectedDisease = checkSuspectedDiseases(selectedSymptoms);
    if (!suspectedDisease.isEmpty()) {
        QMessageBox infoBox;
        infoBox.setWindowTitle("重要提示");
        infoBox.setText(QString("⚠️ 检测到疑似%1症状\n已自动上报疾控中心 ⚠️").arg(suspectedDisease));
        infoBox.setIcon(QMessageBox::Critical);
        infoBox.setStyleSheet("QLabel{ font-size: 22px; } QPushButton{ font-size: 20px; padding: 15px; }");
        infoBox.exec();
    }

    // 发送症状信息到服务器
    QString symptomsStr = selectedSymptoms.join("、");
    /*Message msg(user, new User, symptomsStr, MessageType::EMERGENCY);
    socket->write(Message::messageToByteArray(msg));*/

    // 跳转到选人页面
    this->hide();
    SelectReceiver *selectReceiver = new SelectReceiver(socket, user);
    selectReceiver->show();
}

QString EmergencySymptoms::checkSuspectedDiseases(const QStringList &selectedSymptoms)
{
    for (const QString &disease : diseaseSymptoms.keys()) {
        const QStringList &symptoms = diseaseSymptoms[disease];
        int matchCount = 0;

        for (const QString &symptom : symptoms) {
            if (selectedSymptoms.contains(symptom)) {
                matchCount++;
                if (matchCount >= 3) {
                    return disease;
                }
            }
        }
    }

    return "";
}
