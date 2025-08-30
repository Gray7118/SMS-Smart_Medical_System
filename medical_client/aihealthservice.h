#ifndef AIHEALTHSERVICE_H
#define AIHEALTHSERVICE_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>

class AIHealthService : public QObject
{
    Q_OBJECT
public:
    enum AIProvider {
        OpenAI,
        DeepSeek,
        BaiduWenxin,
        AlibabaQwen,
        TencentHunyuan
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
    };

    explicit AIHealthService(QObject *parent = nullptr);
    ~AIHealthService();

    void setAPIConfiguration(AIProvider provider, const QString& apiKey, const QString& endpoint = "");
    bool isConfigured() const;
    QString getProviderName() const;
    QString getLastError() const;

    QString analyzeHealthData(const HealthData& data);

private:
    QJsonObject buildRequestBody(const HealthData& data);
    QString buildHealthPrompt(const HealthData& data);
    QString performRequest(const QJsonObject& requestBody);
    QString parseResponse(const QJsonObject& response);

    QNetworkAccessManager* networkManager;
    AIProvider currentProvider;
    QString apiKey;
    QString apiEndpoint;
    QString lastError;
};

#endif // AIHEALTHSERVICE_H
