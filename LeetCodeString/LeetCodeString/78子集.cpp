#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
* 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
*/

/*
* 子集嘛，回溯嘛，还是那一套写法，只不过需要注意一点，子集包括空和本身
* 这题的难点在于，何时结束循环，子集，在范围内任何大小都有可能，那什么时候确定它要存储起来？
* 结论是，每次都存，每一个都算子集，所以每一个都存
* 
* 回溯可真**好用啊，只要能解决循环条件和结束条件两个问题，只要是回溯的题都能迎刃而解
*/

class Solution {
public:
	vector<vector<int>> result;
	vector<int> vec;
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.size() == 0) return result;
		BackTracking(nums, -1);
		return result;
	}

	void BackTracking(vector<int>& nums, int index)
	{
		for (int i = index + 1; i < nums.size(); i++)
		{
			vec.push_back(nums[i]);
			BackTracking(nums, i);
			vec.pop_back();
		}

		result.emplace_back(vec);
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

