#include "Log.h"
#include <fstream>
#include <ctime>

char Log::logLevel = Log::ERROR;
std::string Log::logPath = "";

void Log::setLogLevel(const char logLevel)
{
    Log::logLevel = logLevel;
}

void Log::setLogPath(std::string logPath)
{
    // 默认分隔符为'/'
    char seperator = '/';

    // 遍历，自动找当前路径中的分隔符；
    for (std::string::iterator i = logPath.begin();i != logPath.end();i++)
    {
        if (*i == '/' || *i == '\\')
        {
            seperator = *i;
            break;
        }
    }

    if (logPath.at(logPath.length() - 1) != seperator)
        logPath += seperator;

    Log::logPath = logPath;
}

void Log::d(char content)
{
    std::string temp;
    temp.push_back(content);
    d(temp);
}

void Log::d(short content)
{
    d(std::to_string(content));
}

void Log::d(int content)
{
    d(std::to_string(content));
}

void Log::d(long content)
{
    d(std::to_string(content));
}

void Log::d(long long content)
{
    d(std::to_string(content));
}

void Log::d(float content)
{
    d(std::to_string(content));
}

void Log::d(double content)
{
    d(std::to_string(content));
}

void Log::d(char * content)
{
    std::string temp;
    temp.append(content);
    d(temp);
}

void Log::d(std::string content)
{
    // 获取当前运行时间，精确到秒
    time_t timeT = time(NULL);
    tm time;
    localtime_s(&time,&timeT);

    // 组织字符串
    std::string temp;
    temp.append(std::to_string(time.tm_year + 1900)); // 年
    temp += "-";
    temp.append(std::to_string(time.tm_mon + 1)); // 月
    temp += "-";
    temp.append(std::to_string(time.tm_mday)); // 日
    temp += " ";
    temp.append(std::to_string(time.tm_hour)); // 时
    temp += ":";
    temp.append(std::to_string(time.tm_min)); // 分
    temp += ":";
    temp.append(std::to_string(time.tm_sec)); // 秒
    temp += " ";
    temp += "[debug]: ";
    temp += content;

    if (Log::logLevel <= Log::DEBUG)
        toLogFile(temp);

    std::cout << temp.data()<< std::endl;
}

void Log::w(char content)
{
    std::string temp;
    temp.push_back(content);
    w(temp);
}

void Log::w(short content)
{
    w(std::to_string(content));
}

void Log::w(int content)
{
    w(std::to_string(content));
}

void Log::w(long content)
{
    w(std::to_string(content));
}

void Log::w(long long content)
{
    w(std::to_string(content));
}

void Log::w(float content)
{
    w(std::to_string(content));
}

void Log::w(double content)
{
    w(std::to_string(content));
}

void Log::w(char * content)
{
    std::string temp;
    temp.append(content);
    w(temp);
}

void Log::w(std::string content)
{
    // 获取当前运行时间，精确到秒
    time_t timeT = time(NULL);
    tm time;
    localtime_s(&time, &timeT);

    // 组织字符串
    std::string temp;
    temp.append(std::to_string(time.tm_year + 1900)); // 年
    temp += "-";
    temp.append(std::to_string(time.tm_mon + 1)); // 月
    temp += "-";
    temp.append(std::to_string(time.tm_mday)); // 日
    temp += " ";
    temp.append(std::to_string(time.tm_hour)); // 时
    temp += ":";
    temp.append(std::to_string(time.tm_min)); // 分
    temp += ":";
    temp.append(std::to_string(time.tm_sec)); // 秒
    temp += " ";
    temp += "[warning]: ";
    temp += content;

    if (Log::logLevel <= Log::WARNING)
        toLogFile(temp);
    std::cout << temp.data() << std::endl;
}

void Log::e(char content)
{
    std::string temp;
    temp.push_back(content);
    e(temp);
}

void Log::e(short content)
{
    e(std::to_string(content));
}

void Log::e(int content)
{
    e(std::to_string(content));
}

void Log::e(long content)
{
    e(std::to_string(content));
}

void Log::e(long long content)
{
    e(std::to_string(content));
}

void Log::e(float content)
{
    e(std::to_string(content));
}

void Log::e(double content)
{
    e(std::to_string(content));
}

void Log::e(char * content)
{
    std::string temp;
    temp.append(content);
    e(temp);
}

void Log::e(std::string content)
{
    // 获取当前运行时间，精确到秒
    time_t timeT = time(NULL);
    tm time;
    localtime_s(&time, &timeT);

    // 组织字符串
    std::string temp;
    temp.append(std::to_string(time.tm_year + 1900)); // 年
    temp += "-";
    temp.append(std::to_string(time.tm_mon + 1)); // 月
    temp += "-";
    temp.append(std::to_string(time.tm_mday)); // 日
    temp += " ";
    temp.append(std::to_string(time.tm_hour)); // 时
    temp += ":";
    temp.append(std::to_string(time.tm_min)); // 分
    temp += ":";
    temp.append(std::to_string(time.tm_sec)); // 秒
    temp += " ";
    temp += "[error]: ";
    temp += content;

    if (Log::logLevel <= Log::ERROR)
        toLogFile(temp);
    std::cout << temp.data() << std::endl;
}

void Log::toLogFile(std::string content)
{
    // 获取当前运行时间，精确到天
    time_t timeT = time(NULL);
    tm time;
    localtime_s(&time, &timeT);

    // 输出到文件
    std::ofstream out;
    std::string temp;
    temp.append(Log::logPath);
    temp.append(std::to_string(time.tm_year + 1900)); // 年
    temp += "-";
    temp.append(std::to_string(time.tm_mon + 1)); // 月
    temp += "-";
    temp.append(std::to_string(time.tm_mday)); // 日
    temp += ".txt";
    out.open(temp, std::ios::app);
    out << content<<"\n";
    out.close();
}
