#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
* 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
*/

/*
* 总结上一题的经验教训，不要拘泥于数组本身，要从数组里面找规律出来
* 
* 当前下标所在位置的数字过后，其所代表的数字是否大于剩余个数
* 遍历全部，如果全都为true，则返回true，有一个false，直接返回false
* 还有个判断是，如果某一轮循环中，已经判断到等于0了，那就是已经到终点了，就可以不继续了
* 可以不用比较，都已经算出来剩余了，那就直接拿剩余量来判断就可以了，那样的话，remain需要拿到外面来了
* 里面判断还会有最后一个没法判断的情况
* 还少一种情况.......mmp的不愧是中等
* 考虑了全都走的情况，没考虑能不能走的情况,如果第一个就是0那根本就没法进行，更别提能不能到了
* 。。。。。八次啊，八次...我提交了八次！
* 你知道这八次我是怎么过的吗......
*/

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() == 1) return true;
		bool flag = true;
		int remain = 0;
		int reachable = nums[0];
		if (reachable == 0) return false;

		for (int i = 0; i <= reachable; i++) // 最后一格不用跳，只需要到达就行
		{
			remain = nums.size() - (i + 1) - nums[i];
			if (remain <= 0)
				break;
			reachable = max(reachable, i + nums[i]);
			if (reachable >= nums.size() - 1) reachable = nums.size() - 1;
		}
		if (remain > 0) flag = false; // 到这里是因为里面的已经全部循环完了也没有返回，说明到最后一个了，剩余还有

		return flag;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 2,5,0,0};
	if (Solution().canJump(nums))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}

