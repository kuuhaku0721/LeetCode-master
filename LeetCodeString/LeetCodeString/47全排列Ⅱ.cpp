#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
*/

/*
* 一眼回溯
* 数组可重复，结果不重复
* 普通回溯，只需要path和result
* 如果需要考虑去重，就得先排序，然后增加一个used数组
*/

class Solution {
public:
	vector<int> path;
	vector<vector<int>> result;
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.empty()) return result;
		sort(nums.begin(), nums.end());
		vector<bool> used(nums.size(), false);
		BackTracking(nums, used);
		return result;
	}

	void BackTracking(vector<int>& nums, vector<bool>& used)
	{
		if (path.size() == nums.size())
		{
			result.push_back(path);
			return;
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
				continue;
			if (used[i] == false)
			{
				used[i] = true;
				path.push_back(nums[i]);
				BackTracking(nums, used);
				path.pop_back();
				used[i] = false;
			}
		}
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 1,1,2 };
	auto res = Solution().permuteUnique(nums);

	system("pause");
	return 0;
}

