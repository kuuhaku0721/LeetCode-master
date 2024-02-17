#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

/*
* 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
* 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
* 
* 实在做不出来了看了眼答案，然后发现，捏嘛的不用连着，不是子集，是子序列，只要是从里面挑出来的就行，不需要递增的连续子序列
* 我t……&*#￥%……&￥#@……&……
* 虽然照着原本的写法，要连着的也不对，原本的写法只取了从0开始的，也就是只取了第一层，第二层开始就没取了
* 修改过后，问题就又回到之前的问题上了，怎么去重...
*/

class Solution1 {
public:
	vector<vector<int>> result;
	vector<int> vec;
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		if (nums.size() == 0) return result;
		BackTracking(nums, 0);
		return result;
	}

	void BackTracking(vector<int>& nums, int index)
	{
		if (vec.size() > 1)
		{
			result.emplace_back(vec);
		}

		unordered_set<int> uset;
		for (int i = index; i< nums.size();)
		{
			if (uset.find(nums[i]) != uset.end())
			{
				i++;
				continue;
			}
			vec.push_back(nums[i]);
			uset.insert(nums[i]);
			i++;
			if (i == nums.size() || nums[i] >= nums[index])
			{
				BackTracking(nums, i);
				vec.pop_back();
			}
			else
				result.push_back(vec);
		}
	}
};

/*
* 最终还是没写出来，靠答案过关.....
* 有点耻辱.....
* 但我脑子真的不好使啊...
*/

class Solution {
private:
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(vector<int>& nums, int startIndex) {
		if (path.size() > 1) {
			result.push_back(path);
			// 注意这里不要加return，要取树上的节点
		}
		unordered_set<int> uset; // 使用set对本层元素进行去重
		for (int i = startIndex; i < nums.size(); i++) {
			if ((!path.empty() && nums[i] < path.back())
				|| uset.find(nums[i]) != uset.end()) {
				continue;
			}
			uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
			path.push_back(nums[i]);
			backtracking(nums, i + 1);
			path.pop_back();
		}
	}
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		result.clear();
		path.clear();
		backtracking(nums, 0);
		return result;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 4,4,3,2,1 };
	auto result = Solution().findSubsequences(nums);
	for (vector<int> v : result)
	{
		for (int i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

