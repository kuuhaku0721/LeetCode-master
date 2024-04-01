#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
* 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
* 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
*/

/*
* dp公式：猜测一下
* 每一个位置需要保留的是
*   当前位置+前前一个位置的和（上一家没偷，偷了当前这一家）
* 与
*   前一个位置
* 相比，留下最大的那个（上一家偷了，当前这一家不能偷了）
*/

/*
* 很好，很棒，我做出来了
*/

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() <= 2)
			return *max_element(nums.begin(), nums.end());
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
		for (int i = 2; i < nums.size(); i++)
		{
			int cur = nums[i] + dp[i - 2];	// 上一家没偷，偷现在这一家
			int prev = dp[i - 1];			// 上一家偷了，现在这一家不能偷了
			dp[i] = max(cur, prev);
		}
		return dp[dp.size() - 1];
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 1,2,3,1 };
	cout << Solution().rob(nums) << endl;

	system("pause");
	return 0;
}

