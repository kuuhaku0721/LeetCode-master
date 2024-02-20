#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
* 子数组 是数组中的一个连续部分。
*/

/*
* 暴力可以解，套两层循环就行，但很明显，不想用暴力，那干吧，不行就cv呗
* 贪心算法：局部最优推导出全局最优，但这个最优不一定是随时保证要递增式增长
* 从头开始遍历累加和，如果累加和加成了负数，那就从下一个位置重新开始计算
* 因为前面的已经加成负数了，再往后加只会拖累总和
* 那为什么不在总和减小的时候改变呢？因为就算总和一时减小了，但前面加起来仍然是个整数
* 前面的总和可以看成一个数，继续给后面的当作累加因子，对总体的累加和来说还是有利的
* 那万一后面的加起来没前面的大了呢，这就需要随时保存累加和了，只有累加和大的时候保存
* 这样无论加到多少，最后保存下来的仍然是最大数
* 
* 最开始设置sum = INT_MIN是因为防止累加和最大也是个负数
* 先保存最大值，再去判断是否从头开始，免得错过负数的最大和
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = INT_MIN;
		int tmp = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			tmp += nums[i];
			if (tmp > sum)
			{
				sum = tmp;
			}
			if (tmp <= 0)
			{
				tmp = 0;
			}
			
		}
		return sum;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
	int res = Solution().maxSubArray(nums);
	cout << "结果是：" << res << endl;

	system("pause");
	return 0;
}

