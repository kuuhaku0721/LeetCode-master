#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
* 说明：每次只能向下或者向右移动一步。
*/

/*
* 这个好说，dp[i][j]就是到当前位置的最大值,每次只能向右或者向下，所以直接遍历就完事了
*/

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
		// 方便起见，先初始化第一行  和第一列
		dp[0][0] = grid[0][0];
		// 第一行
		for (int i = 1; i < grid[0].size(); i++)
		{
			dp[0][i] = grid[0][i] + dp[0][i - 1];
			
		}
		// 第一列
		for (int i = 1; i < grid.size(); i++)
		{
			dp[i][0] = grid[i][0] + dp[i - 1][0];
		}

		for (int i = 1; i < grid.size(); i++)
		{
			for (int j = 1; j < grid[0].size(); j++)
			{
				dp[i][j] = min(grid[i][j] + dp[i - 1][j], grid[i][j] + dp[i][j - 1]);
			}
		}
		return dp[dp.size() - 1][dp[0].size() - 1];
	}
};



int main()
{
	cout << "hello world" << endl;
	// 1,3,1],[1,5,1],[4,2,1]
	vector<vector<int>> grid {
		{1, 2, 3},
		{4, 5, 6}
		/*{ 4, 2, 1 }*/
	};
	int res = Solution().minPathSum(grid);
	cout << res << endl;

	system("pause");
	return 0;
}

