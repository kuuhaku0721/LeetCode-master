#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
* 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
* 请你计算并返回达到楼梯顶部的最低花费。
*/
/*
* 翻译成人话：循环的时候，每次都选下一个位置和第二个位置中小的哪一个
* 寄喽，还是看答案吧
*/

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		vector<int> dp(cost.size() + 1);
		dp[0] = 0;
		dp[1] = 0;
		for (int i = 2; i <= cost.size(); i++)
		{
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[cost.size()];
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> cost{ 10,15,20 };
	int res = Solution().minCostClimbingStairs(cost);
	cout << res << endl;

	system("pause");
	return 0;
}

