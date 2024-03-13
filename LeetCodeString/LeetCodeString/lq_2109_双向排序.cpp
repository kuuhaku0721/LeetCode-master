#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 因为有部分排序的库函数存在，所以这题应该问题不大
* 就是题意比较难懂...
* 
* 能撑到3k级别，然后超时，不错了已经，因为有库函数所以特别省时间
* 基本可以算不占用时间就能完成，超时也就超时吧
*/

void SortPart()
{
	int n, m;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		vec[i] = i + 1;
	}
	for (int i = 0; i < m; i++)
	{
		int op, cnt;
		cin >> op >> cnt;
		// 闭区间，带两头
		if (op == 0)
		{	// a1 到 acnt 作降序
			sort(vec.begin(), vec.begin() + cnt, [](int& lp, int & rp) {
				return lp > rp;
				});
		}
		else
		{	// acnt 到 an 作升序
			sort(vec.begin() + cnt - 1, vec.end());
		}
	}
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	// cout << "hello world" << endl;
	SortPart();

	system("pause");
	return 0;
}

