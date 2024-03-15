#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
* 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
* 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
*/

/*
* 我怀疑一个map完事
*/

class Solution {
public:
	int majorityElement1(vector<int>& nums) {
		unordered_map<int, int> umap;
		for (int i : nums)
		{
			umap[i]++;
		}
		int res = 0;
		for (auto pair : umap)
		{
			if (pair.second > nums.size() / 2)
				res = pair.first;
		}
		return res;
	}
	// 卧槽我真是服了，你就不能不...不那啥吗
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

