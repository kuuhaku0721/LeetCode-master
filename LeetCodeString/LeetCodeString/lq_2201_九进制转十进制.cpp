#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
* 这是个填空题，也就是让手算的
* 这里就改成编程题写写，反正不难
*/

void NineToTen()
{
	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		res += (s[i] - '0') * pow(9, i);
	}
	cout << res << endl;
}


int main()
{
	cout << "hello world" << endl;
	NineToTen();

	system("pause");
	return 0;
}

