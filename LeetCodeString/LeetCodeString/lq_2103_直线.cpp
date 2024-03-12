#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 坐标值 x是[0, 19] y是[0, 20]
* 两点可以确定一条直线
* 问一共可以组成多少条不同的直线
* 
* 数学题，组成的不同的直线有俩指标可以判断，y=ax+b  判断a和b
* 最高也就420*420，直接遍历搜索
* 填空题，不用担心超时，只管暴力搜
*/

void Line()
{
	// y = ax + b;
	vector<pair<int, int>> points;
	vector<float> A;
	vector<float> B;
	for (int x = 0; x <= 19; x++)
	{
		for (int y = 0; y <= 20; y++)
		{
			points.emplace_back(make_pair(x, y));
		}
	}
	for (int i = 0; i < points.size() - 1; i++)
	{
		for (int j = i + 1; j < points.size(); j++)
		{
			float deltaY = (points[j].second - points[i].second) * 1.0;
			float deltaX = (points[j].first - points[i].first) * 1.0;
			float a;
			float b;
			if (deltaY == 0)
			{
				a = 0;
				b = points[j].second;
			}
			if (deltaX == 0)
			{
				a = -1;
				b = points[j].first;
			}
			if (deltaY != 0 && deltaX != 0)
			{
				a = deltaY / deltaX;
				b = points[i].second - (a * points[i].first);
			}
			
			int k;
			bool flag = true;
			for ( k = 0; k < A.size(); k++)
			{
				if (A[k] == a)
				{
					cout << "找到一个相同的斜率: " << a << endl;
					// 存在这个斜率 该判断偏差了
					if (B[k] != b)
					{	// 偏差相同 同一条直线，不管
						A.push_back(a);
						B.push_back(b);
						flag = false;
					}
				}
			}
			if (flag)
			{
				A.push_back(a);
				B.push_back(b);
			}
		}
	}
	cout << A.size() << endl;
}

int main()
{
	cout << "hello world" << endl;
	Line();

	system("pause");
	return 0;
}

