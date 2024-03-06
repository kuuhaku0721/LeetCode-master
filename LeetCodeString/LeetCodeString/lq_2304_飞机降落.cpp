#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 样例输入
2
3
0 100 10
10 10 10
0 2 20
3
0 10 20
10 10 20
20 10 20

样例输出
YES
NO

样例说明
对于第一组数据，可以安排第3 33 架飞机于0 00 时刻开始降落，20 2020 时刻完成降落。安排第2 22 架飞机于20 2020 时刻开始降落，30 3030 时刻完成降落。安排第1 11 架飞机于30 3030 时刻开始降落，40 4040 时刻完成降落。
对于第二组数据，无论如何安排，都会有飞机不能及时降落。
*/

vector<string> res;

// 很好，没做出来，先放着，大不了四小时怒开九道题

bool IsSafeLand(vector<vector<int>>& planes)
{
	// 现在数组中的顺序是：最早 最晚 用时
	// 直接让每一个都最晚到达，这样能够得到n个区间，直接看这n个区间是否会重叠就行了
	for (auto& vec : planes)
	{
		vec[1] += vec[0];
		vec[2] += vec[1];
	}
	// 现在的[1]是最晚到达，[2]是完成降落动作,也就是一个区间，现在就看这几个区间是否有重叠
	sort(planes.begin(), planes.end(), [](vector<int>& lp, vector<int>& rp) {
		return lp[1] == rp[1] ? lp[2] < rp[2] : lp[1] < rp[1];
		});
	for (int i = 0; i < planes.size() - 1; i++)
	{
		if (planes[i][2] > planes[i + 1][1])
			return false;
	}
	
	return true;
}

void Landing()
{
	int n;
	cin >> n;
	vector<vector<int>> planes;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			vector<int> tmp;
			int p;
			for (int k = 0; k < 3; k++)
			{
				cin >> p;
				tmp.push_back(p);
			}
			planes.emplace_back(tmp);
		}
		// 输入完成，开始判断逻辑
		if (IsSafeLand(planes))
			res.emplace_back("YES");
		else
			res.push_back("NO");
		planes.clear();
	}
}



int main()
{
	cout << "hello world" << endl;
	Landing();
	for (auto s : res)
	{
		cout << s << endl;
	}

	system("pause");
	return 0;
}

