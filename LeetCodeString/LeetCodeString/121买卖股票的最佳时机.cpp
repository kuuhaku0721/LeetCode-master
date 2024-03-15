#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
* 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
* 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/

/*
* 后减前，保留差值的最大值
* 如果讨个双层循环，时间就是n阶乘，不好说会不会超时
* 很好，超时
* 那就不循环，直接调库函数试试
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ans = 0, minPrice = INT_MAX;
		for (int p : prices)
		{
			ans = max(ans, p - minPrice);
			minPrice = min(p, minPrice);
		}
		return ans;
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

