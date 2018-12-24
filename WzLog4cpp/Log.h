#ifndef _Log_H_
#define _Log_H_

/*
*	���ߣ�ŷ��ΰ
*	���ڣ�2018-12-24
*	�ࣺLog
*	��;����������ƽ̨��־�⣬�ο�����Ŀ�е�main.cppʹ�ü��ɣ��ܷ���
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
	static void d(char* content);
	static void d(std::string content);

	// warning
	static void w(char content);
	static void w(short content);
	static void w(int content);
	static void w(char* content);
	static void w(std::string content);

	// error
	static void e(char content);
	static void e(short content);
	static void e(int content);
	static void e(char* content);
	static void e(std::string content);

	// ������־�ȼ���Log::DEBUG��Log::WARNING��Log::ERROR
	static void setLogLevel(const char logLevel);
	// ������־·�����Ƽ�ʹ�ñ�׼·������,D:/
	static void setLogPath(std::string logPath);
	
private:
	// debug��0��warning��1��error��2
	static char logLevel;
	static std::string logPath;

	// ������ļ��ĺ���
	static void toLogFile(std::string content);
};

#endif 
