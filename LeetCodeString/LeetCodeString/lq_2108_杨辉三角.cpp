#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 还好还好，杨辉三角还好说，只要别来动规就行
*/
/*
* 搞个二维矩阵出来，然后一边往里面塞数，一边记录塞进去了几个数，一边记录现在塞的数是几
* 如果碰到n就break，然后输出记录的总数
* 
* 超时了，不过问题不大，能写出来就行，估摸着能过一半
*/

int YanghuiRectangle()
{
	vector<vector<int>> vec;
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i <= n; i++)
	{
		vector<int> currFloor;
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				currFloor.push_back(1);
				cnt++;
			}
			else
			{
				int curr = vec[i - 1][j] + vec[i - 1][j - 1];
				if (curr == n)
					return cnt + 1;
				else
					currFloor.push_back(curr);
				cnt++;
			}
		}
		vec.emplace_back(currFloor);
	}
	return 0;
}


int main()
{
	cout << "hello world" << endl;
	cout << YanghuiRectangle() << endl;

	system("pause");
	return 0;
}

