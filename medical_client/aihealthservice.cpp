#include "aihealthservice.h"
#include <QDebug>
#include <QUrl>

AIHealthService::AIHealthService()
    : networkManager(new QNetworkAccessManager())
    , currentProvider(OpenAI)
{
}

AIHealthService::~AIHealthService()
{
    delete networkManager;
}

void AIHealthService::setAPIConfiguration(AIProvider provider, const QString& apiKey, const QString& endpoint)
{
    this->currentProvider = provider;
    this->apiKey = apiKey;

    if (!endpoint.isEmpty()) {
        this->apiEndpoint = endpoint;
    } else {
        this->apiEndpoint = getDefaultEndpoint(provider);
    }
}

QString AIHealthService::analyzeHealthData(const HealthData& data)
{
    if (!isConfigured()) {
        lastError = "AI服务未配置，请先设置API密钥";
        return QString();
    }

    QNetworkRequest request;
    request.setUrl(QUrl(apiEndpoint));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // 根据不同的AI服务设置请求头
    switch (currentProvider) {
    case OpenAI:
        request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());
        break;
    case BaiduWenxin:
        {
            QString urlWithToken = QString("%1?access_token=%2").arg(apiEndpoint, apiKey);
            request.setUrl(QUrl(urlWithToken));
        }
        break;
    case AlibabaQwen:
        request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());
        request.setRawHeader("X-DashScope-SSE", "disable");
        break;
    case TencentHunyuan:
        request.setRawHeader("Authorization", apiKey.toUtf8());
        break;
    // 在switch语句中添加
    case DeepSeek:
        request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());
        break;
    }

    request.setRawHeader("User-Agent", "MedicalHealthApp/1.0");

    QJsonObject requestBody = buildRequestBody(data);

    return performSyncRequest(request, requestBody);
}

bool AIHealthService::isConfigured() const
{
    return !apiKey.isEmpty() && !apiEndpoint.isEmpty();
}

QString AIHealthService::getProviderName() const
{
    switch (currentProvider) {
    case OpenAI: return "OpenAI GPT";
    case BaiduWenxin: return "百度文心一言";
    case AlibabaQwen: return "阿里云通义千问";
    case TencentHunyuan: return "腾讯混元";
    case DeepSeek: return "DeepSeek";
    default: return "未知服务";
    }
}

QString AIHealthService::getLastError() const
{
    return lastError;
}

QJsonObject AIHealthService::buildRequestBody(const HealthData& data)
{
    QJsonObject requestBody;
    QString prompt = buildHealthPrompt(data);

    switch (currentProvider) {
    case OpenAI:
        {
            requestBody["model"] = "gpt-3.5-turbo";
            requestBody["max_tokens"] = 2000;
            requestBody["temperature"] = 0.7;

            QJsonArray messages;
            QJsonObject systemMessage;
            systemMessage["role"] = "system";
            systemMessage["content"] = "你是一位专业的健康顾问。请根据用户提供的健康数据，给出专业、个性化的健康评估和建议。请用中文回答，内容要包含各项指标评估、健康风险、具体建议等。";
            messages.append(systemMessage);

            QJsonObject userMessage;
            userMessage["role"] = "user";
            userMessage["content"] = prompt;
            messages.append(userMessage);

            requestBody["messages"] = messages;
        }
        break;

    case DeepSeek:
        {
            requestBody["model"] = "deepseek-chat";  // 或者使用其他DeepSeek模型
            requestBody["max_tokens"] = 2000;
            requestBody["temperature"] = 0.7;

            QJsonArray messages;
            QJsonObject systemMessage;
            systemMessage["role"] = "system";
            systemMessage["content"] = "你是一位专业的健康顾问。请根据用户提供的健康数据，给出专业、个性化的健康评估和建议。请用中文回答，内容要包含各项指标评估、健康风险、具体建议等。";
            messages.append(systemMessage);

            QJsonObject userMessage;
            userMessage["role"] = "user";
            userMessage["content"] = prompt;
            messages.append(userMessage);

            requestBody["messages"] = messages;
        }
        break;

    case BaiduWenxin:
        {
            QJsonArray messages;
            QJsonObject message;
            message["role"] = "user";
            message["content"] = "请作为专业健康顾问，分析以下健康数据：\n" + prompt;
            messages.append(message);

            requestBody["messages"] = messages;
            requestBody["temperature"] = 0.7;
            requestBody["max_output_tokens"] = 2000;
        }
        break;

    case AlibabaQwen:
        {
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
        }
        break;

    case TencentHunyuan:
        {
            QJsonArray messages;
            QJsonObject message;
            message["Role"] = "user";
            message["Content"] = prompt;
            messages.append(message);
            requestBody["Messages"] = messages;
        }
        break;
    }

    return requestBody;
}

QString AIHealthService::buildHealthPrompt(const HealthData& data)
{
    QString prompt = QString(
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
        "3. 饮食建议\n"
        "4. 运动建议\n"
        "5. 生活方式建议\n"
        "6. 就医建议\n\n"
        "请用专业但易懂的中文回答。"
    ).arg(data.sex)
     .arg(data.height)
     .arg(data.weight)
     .arg(data.bmi, 0, 'f', 1)
     .arg(data.heartRate)
     .arg(data.systolicBP)
     .arg(data.diastolicBP)
     .arg(data.temperature)
     .arg(data.vitalCapacity);

    return prompt;
}

QString AIHealthService::performSyncRequest(const QNetworkRequest& request, const QJsonObject& requestBody)
{
    QJsonDocument requestDoc(requestBody);
    QNetworkReply* reply = networkManager->post(request, requestDoc.toJson());

    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    timer.setInterval(30000); // 30秒超时

    // 连接信号
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);

    timer.start();
    loop.exec(); // 等待响应或超时

    QString result;

    if (timer.isActive()) {
        timer.stop();

        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);
            QJsonObject responseObj = responseDoc.object();

            result = parseResponse(responseObj);

            if (result.isEmpty()) {
                lastError = "AI响应解析失败";
            }
        } else {
            lastError = QString("网络请求失败：%1").arg(reply->errorString());
        }
    } else {
        reply->abort();
        lastError = "请求超时";
    }

    reply->deleteLater();
    return result;
}

QString AIHealthService::parseResponse(const QJsonObject& response)
{
    switch (currentProvider) {
    case DeepSeek:
        // DeepSeek使用与OpenAI相同的响应格式
        if (response.contains("choices")) {
            QJsonArray choices = response["choices"].toArray();
            if (!choices.isEmpty()) {
                QJsonObject firstChoice = choices[0].toObject();
                QJsonObject message = firstChoice["message"].toObject();
                return message["content"].toString();
            }
        }
        break;

    case OpenAI:
        if (response.contains("choices")) {
            QJsonArray choices = response["choices"].toArray();
            if (!choices.isEmpty()) {
                QJsonObject firstChoice = choices[0].toObject();
                QJsonObject message = firstChoice["message"].toObject();
                return message["content"].toString();
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
                        QJsonObject message = choice["Message"].toObject();
                        return message["Content"].toString();
                    }
                }
            }
        }
        break;
    }

    return QString();
}

QString AIHealthService::getDefaultEndpoint(AIProvider provider) const
{
    switch (provider) {
    case OpenAI:
        return "https://api.openai.com/v1/chat/completions";
    case BaiduWenxin:
        return "https://aip.baidubce.com/rpc/2.0/ai_custom/v1/wenxinworkshop/chat/completions";
    case AlibabaQwen:
        return "https://dashscope.aliyuncs.com/api/v1/services/aigc/text-generation/generation";
    case TencentHunyuan:
        return "https://hunyuan.tencentcloudapi.com/";
    case DeepSeek:
            return "https://api.deepseek.com/v1/chat/completions";
    default:
        return "";
    }
}
