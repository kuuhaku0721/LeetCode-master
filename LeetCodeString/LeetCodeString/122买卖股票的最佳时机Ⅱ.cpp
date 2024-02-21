#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
返回 你能获得的 最大 利润 。
*/

/*
* 不是，这可是个中等题，给点面子好吧，不要一个循环就没了啊，中等题不要面子的吗？
* 
* 思路：局部最优推导全局最优，收集每两天之间的利润值，最后得到的总和就是最终利润
* 重点是分割利润获取，比如第一天买入，第四天卖出，那么获得的利润是prices[3] - prices[0]
* 分割出来就是prices[3] - prices[2] + prices[2] - prices[1] + prices[1] - prices[0]
* 也就是每两天之间的利润值
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			res += max(prices[i] - prices[i - 1], 0);
		}
		return res;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

