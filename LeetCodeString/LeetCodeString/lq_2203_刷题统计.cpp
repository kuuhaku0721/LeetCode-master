#include <iostream>
#include <string>
using namespace std;


/*
* 样例输入
* 10 20 99
* 样例输出
* 8
*/

/*
* 这样子直接算会超时，所以正确解法肯定不是直接算，而是找规律
* 比如它需要几个a 几个b
*/

void CodingCnt()
{
	long long a, b, n;
	cin >> a >> b >> n;
	long long sum = 0;
	int i = 1;
	long long cnt = 0;
	while (sum < n)
	{
		if (i >= 1 && i <= 5)
		{
			sum += a;
			++i;
			++cnt;
		}
		else if (i == 6)
		{
			sum += b;
			++i;
			++cnt;
		}
		else if (i == 7)
		{
			sum += b;
			i = 1;
			++cnt;
		}
	}
	cout << cnt << endl;
}

void CodingCnt2()
{
	long long a, b, n, res = 0, hasDo = 0, weekDo = 0;
	cin >> a >> b >> n;
	// 每周做的题的数量是有限的，5*a+2*b，那直接除就行了,剩下的余数就说明不足一周，就可以直接减了
	weekDo = a * 5 + b * 2;
	if (n < weekDo) 
	{
		for (int i = 1; i <= 7; i++) 
		{
			if (i == 6 || i == 7)hasDo += b;
			else hasDo += a;
			res++;
			if (hasDo >= n) break;
		}
	}
	else 
	{
		res = n / weekDo;
		hasDo = weekDo * res;
		res *= 7;
		for (int i = 1; i <= 7; i++) 
		{
			if (hasDo >= n)break;
			if (i == 6 || i == 7)hasDo += b;
			else hasDo += a;
			res++;
		}
	}
	
	a = 84268782243324780;
	b = 71090475290812475;
	n = 959568671578137330;

	cout << res << endl;
}


int main()
{
	cout << "hello world" << endl;
	// CodingCnt();
	CodingCnt2();

	system("pause");
	return 0;
}

