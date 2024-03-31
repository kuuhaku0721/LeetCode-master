#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

/*
* 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
* 假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
* 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
*/


/*
* 如果不考虑O(1)的额外空间，直接set秒了
* 但是如果用set，那就是O(n)的空间，没有限制时间，倒是可以count或者find，O(n方)的时间
* 不能修改原数组，也就是不能排序，所以如果想遍历只能从头到尾，多半超时
* 放弃，我的脑子接受不了这么高难度的内容
* 正解应该是快慢指针
*/

class Solution {
public:
	int findDuplicate1(vector<int>& nums) {
		set<int> hashset;
		for (int i : nums)
		{
			if (hashset.insert(i).second == false)
				return i;
		}
		return -1;
	}

	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0;
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);
		slow = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

