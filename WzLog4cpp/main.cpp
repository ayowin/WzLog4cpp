#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>
#include "Log.h"

using namespace std;

int main()
{
	cout << "------begin-------" << endl;

	Log::d('a');
	Log::d("bbb");
	Log::d((short)1);
	Log::d(2);
	Log::d((char*)"abc");

	cout << "------------���ú����-------------" << endl;

	Log::d(__LINE__);
	Log::d(__FILE__);
	Log::d(__DATE__);
	Log::d(__TIME__);


	cout << "��������˳�" << endl;
	getchar();

	return 0;
}


#endif // !_MAIN_H_
