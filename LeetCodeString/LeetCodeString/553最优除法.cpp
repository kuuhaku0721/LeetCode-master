#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 给定一正整数数组 nums，nums 中的相邻整数将进行浮点除法。例如， [2,3,4] -> 2 / 3 / 4 。
例如，nums = [2,3,4]，我们将求表达式的值 "2/3/4"。
但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。你需要找出怎么添加括号，以便计算后的表达式的值为最大值。
以字符串格式返回具有最大值的对应表达式。
注意：你的表达式不应该包含多余的括号。
*/

class Solution {
public:
	string optimalDivision(vector<int>& nums) {
		//sort(nums.rbegin(), nums.rend());
		if (nums.size() == 1) return to_string(nums[0]);
		if (nums.size() == 2)
		{
			int ma = max(nums[0], nums[1]);
			int mi = max(nums[0], nums[1]);
			return to_string(ma) + "/" + to_string(mi);
		}
		string res = to_string(nums[0]);
		res += "/(";
		for (int i = 1; i < nums.size(); i++)
		{
			if (i == nums.size() - 1)
				res += to_string(nums[i]) + ")";
			else
				res += to_string(nums[i]) + "/";
		}
		return res;
	}
};


int main()
{
	cout << "hello world" << endl;
	//vector<int> nums{ 2,3,4,5,6 };
	vector<int> nums{ 2 };
	string res = Solution().optimalDivision(nums);
	cout << res << endl;
	

	system("pause");
	return 0;
}

