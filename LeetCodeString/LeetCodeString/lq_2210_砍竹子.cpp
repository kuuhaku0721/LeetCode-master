#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

/*
* AcWing 4409 砍竹子
*/

/*
* 感觉暴力可以，每次都取最高值然后计算就行了，凡是遇到最高值相等的全都计算一遍
* 那，时间复杂度起码n方...呵，能过一点是一点
* 能过20%......
*/

void CutBamboo()
{
	int n;
	cin >> n;
	vector<int> bamboos(n);
	for (int i = 0; i < n; i++)
	{
		cin >> bamboos[i];

	}
	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		int tmpMax = *(max_element(bamboos.begin(), bamboos.end()));
		int changeValue = sqrt(tmpMax / 2 + 1);
		for (auto it = find(bamboos.begin(), bamboos.end(), tmpMax); it != bamboos.end(); ++it)
		{
			if (*it != tmpMax) break;
			*it = changeValue;
		}
		++res;
		if (accumulate(bamboos.begin(), bamboos.end(), 0) == bamboos.size())
			break;
	}
	cout << res << endl;
}

int main()
{
	CutBamboo();

	system("pause");
	return 0;
}

