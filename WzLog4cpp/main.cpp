#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>
#include "Log.h"

using namespace std;

int main()
{
	cout << "------begin-------" << endl;

	//Log::setLogPath("D:/project");

	//Log::setLogLevel(Log::WARNING);

	Log::d("debug");

	Log::w("warning");

	Log::e("error");

	cout << "��������˳�" << endl;
	getchar();

	return 0;
}


#endif // !_MAIN_H_
