#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

/*
* n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
* 你需要按照以下要求，给这些孩子分发糖果：
* 每个孩子至少分配到 1 个糖果。
* 相邻两个孩子评分更高的孩子会获得更多的糖果。
* 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
*/

/*
* 局部最优推导全局最优
* 局部最优：每两个之间大的数是小的数的数量加1，然后依次循环下去
* 需要额外准备一个同等大小的数组，初始值都是1，因为要保证每个人至少一个
* 
* 
* wocao我过了，困难题，过了，哟西，好啊好啊
*/

class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> candies(ratings.size(), 1);
		for (int i = 0; i < ratings.size() - 1; i++)
		{
			int one = ratings[i];
			int plusone = ratings[i + 1];
			if (one > plusone)
			{
				if (candies[i] <= candies[i + 1])
					candies[i] = candies[i + 1] + 1;
			}
			if (one < plusone)
			{
				if (candies[i] >= candies[i + 1])
					candies[i + 1] = candies[i] + 1;
			}
			// 评分相等，第二个开始还是一个
		}
		// 倒着再来一遍 
		for (int i = ratings.size() - 1; i > 0; i--)
		{
			int one = ratings[i];
			int minusone = ratings[i - 1];
			if (one > minusone)
			{
				if (candies[i] <= candies[i - 1])
					candies[i] = candies[i - 1] + 1;
			}
			if (one < minusone)
			{
				if (candies[i] >= candies[i - 1])
					candies[i - 1] = candies[i] + 1;
			}
		}
		cout << "现在的candies数组是：" << endl;
		for (int i : candies) { cout << i << " "; } cout << endl;

		return accumulate(candies.begin(), candies.end(), 0);
	}
};


int main()
{
	cout << "hello world" << endl;
	vector<int> ratings{ 1,2,87,87,87,2,1 };
	int res = Solution().candy(ratings);
	cout << res << endl;

	system("pause");
	return 0;
}

