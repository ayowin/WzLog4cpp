#ifndef _Log_H_
#define _Log_H_

/*
*	作者：欧阳伟
*	日期：2018-12-24
*	类：Log
*	用途：轻量级跨平台日志库，参考本项目中的main.cpp使用即可，很方便
*/

#include <iostream>
#include <string>

class Log
{
public:
    static const char DEBUG = 0;
    static const char WARNING = 1;
    static const char ERROR = 2;

    // debug
    static void d(char content);
    static void d(short content);
    static void d(int content);
    static void d(long content);
    static void d(long long content);
    static void d(float content);
    static void d(double content);
    static void d(char* content);
    static void d(std::string content);

    // warning
    static void w(char content);
    static void w(short content);
    static void w(int content);
    static void w(long content);
    static void w(long long content);
    static void w(float content);
    static void w(double content);
    static void w(char* content);
    static void w(std::string content);

    // error
    static void e(char content);
    static void e(short content);
    static void e(int content);
    static void e(long content);
    static void e(long long content);
    static void e(float content);
    static void e(double content);
    static void e(char* content);
    static void e(std::string content);

    // 设置日志等级，Log::DEBUG，Log::WARNING，Log::ERROR
    static void setLogLevel(const char logLevel);
    // 设置日志路径，推荐使用标准路径，如,D:/
    static void setLogPath(std::string logPath);

private:
    // debug：0，warning：1，error：2
    static char logLevel;
    static std::string logPath;

    // 输出到文件的函数
    static void toLogFile(std::string content);
};

#endif
