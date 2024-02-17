#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组
[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
*/

/*
* 很好，超时
*/

/*
* 答案的思路，先算和，然后查找
* 
* 很好，用滑动窗口吧
* 
* 这解法...牛逼啊
*/

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int result = INT_MAX;
		//滑动窗口需要的三个值
		int sum = 0;  //窗口总和
		int beg = 0;  //窗口起始值
		int len = 0;  //窗口长度
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			while (sum >= target)
			{	//当综合大于target的时候进入循环
				len = i - beg + 1;  //窗口长
				result = min(result, len);
				sum -= nums[beg];  //减去窗口头
				beg++; //更改窗口起始位置
			}
		}

		return result == INT_MAX ? 0 : result;
	}
};


int main()
{
	cout << "hello world" << endl;

	vector<int> nums = { 1,2,3,4,5 };
	int target = 11;
	int res = Solution().minSubArrayLen(target, nums);
	cout << res << endl;

	system("pause");
	return 0;
}

