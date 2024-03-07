#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
* 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
* 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
* 网格中的障碍物和空位置分别用 1 和 0 来表示。
*/

// 首先说明，这题不会写，所以直接cv了，先学习，然后再做题
/*
* 动规五部曲：
* 1、确定dp数组及下标含义:一般对动规来说 dp[i][j]的值表示到该位置有几种方法，每一步都是前面几步的累加
* 2、确定递推公式
* 3、确定如何初始化dp数组
* 4、确定遍历顺序
* 5、举例推导dp数组
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();    // 行数
        int n = obstacleGrid[0].size(); // 列数
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) //如果在起点或终点出现了障碍，直接返回0
            return 0;

        // 初始化dp数组
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 注意初始化数，[i][j]表示的是从起点到这个位置有几种方法，如果碰到障碍物直接返回不需要再继续，因为只能向右或向下不能回退
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;

        // 循环遍历，进行递推计算
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // 等于1就是碰到障碍物了，走不了这个格子，自然当前ij对应的dp数组的位置也不用变化
                if (obstacleGrid[i][j] == 1) continue;
                // 除此之外的地方都累加
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

