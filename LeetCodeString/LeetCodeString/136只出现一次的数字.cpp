#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
* 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
*/

class Solution {
public:
	int singleNumber1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] != nums[i + 1])
				return nums[i];
			else
				++i;
		}
		return nums[nums.size() - 1];
	}
	// 艹了啊，一个异或结束了
	int singleNumber(vector<int>& nums) {
		int res = nums[0];
		for (int i : nums)
		{
			res ^= i;
		}
		return res;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

