#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
*/

/*
* 与之前相比所不同的地方在于，以前回溯的时候每一轮起始位置都是通过传参数i决定，而在这里因为要保留所有的数
* 所以起始位置每次都得是0，也就是每次都要从头开始循环
* 那问题来了，每次都从头，要怎么确定这个数已经用过了？也就是第一个数存完之后下一轮过来又存一遍第一个数，然后每次都是第一个无穷无尽
* 这时候就需要一个标志位数组了，每一个数字跟随一个标志位，标识它是否已经用过了
* 然后循环开始的时候检查标志位即可
* 
* 。。。。。死活过不去，看来看去不知道哪错了，结果是因为多打个等号.....
*/

class Solution {
public:
	vector<vector<int>> result;
	vector<int> vec;
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() == 0) return result;
		vector<bool> used(nums.size(), false);
		BackTracking(nums, used);
		return result;
	}

	void BackTracking(vector<int>& nums, vector<bool>& used)
	{
		if (vec.size() == nums.size())
		{
			result.emplace_back(vec);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (used[i] == true) continue;
			used[i] = true;
			vec.push_back(nums[i]);
			BackTracking(nums, used);
			vec.pop_back();
			used[i] = false;
		}
	}
};


int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 1,2,3,4 };
	auto res = Solution().permute(nums);
	for (vector<int> v : res)
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

