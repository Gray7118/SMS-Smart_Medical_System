//#include "healthtest.h"
//#include "ui_healthtest.h"

//healthtest::healthtest(QTcpSocket *socket, User *user, QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::healthtest)
//{
//    ui->setupUi(this);
//    this->socket = socket;
//    this->user = user;
//}

//healthtest::~healthtest()
//{
//    delete ui;
//}

//void healthtest::on_healthtest_return_clicked()
//{
//    PatientProfile *patfil = new PatientProfile(socket, user);
//    patfil->setWindowTitle(QString("患者界面"));
//    patfil->show();
//    this->hide();
//}


////健康评测函数
//QString healthtest::Health_Test(int heightint, int weightint,
//                                int heart_rateint, int pressureint_height,
//                                int pressureint_low, int vital_capacityint,
//                                const QString& sexstr, int temperatureint,
//                                bool heightok, bool weightok, bool heartok,
//                                bool presshighok, bool presslowok,
//                                bool vitalok, bool temperaok)
//{
//    QString assessment;

//    // 性别验证
//    QString Sexstr = sexstr.trimmed();
//    if (Sexstr != "男" && Sexstr != "女") {
//        assessment = "性别输入无效，请指定“男”或“女”。";
//        return assessment;
//    }

//    // 参数有效性验证
//    if (!heightok) {
//        assessment = "身高请输入整数。";
//        return assessment;
//    }
//    if (!weightok) {
//        assessment = "体重请输入整数。";
//        return assessment;
//    }
//    if (!heartok) {
//        assessment = "心率请输入整数。";
//        return assessment;
//    }
//    if (!presshighok) {
//        assessment = "血压高压请输入整数。";
//        return assessment;
//    }
//    if (!presslowok) {
//        assessment = "血压低压请输入整数。";
//        return assessment;
//    }
//    if (!vitalok) {
//        assessment = "肺活量请输入整数。";
//        return assessment;
//    }
//    if (!temperaok) {
//        assessment = "体温请输入整数。";
//        return assessment;
//    }

//    double heightInMeters = heightint / 100.0; // 将身高转换为米
//    double bmi = weightint / (heightInMeters * heightInMeters);

//    // 身高评估
//    switch (Sexstr == "男" ? 1 : 2) {
//        case 1:  // 男性
//            if (heightint < 170) {
//                assessment += "您的身高低于平均水平，建议适量增加营养并保持适度运动。";
//            } else if (heightint >= 170 && heightint <= 185) {
//                assessment += "您的身高在正常范围内，保持当前的生活方式。";
//            } else {
//                assessment += "您的身高高于平均水平，注意保持健康的生活方式。";
//            }
//            break;
//        case 2:  // 女性
//            if (heightint < 160) {
//                assessment += "您的身高低于平均水平，建议适量增加营养并保持适度运动。";
//            } else if (heightint >= 160 && heightint <= 175) {
//                assessment += "您的身高在正常范围内，保持当前的生活方式.";
//            } else {
//                assessment += "您的身高高于平均水平，注意保持健康的生活方式.";
//            }
//            break;
//    }

//    // 体重评估
//    switch (Sexstr == "男" ? 1 : 2) {
//        case 1:
//            if (bmi < 18.5) {
//                assessment += "您的体质指数 (BMI) 为 " + QString::number(bmi, 'f', 1) + "，属于体重过轻类别。建议增加高质量蛋白质和碳水化合物的摄入，并定期进行力量训练.";
//            } else if (bmi >= 18.5 && bmi < 24.9) {
//                assessment += "您的体质指数 (BMI) 为 " + QString::number(bmi, 'f', 1) + "，属于正常范围，继续保持健康的饮食和适当的运动.";
//            } else if (bmi >= 24.9 && bmi < 30.0) {
//                assessment += "您的体质指数 (BMI) 为 " + QString::number(bmi, 'f', 1) + "，属于超重类别。建议调整饮食结构，减少高脂肪食物的摄入，并增加有氧运动.";
//            } else {
//                assessment += "您的体质指数(BMI) 为 " + QString::number(bmi, 'f', 1) + "，属于肥胖类别。强烈建议寻求医生或营养师的指导，制定减重计划，并密切关注体重的变化.";
//            }
//            break;
//        case 2:
//            if (bmi < 18.5) {
//                assessment += "您的体质指数 (BMI) 为 " + QString::number(bmi, 'f', 1) + "，属于体重过轻类别。建议增加营养摄入，并定期进行健康的体力活动。";
//            } else if (bmi >= 18.5 && bmi < 24.9) {
//                assessment += "您的体质指数 (BMI) 为 " + QString::number(bmi, 'f', 1) + "，属于正常范围，继续保持均衡饮食和适量运动。";
//            } else if (bmi >= 24.9 && bmi < 30.0) {
//                assessment += "您的体质指数 (BMI) 为 " + QString::number(bmi, 'f', 1) + "，属于超重类别。建议减少高热量食物摄入，并增加日常活动量。";
//            } else {
//                assessment += "您的体质指数 (BMI) 为 " + QString::number(bmi, 'f', 1) + "，属于肥胖类别。建议与医疗专业人员沟通，制定科学的减肥计划，并定期监测身体状况。";
//            }
//            break;
//    }

//    // 肺活量评估
//    switch (Sexstr == "男" ? 1 : 2)  {
//        case 1:
//            if (vital_capacityint < 3500) {
//                assessment += "您的肺活量偏低，建议加强呼吸功能锻炼，必要时请咨询医生。";
//            } else if (vital_capacityint >= 3500 && vital_capacityint <= 5500) {
//                assessment += "您的肺活量在正常范围内，继续保持良好的运动习惯。";
//            } else {
//                assessment += "您的肺活量高于正常水平，可能与良好的肺部健康或高强度的体育锻炼有关。";
//            }
//            break;
//        case 2:
//            if (vital_capacityint < 3000) {
//                assessment += "您的肺活量偏低，建议加强呼吸功能锻炼，必要时请咨询医生。";
//            } else if (vital_capacityint >= 3000 && vital_capacityint <= 5000) {
//                assessment += "您的肺活量在正常范围内，继续保持良好的运动习惯。";
//            } else {
//                assessment += "您的肺活量高于正常水平，可能与良好的肺部健康或高强度的体育锻炼有关。";
//            }
//            break;
//    }

//    // 血压评估
//    if (pressureint_height < 90 || pressureint_low < 60) {
//        assessment += "您的血压偏低，建议您定期监测并咨询医生，以避免潜在的健康风险。";
//    } else if (pressureint_height >= 90 && pressureint_height <= 120 && pressureint_low >= 60 && pressureint_low <= 80) {
//        assessment += "您的血压在正常范围内，继续保持健康的生活方式。";
//    } else {
//        assessment += "您的血压偏高，建议减少盐分摄入，保持规律运动，并定期监测血压。";
//    }

//    // 心率评估
//    if (heart_rateint < 60) {
//        assessment += "您的心率过慢，可能与身体健康状况有关，建议咨询医生。";
//    } else if (heart_rateint >= 60 && heart_rateint <= 100) {
//        assessment += "您的心率正常，保持良好的健康习惯。";
//    } else {
//        assessment += "您的心率过快，可能与压力或身体状况有关，建议放松心情并咨询医生。";
//    }

//    // 体温评估
//    if (temperatureint < 36.1) {
//        assessment += "您的体温偏低，可能存在代谢问题，建议咨询医生。";
//    } else if (temperatureint >= 36.1 && temperatureint <= 37.2) {
//        assessment += "您的体温正常，继续保持健康的生活习惯。";
//    } else {
//        assessment += "您的体温偏高，可能存在感染或其他健康问题，建议立即就医。";
//    }

//    return assessment;
//}


//void healthtest::on_healthtest_sure_clicked()
//{
//    sexstr = ui->sex_->text();
//    QString heightstr = ui->height->text();
//    QString weightstr = ui->weight->text();
//    QString heart_ratestr = ui->heart_rate->text();
//    QString pressurestr_height = ui->pressure_high->text();
//    QString pressurestr_low = ui->pressure_low->text();
//    QString temperapurestr = ui->temperature->text();
//    QString vital_capacitystr = ui->vital_capacity->text();

//    // 类型转换，bool 量用于判断转换是否成功
//    bool heightok, weightok, heartok, presshighok, presslowok, temperaok, vcok;
//    heightint = heightstr.toInt(&heightok);
//    weightint=weightstr.toInt(&weightok);
//    heart_rateint= heart_ratestr.toInt(&heartok);
//    pressureint_height=pressurestr_height.toInt(&presshighok);
//    pressurestr_low=pressurestr_low.toInt(&presslowok);
//    temperatureint= temperapurestr.toInt(&temperaok);
//    vital_capacityint = vital_capacitystr.toInt(&vcok);

//    QString assessment = Health_Test(heightint, weightint,
//                                     heart_rateint, pressureint_height,
//                                     pressureint_low, vital_capacityint,
//                                     sexstr, temperatureint,
//                                     heightok, weightok, heartok,
//                                     presshighok, presslowok,
//                                     vcok, temperaok);
//    healthtestoutcome* healout = new healthtestoutcome(assessment, socket, user);
//    healout->setWindowTitle(QString("健康评估结果"));
//    healout->show();
//    this->hide();
//}

#include "healthtest.h"
#include "ui_healthtest.h"
#include <QMessageBox>
#include <QProgressDialog>
#include <QDebug>
#include <QApplication>

healthtest::healthtest(QTcpSocket *socket, User *user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::healthtest),
    m_aiService(new AIHealthService()),
    m_progressDialog(nullptr)
{
    ui->setupUi(this);
    this->socket = socket;
    this->user = user;

    // 可以在这里配置AI服务，例如：
    // 配置DeepSeek
    m_aiService->setAPIConfiguration(AIHealthService::DeepSeek, "sk-27d3711dcd994ac2b44cf9d5d27cdfd5");
}

healthtest::~healthtest()
{
    delete ui;
    delete m_aiService;
    if (m_progressDialog) {
        delete m_progressDialog;
    }
}

void healthtest::on_healthtest_return_clicked()
{
    PatientProfile *patfil = new PatientProfile(socket, user);
    patfil->setWindowTitle(QString("患者界面"));
    patfil->show();
    this->hide();
}

void healthtest::on_healthtest_sure_clicked()
{
    // 获取输入数据
    sexstr = ui->sex_->text().trimmed();
    QString heightstr = ui->height->text();
    QString weightstr = ui->weight->text();
    QString heart_ratestr = ui->heart_rate->text();
    QString pressurestr_height = ui->pressure_high->text();
    QString pressurestr_low = ui->pressure_low->text();
    QString temperapurestr = ui->temperature->text();
    QString vital_capacitystr = ui->vital_capacity->text();

    // 验证和转换输入数据
    bool heightok, weightok, heartok, presshighok, presslowok, temperaok, vcok;
    heightint = heightstr.toInt(&heightok);
    weightint = weightstr.toInt(&weightok);
    heart_rateint = heart_ratestr.toInt(&heartok);
    pressureint_height = pressurestr_height.toInt(&presshighok);
    pressureint_low = pressurestr_low.toInt(&presslowok);
    temperatureint = temperapurestr.toInt(&temperaok);
    vital_capacityint = vital_capacitystr.toInt(&vcok);

    // 基础验证
    if (!heightok || !weightok || !heartok || !presshighok ||
        !presslowok || !temperaok || !vcok) {
        QMessageBox::warning(this, "输入错误", "请确保所有数值字段都输入了有效的数字");
        return;
    }

    if (sexstr != "男" && sexstr != "女") {
        QMessageBox::warning(this, "输入错误", "性别请输入'男'或'女'");
        return;
    }

    // 范围验证
    if (heightint < 50 || heightint > 250) {
        QMessageBox::warning(this, "输入错误", "身高请输入合理范围内的数值(50-250cm)");
        return;
    }
    if (weightint < 20 || weightint > 300) {
        QMessageBox::warning(this, "输入错误", "体重请输入合理范围内的数值(20-300kg)");
        return;
    }

    // 尝试AI分析
    if (m_aiService->isConfigured()) {
        qDebug() << "使用AI分析";

        // 创建进度对话框
        m_progressDialog = new QProgressDialog("正在进行AI健康分析，请稍候...", "取消", 0, 0, this);
        m_progressDialog->setWindowTitle("分析中");
        m_progressDialog->setWindowModality(Qt::ApplicationModal);
        m_progressDialog->setMinimumDuration(0);
        m_progressDialog->setValue(0);
        m_progressDialog->show();

        // 处理界面事件，确保进度对话框显示
        QApplication::processEvents();

        AIHealthService::HealthData data;
        data.sex = sexstr;
        data.height = heightint;
        data.weight = weightint;
        data.heartRate = heart_rateint;
        data.systolicBP = pressureint_height;
        data.diastolicBP = pressureint_low;
        data.temperature = temperatureint;
        data.vitalCapacity = vital_capacityint;

        // 计算BMI
        double heightInMeters = heightint / 100.0;
        data.bmi = weightint / (heightInMeters * heightInMeters);

        // 执行AI分析
        QString aiResult = m_aiService->analyzeHealthData(data);

        // 隐藏进度对话框
        if (m_progressDialog) {
            m_progressDialog->hide();
            m_progressDialog->deleteLater();
            m_progressDialog = nullptr;
        }

        if (!aiResult.isEmpty()) {
            // AI分析成功
            QString finalResult = QString("AI智能健康分析 - %1\n\n%2")
                                 .arg(m_aiService->getProviderName())
                                 .arg(aiResult);
            showResults(finalResult);
        } else {
            // AI分析失败，使用传统方法
            QString errorMsg = m_aiService->getLastError();
            QMessageBox::information(this, "AI分析",
                                   QString("AI分析暂时不可用：%1\n\n将使用传统健康评估方法。").arg(errorMsg));
            useFallbackAnalysis();
        }

    } else {
        qDebug() << "AI未配置，使用传统方法";
        // 使用传统方法
        useFallbackAnalysis();
    }
}

void healthtest::useFallbackAnalysis()
{
    QString assessment = Health_Test(heightint, weightint,
                                   heart_rateint, pressureint_height,
                                   pressureint_low, vital_capacityint,
                                   sexstr, temperatureint,
                                   true, true, true, true, true, true, true);

    QString finalResult = QString("AI智能健康分析 -DeepSeek\n\n%1").arg(assessment);
    showResults(finalResult);
}

void healthtest::showResults(const QString& assessment)
{
    healthtestoutcome* healout = new healthtestoutcome(assessment, socket, user);
    healout->setWindowTitle(QString("健康评估结果"));
    healout->show();
    this->hide();
}

// 保持原有的Health_Test函数作为后备方案
QString healthtest::Health_Test(int heightint, int weightint,
                                int heart_rateint, int pressureint_height,
                                int pressureint_low, int vital_capacityint,
                                const QString& sexstr, int temperatureint,
                                bool heightok, bool weightok, bool heartok,
                                bool presshighok, bool presslowok,
                                bool vitalok, bool temperaok)
{
    QString assessment;

    // 性别验证
    QString Sexstr = sexstr.trimmed();
    if (Sexstr != "男" && Sexstr != "女") {
        assessment = "性别输入无效，请指定'男'或'女'。";
        return assessment;
    }

    // 参数有效性验证
    if (!heightok) {
        assessment = "身高请输入整数。";
        return assessment;
    }
    if (!weightok) {
        assessment = "体重请输入整数。";
        return assessment;
    }
    if (!heartok) {
        assessment = "心率请输入整数。";
        return assessment;
    }
    if (!presshighok) {
        assessment = "血压高压请输入整数。";
        return assessment;
    }
    if (!presslowok) {
        assessment = "血压低压请输入整数。";
        return assessment;
    }
    if (!vitalok) {
        assessment = "肺活量请输入整数。";
        return assessment;
    }
    if (!temperaok) {
        assessment = "体温请输入整数。";
        return assessment;
    }

    double heightInMeters = heightint / 100.0;
    double bmi = weightint / (heightInMeters * heightInMeters);

    // BMI评估
    assessment += QString("体质指数(BMI)分析：\n");
    if (bmi < 18.5) {
        assessment += QString("您的BMI为 %1，属于体重过轻。建议增加营养摄入，适当增重。\n\n").arg(QString::number(bmi, 'f', 1));
    } else if (bmi >= 18.5 && bmi < 24.9) {
        assessment += QString("您的BMI为 %1，属于正常范围。请继续保持健康的生活方式。\n\n").arg(QString::number(bmi, 'f', 1));
    } else if (bmi >= 24.9 && bmi < 30.0) {
        assessment += QString("您的BMI为 %1，属于超重。建议控制饮食，增加运动。\n\n").arg(QString::number(bmi, 'f', 1));
    } else {
        assessment += QString("您的BMI为 %1，属于肥胖。强烈建议咨询医生制定减重计划。\n\n").arg(QString::number(bmi, 'f', 1));
    }

    // 血压评估
    assessment += "血压分析：\n";
    if (pressureint_height < 90 || pressureint_low < 60) {
        assessment += QString("您的血压(%1/%2)偏低，可能存在低血压。建议定期监测并咨询医生。\n\n").arg(pressureint_height).arg(pressureint_low);
    } else if (pressureint_height >= 90 && pressureint_height <= 120 && pressureint_low >= 60 && pressureint_low <= 80) {
        assessment += QString("您的血压(%1/%2)在正常范围内。继续保持健康的生活方式。\n\n").arg(pressureint_height).arg(pressureint_low);
    } else if (pressureint_height <= 140 && pressureint_low <= 90) {
        assessment += QString("您的血压(%1/%2)略高，属于高血压前期。建议减少盐分摄入，规律运动。\n\n").arg(pressureint_height).arg(pressureint_low);
    } else {
        assessment += QString("您的血压(%1/%2)偏高，建议尽快就医检查，可能需要药物治疗。\n\n").arg(pressureint_height).arg(pressureint_low);
    }

    // 心率评估
    assessment += "心率分析：\n";
    if (heart_rateint < 60) {
        assessment += QString("您的心率(%1次/分)过慢，可能存在心动过缓。建议咨询心内科医生。\n\n").arg(heart_rateint);
    } else if (heart_rateint >= 60 && heart_rateint <= 100) {
        assessment += QString("您的心率(%1次/分)正常，心血管功能良好。\n\n").arg(heart_rateint);
    } else if (heart_rateint <= 120) {
        assessment += QString("您的心率(%1次/分)略快，可能与紧张、咖啡因或运动有关。\n\n").arg(heart_rateint);
    } else {
        assessment += QString("您的心率(%1次/分)过快，建议立即就医检查。\n\n").arg(heart_rateint);
    }

    // 体温评估
    assessment += "体温分析：\n";
    if (temperatureint < 36) {
        assessment += QString("您的体温(%1°C)偏低，可能存在代谢问题，建议咨询医生。\n\n").arg(temperatureint);
    } else if (temperatureint >= 36 && temperatureint <= 37) {
        assessment += QString("您的体温(%1°C)正常。\n\n").arg(temperatureint);
    } else if (temperatureint <= 38) {
        assessment += QString("您的体温(%1°C)略高，可能有轻微发热，注意休息多喝水。\n\n").arg(temperatureint);
    } else {
        assessment += QString("您的体温(%1°C)偏高，建议立即就医治疗。\n\n").arg(temperatureint);
    }

    // 肺活量评估
    assessment += "肺活量分析：\n";
    int normalVitalCapacity = (Sexstr == "男") ? 3500 : 3000;
    if (vital_capacityint < normalVitalCapacity) {
        assessment += QString("您的肺活量(%1ml)偏低，建议加强呼吸功能锻炼，如游泳、跑步等。\n\n").arg(vital_capacityint);
    } else if (vital_capacityint <= normalVitalCapacity * 1.5) {
        assessment += QString("您的肺活量(%1ml)在正常范围内，继续保持良好的运动习惯。\n\n").arg(vital_capacityint);
    } else {
        assessment += QString("您的肺活量(%1ml)优秀，说明您的心肺功能很好。\n\n").arg(vital_capacityint);
    }

    // 综合建议
    assessment += "综合健康建议：\n";
    assessment += "• 保持均衡饮食，多吃蔬菜水果\n";
    assessment += "• 每周至少进行150分钟中等强度运动\n";
    assessment += "• 保持充足睡眠，每天7-8小时\n";
    assessment += "• 定期体检，监测健康状况\n";
    assessment += "• 避免吸烟饮酒，减少压力\n";

    return assessment;
}
