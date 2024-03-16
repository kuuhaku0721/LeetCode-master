#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
* 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
* 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/

/*
* O(n)就是一次遍历，但是遍历前需要先排序
* 不要求连续，那就不用排序了，直接转存，让set去排序，顺带去重
*/

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.empty()) return 0;
		set<int> oset(nums.begin(), nums.end());
		for (auto i : oset)
			cout << i << " ";
		cout << endl;
		int ans = 0;
		int cnt = 0;
		for (auto it = ++oset.begin(); it != oset.end(); ++it)
		{
			auto pre = it; --pre;
			if (*it - 1 == *pre)
				++cnt;
			else
			{
				ans = max(ans, cnt + 1);
				cnt = 0;
			}
		}
		ans = max(ans, cnt + 1);

		return ans;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 1,2,0,1 };
	int res = Solution().longestConsecutive(nums);
	cout << res << endl;

	system("pause");
	return 0;
}

