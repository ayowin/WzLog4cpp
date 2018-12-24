#ifndef _Log_H_
#define _Log_H_

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

	static void setLogLevel(const char logLevel);
	static void setFileName(std::string fileName);
	
private:
	// debug£º0£¬warning£º1£¬error£º2
	static char logLevel;
	static std::string fileName;

	static void toLogFile();
};

#endif 
