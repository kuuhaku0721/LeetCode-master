#include <iostream>
#include <string>
using namespace std;

/*
* 256MB空间开一个数组 每个元素都是32位数
* 256MB空间可以容纳多少个
*/


int main()
{
	cout << "hello world" << endl;
	cout << (256 * 1024 * 1024) * 8 / 32 << endl;

	system("pause");
	return 0;
}

