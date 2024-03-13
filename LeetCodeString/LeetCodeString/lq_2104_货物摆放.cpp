#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

/*
* n = L * W * H
* 已知n = 2021041820210418
* 求 LWH的组合一共有多少种
* 
* 填空题 答案2430
*/

typedef long long LL;
auto n = 2021041820210418;

void PushCargo()
{
	vector<LL> vec;
	// 44, 955, 998 (44956000)
	LL idx = 0;
	for (LL i = 1; i * i <= n; i++)
	{
		if (n % i == 0) 
		{
			vec.push_back(i);
			if (n / i != i) vec.push_back(n / i);
		}
	}
	// 拿到所有因数之后，直接一个三重循环解决
	for (auto i : vec)
	{
		for (auto j : vec)
		{
			for (auto k : vec)
			{
				if (i * j * k == n) idx++;
			}
		}
	}

	cout << idx << endl;
}


int main()
{
	cout << "hello world" << endl;
	PushCargo();

	system("pause");
	return 0;
}

