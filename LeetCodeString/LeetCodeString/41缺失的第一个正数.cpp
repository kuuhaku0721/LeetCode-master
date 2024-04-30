#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
* 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
* 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
*/


/*
* 按题目这个说法，我直接排序不就好了吗？排序，然后从第一个正数开始累加，只要断开，那就是它，直接返回
* 好了，现在问题变成了，怎么找到这个返回值，要求的是最小的返回值，问题是，这个最小，是从1开始算的..
* 
* 笑死，0.13% 
* 但不管怎么说，你就说做没做出来吧
*/
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		unordered_set<int> uset(nums.begin(), nums.end());
		int maxEle = *max_element(nums.begin(), nums.end());
		for (int i = 1; i <= maxEle; i++)
		{
			if (uset.find(i) == uset.end())
				return i;
		}
		if (maxEle <= 0) return 1;
		else return maxEle + 1;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

