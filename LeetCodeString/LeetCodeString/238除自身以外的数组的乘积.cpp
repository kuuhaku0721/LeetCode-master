#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
* 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
* 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。 
*/

/*
* 不让用除法还得O(n)，前缀积？
* 虽然一眼就可以暴力循环，但肯定超时10次方了
* 用前缀积加后缀积，前缀数组第几个就是前几个数的乘积，后缀一样
* 然后结果数组只需要让前缀积当前位置左边的乘上后缀积当前位置右边的就行了
* 做是做出来了，就是时间比较慢，空间比较多而已，小问题，小问题
*/
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> prefixMulti(nums.size() + 1, 1);
		for (int i = 0; i < nums.size(); i++)
		{
			prefixMulti[i + 1] = prefixMulti[i] * nums[i];
		}
		vector<int> backMulti(nums.size() + 1, 1);
		for (int i = 0; i < nums.size(); i++)
		{
			backMulti[i + 1] = backMulti[i] * nums[nums.size() - i - 1];
		}
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			result.push_back(prefixMulti[i] * backMulti[nums.size() - i - 1]);
		}
		return result;
	}
};

int main()
{
	cout << "hello world" << endl;
	// vector<int> nums{ 1,2,3,4 };
	vector<int> nums{ -1,1,0,-3,3 };
	auto res = Solution().productExceptSelf(nums);
	cout << "结果" << endl;
	for (int i : res)
		cout << i << " ";
	cout << endl;

	system("pause");
	return 0;
}

