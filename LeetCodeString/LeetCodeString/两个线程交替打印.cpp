#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex m_mutex;
condition_variable cond;
bool flag = false;

void printA()
{
	unique_lock<mutex> lock(m_mutex);
	for (int i = 0; i < 10; i++)
	{
		while (flag)
		{
			cond.wait(lock);
		}
		cout << "A" << endl;
		flag = !flag;
		cond.notify_all();
	}
}

void printB()
{
	unique_lock<mutex> lock(m_mutex);
	for (int i = 0; i < 10; i++)
	{
		while (!flag)
		{
			cond.wait(lock);
		}
		cout << "B" << endl;
		flag = !flag;
		cond.notify_all();
	}
}



int main()
{
	thread ta(printA);
	thread tb(printB);

	ta.join();
	tb.join();

	system("pause");
	return 0;
}

