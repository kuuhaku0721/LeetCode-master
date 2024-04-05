#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
* 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的
* 子序列		不用连续，递增即可
*/

/*
* 有个思路，dp[i]就是nums[i]的前面比它小的数的个数
* 计算dp[i]需要找到它前面第一个比它小的数，在它基础上加1
* 
* 好欸，第一次做动规题，能够自己想出来自己做出来还能有个不错的效率
*/

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		dp[0] = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			int j = i - 1;
			int big = 0;
			bool flag = false; // 是否有比它小的存在的标志
			for (; j >= 0; --j)
			{	// 不能是第一个，得是最大那一个
				if (nums[i] > nums[j])
				{
					big = max(big, dp[j]);
					flag = true;
				}
			}
			if (flag) dp[i] = big + 1;	// 只有上面的if判断过，才说明有小于它的，需要增加
		}
		return (*max_element(dp.begin(), dp.end())) + 1;  // 最后+1是因为前面算的时候没算自己
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 10,9,2,5,3,7,101,18 };
	int res = Solution().lengthOfLIS(nums);
	cout << res << endl;

	system("pause");
	return 0;
}

