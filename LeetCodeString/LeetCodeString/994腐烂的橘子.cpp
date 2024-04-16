#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
* 值 0 代表空单元格；
* 值 1 代表新鲜橘子；
* 值 2 代表腐烂的橘子。
* 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
* 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
*/

/*
* 单纯的判断好说，但多半会超时
* 按照我自己简单的想法来看：遍历，遍历整个数组，如果遇到2就把它四周的下标保留，不能直接置位，会影响后面判断
* 然后把保留下来的索引位置进行置位，然后继续循环，如果某一轮循环遍历的时候，保留的结果是空，那就跳出循环，判断
* 判断是否还有1存在，有就返回-1，就是不可能，没有，返回分钟数
* 如果是2挨着2，不管
* 2挨着1，保留1
* 2挨着0，不管
* 
* 哦吼，过了，好欸
* 一遍过，时间不快三十多，但是空间少，将近90
*/

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int cnt = 0;
		while (true)
		{
			vector<pair<int, int>> indexs;
			for (int i = 0; i < grid.size(); ++i)
			{
				for (int j = 0; j < grid[i].size(); ++j)
				{
					if (grid[i][j] == 2)
					{
						// 上
						if (i - 1 >= 0 && grid[i - 1][j] == 1)
							indexs.emplace_back(i - 1, j);
						// 下
						if (i + 1 < grid.size() && grid[i + 1][j] == 1)
							indexs.emplace_back(i + 1, j);
						// 左
						if (j - 1 >= 0 && grid[i][j - 1] == 1)
							indexs.emplace_back(i, j - 1);
						// 右
						if (j + 1 < grid[i].size() && grid[i][j + 1] == 1)
							indexs.emplace_back(i, j + 1);
						// 用完就扔掉，避免影响后续判断
						grid[i][j] = 0;
					}
				}
			}
			if (indexs.empty())
				break;
			else
			{
				++cnt;
				for (auto pr : indexs)
				{
					grid[pr.first][pr.second] = 2;
				}
				
				cout << "当前cnt = " << cnt << endl;
				cout << "现在的数组为：" << endl;
				for (auto vec : grid)
				{
					for (auto i : vec)
						cout << i << " ";
					cout << endl;
				}
			}
		}
		// 最后判断是否还剩的有1
		for (auto vec : grid)
		{
			for (auto i : vec)
				if (i == 1)
					return -1;
		}
		return cnt;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<vector<int>> grid{
		{2,1,1},
		{1,1,0},
		{0,1,1}
	};
	int res = Solution().orangesRotting(grid);
	cout << res << endl;

	system("pause");
	return 0;
}

