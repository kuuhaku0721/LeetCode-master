#include <vector>
#include <iostream>
#include <string>
using namespace std;

/*
* 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
* 如果数组中不存在目标值 target，返回 [-1, -1]。
* 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
* 可以直接循环遍历，但是这样复杂度起码O(n)打底
* 也可以用find和rfind，但是需要迭代器转下标
* 那么问题来了O(logn)是怎么来的捏？
* emmmmmm
* so，这题原来是二分的意思啊，两次二分，左边查一次，右边查一次
* 虽然但是，我的find又何尝不是二分呢？
* 好吧还真不是，用的线性搜索，std::binary_search才是二分
*/

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		auto itleft = find(nums.begin(), nums.end(), target);
		if (itleft != nums.end())
			res.push_back(distance(nums.begin(), itleft));
		else
			res.push_back(-1);
		auto itright = find(nums.rbegin(), nums.rend(), target);
		if (itright != nums.rend())
			res.push_back(distance(itright, nums.rend()));
		else
			res.push_back(-1);
		return res;
		
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

