#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
* 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等
*/

/*
* 只有正整数，说明只会递增，两个子集元素相等，说明总和一定是2的倍数
* 所以其实就是找，是否存在一个子集，它的总和刚好等于数组总和的一半
* 但是，但是啊，这题是动规啊....
* 随想录有一个01背包问题，需要点时间去看看那个，并且还得是脑子够用的时候
*/

class Solution {
public:
	bool canPartition1(vector<int>& nums) {
		float target = accumulate(nums.begin(), nums.end(), 0.0) / 2;
		sort(nums.begin(), nums.end());
		float sum = 0;
		int slow = 0, fast = 0;
		while (fast < nums.size() && slow <= fast)
		{
			// 只能找到连续的正确答案，不连续的无法正确判断
			if (sum < target)
			{
				sum += nums[fast];
				fast++;
			}
			else if (sum > target)
			{
				sum -= nums[slow];
				slow++;
			}
			if (sum == target)
				return true;
			
		}
		return false;
	}

	bool canPartition(vector<int>& nums) {
		int sum = 0;

		// dp[i]中的i表示背包内总和
		// 题目中说：每个数组中的元素不会超过 100，数组的大小不会超过 200
		// 总和不会大于20000，背包最大只需要其中一半，所以10001大小就可以了
		vector<int> dp(10001, 0);
		// 求和
		sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 == 1) return false;
		int target = sum / 2;

		// 开始 01背包
		for (int i = 0; i < nums.size(); i++) {
			for (int j = target; j >= nums[i]; j--) { // 每一个元素一定是不可重复放入，所以从大到小遍历
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);  // 前面的都没用，重要的就这一行
			}
		}
		// 集合中的元素正好可以凑成总和target
		if (dp[target] == target) return true;
		return false;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 14,9,8,4,3,2 };
	if (Solution().canPartition(nums))
		cout << "true" << endl;
	else
		cout << "fasle" << endl;

	system("pause");
	return 0;
}

