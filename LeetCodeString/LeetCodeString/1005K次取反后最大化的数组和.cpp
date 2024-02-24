#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
* 给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
* 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
* 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
* 以这种方式修改数组后，返回数组 可能的最大和 。
*/

/*
* 先排序，排序完省事
* 然后找负数，开始取反
* 
* 时间100%  空间10% 笑死，库函数真好用
*/

class Solution {
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int i = 0;
		while (i < nums.size() && nums[i] < 0 && k > 0)
		{
			nums[i] = -nums[i];
			k--;
			i++;
		}
		if (k == 0)
		{	// 取反次数用完了，这个时候直接求和就行了
			return accumulate(nums.begin(), nums.end(), 0);
		}
		else if (k != 0 && k % 2 == 0)
		{	// k是偶数，可以循环取反结果还是正的，到这里就是负数已经全都变成了正数
			return accumulate(nums.begin(), nums.end(), 0);
		}
		else if (k != 0 && k % 2 != 0)
		{
			sort(nums.begin(), nums.end());
			nums[0] = -nums[0];
			return accumulate(nums.begin(), nums.end(), 0);
		}
		return 0;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ -4,-2,-3 };
	int k = 4;
	int sum = Solution().largestSumAfterKNegations(nums, k);
	cout << sum << endl;

	system("pause");
	return 0;
}

