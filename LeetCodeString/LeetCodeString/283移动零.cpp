#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
* 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
* 4ms 99%
*/

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int slow = 0, fast = 0;
		while (fast < nums.size())
		{
			if (nums[fast] != 0)
			{
				nums[slow] = nums[fast];
				++slow;
				++fast;
			}
			else
				++fast;
		}
		// 最后要把后面几个都置0
		for (int i = slow; i < nums.size(); i++)
		{
			nums[i] = 0;
		}
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

