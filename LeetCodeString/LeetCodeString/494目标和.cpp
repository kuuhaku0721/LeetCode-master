#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个非负整数数组 nums 和一个整数 target 。
* 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
* 
* 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
* 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
*/

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
		}
		if (abs(target) > sum) return 0;
		if ((target + sum) % 2 == 1) return 0;
		int bagSize = (target + sum) / 2;
		vector<int> dp(bagSize + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = bagSize; j >= nums[i]; --j)
			{
				dp[j] += dp[j - nums[i]];
			}
		}
		return dp[bagSize];
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

