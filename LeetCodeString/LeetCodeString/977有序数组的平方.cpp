#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
*/

/*
* 可以原地平方，然后排序
* 排序就，直接库函数吧
*/

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			nums[i] = pow(nums[i], 2);
		}
		sort(nums.begin(), nums.end());
		return nums;
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

