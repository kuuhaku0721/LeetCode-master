#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。
* 仅有一个元素或者含两个不等元素的序列也视作摆动序列。
* 例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。
* 相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
* 子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。
* 给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。
*/

/*
* 这题看似是找给定的序列的，其实是找差值序列，最终结果返回插值序列的值+1即可
* 可以先从给定序列构造出来差值序列
* 然后在差值序列里面判断，找正负交替出现的
*/

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() == 1) return 1;
		else if (nums.size() == 2)
		{
			if (nums[0] != nums[1])
				return 2;
			else
				return 1;
		}
		vector<int> difference;
		for (int i = 1; i < nums.size(); i++)
		{
			int minus = nums[i] - nums[i - 1];
			if (minus != 0) difference.push_back(minus);		// TODO:可以优化，即放弃掉这个difference数组，直接一边减一边判断
		}
		// 从差值序列摘出去一部分来构造正负交替序列
		if (difference.size() == 0) return 1;
		bool flag = false;
		if (difference[0] > 0) flag = true; // 保存上一个的正负号，true代表正 false代表负
		int cnt = 1;
		for (int i = 1; i < difference.size(); i++)
		{
			if (difference[i] > 0 && flag == false)
			{
				cnt++;
				flag = true;
			}
			else if (difference[i] < 0 && flag == true)
			{
				cnt++;
				flag = false;
			}
		}
		return cnt + 1;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 1,17,5,10,13,15,10,5,16,8 };
	int res = Solution().wiggleMaxLength(nums);
	cout << "结果为：" << res << endl;

	system("pause");
	return 0;
}

