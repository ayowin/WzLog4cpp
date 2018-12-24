#include "Log.h"

char Log::logLevel = Log::ERROR;
std::string Log::fileName = "";

void Log::setLogLevel(const char logLevel)
{
	Log::logLevel = logLevel;
}

void Log::setFileName(std::string fileName)
{
	Log::fileName = fileName;
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

void Log::d(char * content)
{
	std::string temp;
	temp.append(content);
	d(temp);
}

void Log::d(std::string content)
{
	if (Log::logLevel <= Log::DEBUG)
		toLogFile();
	std::cout << content.data()<< std::endl;
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

void Log::w(char * content)
{
	std::string temp;
	temp.append(content);
	w(temp);
}

void Log::w(std::string content)
{
	if (Log::logLevel <= Log::WARNING)
		toLogFile();
	std::cout << content.data() << std::endl;
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

void Log::e(char * content)
{
	std::string temp;
	temp.append(content);
	e(temp);
}

void Log::e(std::string content)
{
	if (Log::logLevel <= Log::ERROR)
		toLogFile();
	std::cout << content.data() << std::endl;
}

void Log::toLogFile()
{
}
