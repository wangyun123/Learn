#include "../common/common.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <OpenThreads/Thread>

#ifdef _DEBUG
#pragma comment(lib, "../Debug/common.lib")
#else
#pragma comment(lib, "../Release/common.lib")
#endif


int ticket=10;
class MyThreads : public OpenThreads::Thread
{
public:
	MyThreads(std::string name) {this->name=name;}
	
	void run()
	{
		while(--ticket)
		{
			std::cout << name << ":" << ticket << std::endl;
		}
	}

private:
	std::string name;
};
int main()
{
	MyThreads thread1("thread A");
	MyThreads thread2("thread B");

	thread1.start();
	thread2.start();

	Sleep(30000);
	return 1;
}