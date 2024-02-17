#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 
[nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

测试用例 4个亿.....你是来恶心人的吧.....
*/

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		if (nums.size() <= 4)
		{
			long long sum = 0;
			for (int i : nums)
			{
				sum += i;
			}
			if (sum == target)
			{
				res.emplace_back(nums);
			}
			return res;
		}
		for (int i = 0; i < nums.size() - 3; i++)
		{
			if (i != 0)
			{
				if (nums[i] == nums[i - 1])
					continue;
			}
			for (int j = i + 1; j < nums.size() - 2; j++)
			{
				if (j != 0)
				{
					if (nums[j] == nums[j - 1])
						continue;
				}

				vector<int> tmpVec;
				int left = j + 1;
				int right = nums.size() - 1;
				while (left < right)
				{
					long long sum = 0;
					sum += nums[i];
					sum += nums[j];
					sum += nums[left];
					sum += nums[right];
					if (sum == target)
					{
						tmpVec.emplace_back(nums[i]);
						tmpVec.emplace_back(nums[j]);
						tmpVec.emplace_back(nums[left]);
						tmpVec.emplace_back(nums[right]);
						res.emplace_back(tmpVec);
						left++;
						right--;
					}
					else if (sum > target)
					{
						right--;
					}
					else if (sum < target)
					{
						left++;
					}

					if (tmpVec.size() != 0)
					{
						while (left < nums.size() && nums[left] == nums[left - 1])
						{
							left++;
						}
						if (right != (nums.size() - 1))
						{
							while (right >= 0 && nums[right] == nums[right + 1])
							{
								right--;
							}
						}

						tmpVec.clear();
					}
				}
			}
		}
		return res;
	}
};


int main()
{
	cout << "hello world" << endl;
	vector<int> nums = { 0,0,0,0 };
	int target = 0;
	vector<vector<int>> res = Solution().fourSum(nums, target);
	for (vector<int> vec : res)
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

