#ifndef AIHEALTHSERVICE_H
#define AIHEALTHSERVICE_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QEventLoop>
#include <QTimer>
#include <QString>
#include <QApplication>

class AIHealthService
{
public:
    enum AIProvider {
        OpenAI = 0,
        BaiduWenxin = 1,
        AlibabaQwen = 2,
        TencentHunyuan = 3,
        DeepSeek = 4
    };

    struct HealthData {
        QString sex;
        int height;
        int weight;
        int heartRate;
        int systolicBP;
        int diastolicBP;
        int temperature;
        int vitalCapacity;
        double bmi;

        HealthData() : height(0), weight(0), heartRate(0), systolicBP(0),
                      diastolicBP(0), temperature(0), vitalCapacity(0), bmi(0.0) {}
    };

    AIHealthService();
    ~AIHealthService();

    void setAPIConfiguration(AIProvider provider, const QString& apiKey, const QString& endpoint = QString());
    QString analyzeHealthData(const HealthData& data); // 同步调用
    bool isConfigured() const;
    QString getProviderName() const;
    QString getLastError() const;

private:
    QNetworkAccessManager* networkManager;
    AIProvider currentProvider;
    QString apiKey;
    QString apiEndpoint;
    QString lastError;

    QJsonObject buildRequestBody(const HealthData& data);
    QString buildHealthPrompt(const HealthData& data);
    QString parseResponse(const QJsonObject& response);
    QString getDefaultEndpoint(AIProvider provider) const;

    // 同步网络请求
    QString performSyncRequest(const QNetworkRequest& request, const QJsonObject& requestBody);
};

#endif // AIHEALTHSERVICE_H
