#include "aihealthservice.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QEventLoop>
#include <QTimer>
#include <QDebug>

AIHealthService::AIHealthService(QObject *parent)
    : QObject(parent),
      networkManager(new QNetworkAccessManager(this)),
      currentProvider(DeepSeek)
{
}

AIHealthService::~AIHealthService()
{
    networkManager->deleteLater();
}

void AIHealthService::setAPIConfiguration(AIProvider provider, const QString& apiKey, const QString& endpoint)
{
    this->currentProvider = provider;
    this->apiKey = apiKey;

    if (!endpoint.isEmpty()) {
        this->apiEndpoint = endpoint;
    } else {
        // 设置默认端点
        switch (provider) {
        case OpenAI:
            apiEndpoint = "https://api.openai.com/v1/chat/completions";
            break;
        case DeepSeek:
            apiEndpoint = "https://api.deepseek.com/v1/chat/completions";
            break;
        case BaiduWenxin:
            apiEndpoint = "https://aip.baidubce.com/rpc/2.0/ai_custom/v1/wenxinworkshop/chat/completions";
            break;
        case AlibabaQwen:
            apiEndpoint = "https://dashscope.aliyuncs.com/api/v1/services/aigc/text-generation/generation";
            break;
        case TencentHunyuan:
            apiEndpoint = "https://hunyuan.tencentcloudapi.com/";
            break;
        }
    }
}

bool AIHealthService::isConfigured() const
{
    return !apiKey.isEmpty() && !apiEndpoint.isEmpty();
}

QString AIHealthService::getProviderName() const
{
    switch (currentProvider) {
    case OpenAI: return "OpenAI GPT";
    case DeepSeek: return "DeepSeek";
    case BaiduWenxin: return "百度文心一言";
    case AlibabaQwen: return "阿里云通义千问";
    case TencentHunyuan: return "腾讯混元";
    default: return "未知服务";
    }
}

QString AIHealthService::getLastError() const
{
    return lastError;
}

QString AIHealthService::analyzeHealthData(const HealthData& data)
{
    if (!isConfigured()) {
        lastError = "AI服务未配置，请先设置API密钥";
        return QString();
    }

    QJsonObject requestBody = buildRequestBody(data);
    return performRequest(requestBody);
}

QJsonObject AIHealthService::buildRequestBody(const HealthData& data)
{
    QJsonObject requestBody;
    QString prompt = buildHealthPrompt(data);

    switch (currentProvider) {
    case OpenAI: {
        requestBody["model"] = "gpt-3.5-turbo";
        requestBody["temperature"] = 0.7;
        requestBody["max_tokens"] = 2000;

        QJsonArray messages;
        QJsonObject systemMessage;
        systemMessage["role"] = "system";
        systemMessage["content"] = "你是一位专业的健康顾问。请根据用户提供的健康数据，给出专业、个性化的健康评估和建议。";
        messages.append(systemMessage);

        QJsonObject userMessage;
        userMessage["role"] = "user";
        userMessage["content"] = prompt;
        messages.append(userMessage);

        requestBody["messages"] = messages;
        break;
    }

    case DeepSeek: {
        requestBody["model"] = "deepseek-chat";
        requestBody["temperature"] = 0.7;
        requestBody["max_tokens"] = 2000;

        QJsonArray messages;
        QJsonObject systemMessage;
        systemMessage["role"] = "system";
        systemMessage["content"] = "你是一位专业的健康顾问。请根据用户提供的健康数据，给出专业、个性化的健康评估和建议。";
        messages.append(systemMessage);

        QJsonObject userMessage;
        userMessage["role"] = "user";
        userMessage["content"] = prompt;
        messages.append(userMessage);

        requestBody["messages"] = messages;
        break;
    }

    case BaiduWenxin: {
        QJsonArray messages;
        QJsonObject message;
        message["role"] = "user";
        message["content"] = "请作为专业健康顾问，分析以下健康数据：\n" + prompt;
        messages.append(message);

        requestBody["messages"] = messages;
        requestBody["temperature"] = 0.7;
        requestBody["max_output_tokens"] = 2000;
        break;
    }

    case AlibabaQwen: {
        requestBody["model"] = "qwen-turbo";

        QJsonObject input;
        QJsonArray messages;

        QJsonObject systemMsg;
        systemMsg["role"] = "system";
        systemMsg["content"] = "你是专业的健康评估助手";
        messages.append(systemMsg);

        QJsonObject userMsg;
        userMsg["role"] = "user";
        userMsg["content"] = prompt;
        messages.append(userMsg);

        input["messages"] = messages;
        requestBody["input"] = input;

        QJsonObject parameters;
        parameters["max_tokens"] = 2000;
        parameters["temperature"] = 0.7;
        requestBody["parameters"] = parameters;
        break;
    }

    case TencentHunyuan: {
        QJsonArray messages;
        QJsonObject message;
        message["Role"] = "user";
        message["Content"] = prompt;
        messages.append(message);
        requestBody["Messages"] = messages;
        break;
    }
    }

    return requestBody;
}

QString AIHealthService::buildHealthPrompt(const HealthData& data)
{
    return QString(
        "请分析以下健康数据并提供专业建议：\n\n"
        "基本信息：\n"
        "- 性别：%1\n"
        "- 身高：%2 cm\n"
        "- 体重：%3 kg\n"
        "- BMI：%4\n\n"
        "生理指标：\n"
        "- 心率：%5 次/分钟\n"
        "- 血压：%6/%7 mmHg\n"
        "- 体温：%8 °C\n"
        "- 肺活量：%9 ml\n\n"
        "请提供：\n"
        "1. 各项指标评估\n"
        "2. 健康风险分析\n"
        "3. 具体建议\n"
    ).arg(data.sex)
     .arg(data.height)
     .arg(data.weight)
     .arg(data.bmi, 0, 'f', 1)
     .arg(data.heartRate)
     .arg(data.systolicBP)
     .arg(data.diastolicBP)
     .arg(data.temperature)
     .arg(data.vitalCapacity);
}

QString AIHealthService::performRequest(const QJsonObject& requestBody)
{
    QNetworkRequest request;
    request.setUrl(QUrl(apiEndpoint));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // 设置认证头
    switch (currentProvider) {
    case OpenAI:
    case DeepSeek:
    case AlibabaQwen:
        request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());
        break;
    case BaiduWenxin:
        request.setUrl(QUrl(QString("%1?access_token=%2").arg(apiEndpoint, apiKey)));
        break;
    case TencentHunyuan:
        request.setRawHeader("Authorization", apiKey.toUtf8());
        break;
    }

    QJsonDocument doc(requestBody);
    QByteArray postData = doc.toJson();

    // 打印请求信息用于调试
    qDebug() << "Sending request to:" << apiEndpoint;
    qDebug() << "Request body:" << postData;

    QNetworkReply* reply = networkManager->post(request, postData);

    // 同步等待响应
    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    timer.start(60000); // 60秒超时

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    connect(&timer, &QTimer::timeout, [&]() {
        if (reply->isRunning()) {
            reply->abort();
            lastError = "请求超时";
        }
        loop.quit();
    });

    loop.exec();

    QString result;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "API response:" << responseData;

        QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);
        result = parseResponse(responseDoc.object());

        if (result.isEmpty()) {
            lastError = "无法解析API响应";
        }
    } else {
        lastError = QString("网络错误: %1").arg(reply->errorString());
    }

    reply->deleteLater();
    return result;
}

QString AIHealthService::parseResponse(const QJsonObject& response)
{
    switch (currentProvider) {
    case OpenAI:
    case DeepSeek:
        if (response.contains("choices")) {
            QJsonArray choices = response["choices"].toArray();
            if (!choices.isEmpty()) {
                QJsonObject firstChoice = choices[0].toObject();
                if (firstChoice.contains("message")) {
                    return firstChoice["message"].toObject()["content"].toString();
                }
            }
        }
        break;

    case BaiduWenxin:
        if (response.contains("result")) {
            return response["result"].toString();
        }
        break;

    case AlibabaQwen:
        if (response.contains("output")) {
            QJsonObject output = response["output"].toObject();
            if (output.contains("text")) {



                return output["text"].toString();
            }
        }
        break;

    case TencentHunyuan:
        if (response.contains("Response")) {
            QJsonObject responseObj = response["Response"].toObject();
            if (responseObj.contains("Choices")) {
                QJsonArray choices = responseObj["Choices"].toArray();
                if (!choices.isEmpty()) {
                    QJsonObject choice = choices[0].toObject();
                    if (choice.contains("Message")) {
                        return choice["Message"].toObject()["Content"].toString();
                    }
                }
            }
        }
        break;
    }

    return QString();
}
