#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组
* （该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
* 测试用例的答案是一个 32-位 整数。
*/

/*
* 单层dp思路还是容易想出来的
* dp[i]就是乘到它的时候的乘积
* 只不过这个乘积要判断，如果跟他前面那个相比，更大了，则更新为这个大值 dp[i] = nums[i] * dp[i - 1]
* 如果变小了，那就不变化，dp[i] = nums[i]
*/

class Solution1 {
public:
	int maxProduct(vector<int>& nums) {
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int curr = dp[i - 1] * nums[i];
			// 除了判断乘积，还得判断一下和当前值相比哪个大
			// 也就是现在要比对的是三个值：curr乘积，dp[i - 1]上一个乘积，nums[i]当前值
			if (curr < dp[i - 1])
				dp[i] = nums[i];
			else
				dp[i] = max({ curr, dp[i - 1], nums[i] });

		}
		return *max_element(dp.begin(), dp.end());
	}
};

// 来看官方题解
// 一句话概括就是：因为有负数的出现会让最小变最大，最大变最小，所以在维护最大值dp的时候也要维护一个最小值dp
// 评论区的大佬们的一个比较精明的写法是先遍历一遍找最大，再反过来一遍找最小

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		vector <int> maxF(nums), minF(nums);
		for (int i = 1; i < nums.size(); ++i) {
			maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
			minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
		}
		return *max_element(maxF.begin(), maxF.end());
	}
};


int main()
{
	cout << "hello world" << endl;
	// vector<int> nums{ 0,2 };
	// vector<int> nums{ 2,3,-2,4 };
	vector<int> nums{ -2,3,-4 };		// 卡在这个用例过不去了
	int res = Solution().maxProduct(nums);
	cout << res << endl;

	system("pause");
	return 0;
}

