#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个 rows x cols 的矩阵 grid 来表示一块樱桃地。 grid 中每个格子的数字表示你能获得的樱桃数目。
* 你有两个机器人帮你收集樱桃，机器人 1 从左上角格子 (0,0) 出发，机器人 2 从右上角格子 (0, cols-1) 出发。
* 请你按照如下规则，返回两个机器人能收集的最多樱桃数目：
* 从格子 (i,j) 出发，机器人可以移动到格子 (i+1, j-1)，(i+1, j) 或者 (i+1, j+1) 。
* 当一个机器人经过某个格子时，它会把该格子内所有的樱桃都摘走，然后这个位置会变成空格子，即没有樱桃的格子。
* 当两个机器人同时到达同一个格子时，它们中只有一个可以摘到樱桃。
* 两个机器人在任意时刻都不能移动到 grid 外面。
* 两个机器人最后都要到达 grid 最底下一行。
*/

/*
* 还是回溯，但是回溯的时候需要让两个robot同时往下走，形式上有点像N皇后
* 也就是，枚举所有情况，不能简单的判断走最大的，当前格最大不一定整条路径最大，所以需要遍历所有情况
*/
class Solution1 {
public:
	int sum;
	int cherryPickup(vector<vector<int>>& grid) {
		vector<vector<bool>> used(grid.size(), vector<bool>(grid[0].size(), false));
		sum = 0;
		BackTracking(grid, used, make_pair(0, 0), make_pair(0, grid[0].size() - 1), 0);
		return sum;
	}

	void BackTracking(vector<vector<int>>& grid, vector<vector<bool>>& used, pair<int, int> pt1, pair<int, int> pt2, int currsum)
	{
		if (pt1.first == grid.size() && pt2.first == grid.size())
		{
			sum = max(currsum, sum);
			return;
		}

		// (i+1, j-1)，(i+1, j) 或者 (i+1, j+1)  pt1（右下，下） pt2（左下，下）
		// pt1和pt2单独分开判断，这样可以省去判断0的情况
		// 除非开俩线程，否则一定是一边走完才会走另外一边，那pt1和2的前后顺序就没那么重要了，直接写就可以了
		if (pt1.first != grid.size() && pt1.second != grid[0].size())
		{
			if (used[pt1.first][pt1.second] == false)
			{
				// 累加，置位
				currsum += grid[pt1.first][pt1.second];
				sum = max(sum, currsum);
				used[pt1.first][pt1.second] = true;
			}
			// 下一个
			// 左下
			if (pt1.second >= 1)
			{
				BackTracking(grid, used, make_pair(pt1.first + 1, pt1.second - 1), pt2, currsum);
			}
			// 下
			BackTracking(grid, used, make_pair(pt1.first + 1, pt1.second), pt2, currsum);
			// 右下
			if (pt1.second < grid.size())
			{
				BackTracking(grid, used, make_pair(pt1.first + 1, pt1.second + 1), pt2, currsum);
			}
		}
		if (pt2.first != grid.size() && pt2.second != grid[0].size())
		{
			// 累加，置位
			if (used[pt2.first][pt2.second] == false)
			{	// 如果没人来过，累加，否则的话+0，也就是略过去这一格，直接往后走
				currsum += grid[pt2.first][pt2.second];
				sum = max(sum, currsum);
				used[pt2.first][pt2.second] = true;
			}
			// 下一个
			// 左下
			if (pt2.second >= 1)
			{
				BackTracking(grid, used, pt1, make_pair(pt2.first + 1, pt2.second - 1), currsum);
			}
			// 下
			BackTracking(grid, used, pt1, make_pair(pt2.first + 1, pt2.second), currsum);
			// 右下
			if (pt2.second < grid.size())
			{
				BackTracking(grid, used, pt1, make_pair(pt2.first + 1, pt2.second + 1), currsum);
			}
		}
	}
};

// 官解的动规解法
// 动规的话，一个robot也能写，俩就不会了，呵呵呵呵
// 官解可以优化，判断每个robot行走的路径，从顶点开始都是三角形，所以可以设定遍历边界值，这样可以少遍历几次
class Solution {
public:
	int cherryPickup(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int>> f(n, vector<int>(n, -1)), g(n, vector<int>(n, -1));
		f[0][n - 1] = grid[0][0] + grid[0][n - 1];
		for (int i = 1; i < m; ++i) {
			for (int j1 = 0; j1 < n; ++j1) {
				for (int j2 = 0; j2 < n; ++j2) {
					int best = -1;
					for (int dj1 = j1 - 1; dj1 <= j1 + 1; ++dj1) {
						for (int dj2 = j2 - 1; dj2 <= j2 + 1; ++dj2) {
							if (dj1 >= 0 && dj1 < n && dj2 >= 0 && dj2 < n && f[dj1][dj2] != -1) {
								best = max(best, f[dj1][dj2] + (j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]));
							}
						}
					}
					g[j1][j2] = best;
				}
			}
			swap(f, g);
		}

		int ans = 0;
		for (int j1 = 0; j1 < n; ++j1) {
			for (int j2 = 0; j2 < n; ++j2) {
				ans = max(ans, f[j1][j2]);
			}
		}
		return ans;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<vector<int>> grid{
		{3,1,1},
		{2,5,1},
		{1,5,5},
		{2,1,1}
	};
	int res = Solution().cherryPickup(grid);
	cout << res << endl;

	system("pause");
	return 0;
}

