#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 样例输入
* 6 4
* 1 2 1
* 1 3 1
* 3 4 2
* 3 5 2
* 4 6 3
* 2 6 5 1
* 
* 样例输出
* 10 7 13 14
*/

void TourGuide()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> spot;
	vector<int> path(k);
	for (int i = 0; i < n - 1; i++)
	{
		vector<int> tmp(3);
		for (int i = 0; i < 3; i++)
		{
			cin >> tmp[i];
		}
		spot.emplace_back(tmp);
	}
	for (int i = 0; i < k; i++)
	{
		cin >> path[i];
	}

	cout << "当前spot数组: " << endl;
	for (auto vec : spot)
	{
		for (auto i : vec)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	cout << "当前怕path数组：" << endl;
	for (auto i : path)
	{
		cout << i << " ";
	}
	cout << endl;



	vector<int> res;
	// 当遍历的时候可以知道的是当前值和下一个值，刚好就是一站，然后到spot里面找是否有一个满足刚好有这俩数，有的话就加上[2]的距离，然后更新这俩数
	// 然后继续寻找
	for (int i = 0; i < path.size(); i++)
	{
		vector<int> currPath = path;
		currPath.erase(currPath.begin() + i);
		int len = 0;
		for (int j = 0; j < currPath.size() - 1; j++)
		{
			// 我需要拿到两个数，这个时候需要判断什么时候跳过
			int beg = currPath[j], end = currPath[j + 1];
			auto it = find_if(spot.begin(), spot.end(), [beg, end](vector<int>& vec) {
				cout << "这次要查找的路径是: " << beg << "--" << end << endl;
				return (vec[0] == beg && vec[1] == end) || (vec[1] == beg && vec[0] == end);
				});
			if(it != spot.end())
				len += (*it)[2];
		}
		res.push_back(len);
	}

	for (auto i : res)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	TourGuide();

	system("pause");
	return 0;
}

