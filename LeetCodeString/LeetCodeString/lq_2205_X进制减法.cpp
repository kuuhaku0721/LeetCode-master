#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/*
* 第一行 N进制最高值，最大是N，最小是2
* 之后四行
* A的位数、A的每一位高到低
* B的位数、B的每一位高到低
* A比B大，求A-B的最小值
* 因为A和B的进制表示一样，那自然A和B都是最小值的时候相减的结果最小
* 那问题就变成了，如何能让一个每一位进制都不一样的数转换成十进制之后最小（不一定非得十进制，只是为了统一进制，十进制好看）
* 首先，试一下全部都是2进制，不出意料的是不行，全都是二进制不是最小
* 看了一眼示例输入，找到规律了，每一位的进制都刚好比这一位(A和B的这一位最大值)大个1，这样就能保证它本身就是最小
* 如果太小那就是2进制，如果太大那就是11进制
* 还要注意一点，题目没说A和B的位数一样，所以还得对位数进行判断
*/

/*
* 很好，做不出来，连示例结果都得不出来，莫名其妙，放弃
*/

void XMinus()
{
	int N;
	cin >> N;
	int a;
	cin >> a;
	vector<int> numA(a);
	for (int i = 0; i < a; i++)
	{
		cin >> numA[i];
	}
	int b;
	cin >> b;
	vector<int> numB(b);
	for (int i = 0; i < b; i++)
	{
		cin >> numB[i];
	}
	int len = a >= b ? a : b;
	if (numA.size() < len)
	{
		for (int i = 0; i < len - numA.size(); i++)
		{
			numA.insert(numA.begin(), 0);
		}
	}
	if (numB.size() < len)
	{
		for (int i = 0; i < len - numB.size(); i++)
		{
			numB.insert(numB.begin(), 0);
		}
	}
	vector<int> base(len);
	for (int i = 0; i < len; i++)
	{
		int m = numA[i] >= numB[i] ? numA[i] : numB[i];
		if (m < 2)
			base[i] = 2;
		else if (m >= N)
			base[i] = N;
		else
			base[i] = m + 1;
	}
	long long A = 0;
	long long B = 0;
	// 每一位按照每一位的进制单独计算
	for (int i = 0; i < len; i++)
	{
		A += numA[i] * pow(base[i], base.size() - i - 1);
		B += numB[i] * pow(base[i], base.size() - i - 1);
	}
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	cout << (A - B) << endl;
}


int main()
{
	XMinus();
	

	system("pause");
	return 0;
}

