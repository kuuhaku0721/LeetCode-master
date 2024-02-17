#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
* 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
*/

/*
* 在上一题（78）基础上加一个去重，前面做过类似的，去重可以单独去实现，问题是可能会超时
* 之前在处理去重问题的时候，用的是一个used数组解决的，但是好像没看懂，思路可以借鉴借鉴
* used数组中是将每一个元素都增加一个used使用位，当数组排序过后，相同的元素挨在一起
* 它们的used标志位全部置位，这样下一次循环开始时就会跳过所有相同的数字
* 所以判断方法主要是跳过相同位，那么其实也可以直接跳过
*/

class Solution1 {
public:
	vector<vector<int>> result;
	vector<int> vec;
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		if (nums.size() == 0) return result;
		sort(nums.begin(), nums.end());
		BackTracking(nums, -1);
		return result;
	}

	void BackTracking(vector<int>& nums, int index)
	{
		for (int i = index + 1; i < nums.size();)
		{
			vec.push_back(nums[i]);
			do
			{
				i++;
			} while (i < nums.size() && nums[i] == nums[index + 1]);
			BackTracking(nums, i - 1);
			vec.pop_back();
		}

		result.emplace_back(vec);
	}
};

/*
* 不行啊....去重的做法完全没掌握到，还得精进啊....
*/

class Solution {
private:
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
		result.push_back(path);
		for (int i = startIndex; i < nums.size(); i++) {
			// used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
			// used[i - 1] == false，说明同一树层candidates[i - 1]使用过
			// 而我们要对同一树层使用过的元素进行跳过
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
				continue;
			}
			path.push_back(nums[i]);
			used[i] = true;
			backtracking(nums, i + 1, used);
			used[i] = false;
			path.pop_back();
		}
	}

public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		result.clear();
		path.clear();
		vector<bool> used(nums.size(), false);
		sort(nums.begin(), nums.end()); // 去重需要排序
		backtracking(nums, 0, used);
		return result;
	}
};


int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 1,2,2, 3, 4 };
	auto result = Solution().subsetsWithDup(nums);
	for (vector<int> vec : result)
	{
		for (int i : vec)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

