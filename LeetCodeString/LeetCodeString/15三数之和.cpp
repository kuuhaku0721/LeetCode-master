#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
* 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。


代码随想录的解法
先排序
用双指针，最外层一个循环，指示第一个数
然后双指针，指示第二个和第三个数
循环判断相加结果是否为0
是 则加入结果集，然后继续  注意需要去重
不是，判断大小，如果大，右指针左移 小 左指针右移  当然，也需要去重

虽然时间空间 都很差吧，但是过了
过了就，万事大吉

*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (i != 0)
			{
				if (nums[i] == nums[i - 1])
					continue;
			}
			vector<int> tmpVec;
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				if (nums[i] + nums[left] + nums[right] == 0)
				{
					tmpVec.emplace_back(nums[i]);
					tmpVec.emplace_back(nums[left]);
					tmpVec.emplace_back(nums[right]);
					res.emplace_back(tmpVec);
					left++;
					right--;
				}
				else if (nums[i] + nums[left] + nums[right] > 0)
				{
					right--;
				}
				else if (nums[i] + nums[left] + nums[right] < 0)
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
		return res;
	}
};


int main()
{
	cout << "hello world" << endl;
	vector<int> nums = { -2,0,3,-1,4,0,3,4,1,1,1,-3,-5,4,0 };
	vector<vector<int>> res = Solution().threeSum(nums);
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

