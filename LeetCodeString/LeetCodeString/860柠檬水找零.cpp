#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
* 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
* 每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
* 注意，一开始你手头没有任何零钱。
* 给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
*/

/*
* 注意题目描述，货币面值只有 5 10 20  也就是说如果找零需要的是15 而我手里有两张10块的，是没办法找零的，尽管20比15大
* 剩下的就是一个遍历就行了，中途碰到没法找零的情况就直接false,大概
* 
* 
* 所以这题，解法大家全都一个样，连答案思路都一样
* 区别只在于，你是用的什么方法去记录的5的数量和10的数量
*/

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		map<int, int> mapCnt;
		for (int i : bills)
		{
			if (i == 5)
			{	// 直接收钱，不找零
				mapCnt[5]++;
			}
			if (i == 10)
			{	// 收10块，找零5块
				mapCnt[10]++;
				if (mapCnt[5] > 0)
					mapCnt[5]--;
				else
					return false;	// 不够找零，直接false
			}
			if (i == 20)
			{	// 收20 找零15
				mapCnt[20]++;
				// 如果有10块的，就找零一张10一张5
				if (mapCnt[10] > 0 && mapCnt[5] > 0)
				{
					mapCnt[10]--;
					mapCnt[5]--;
				}
				else if (mapCnt[5] >= 3)
				{	// 如果没有10块的，那就找零三张5，不够就是false
					mapCnt[5] -= 3;
				}
				else
					return false;
			}
		}
		return true;
	}
};



int main()
{
	cout << "hello world" << endl;
	

	system("pause");
	return 0;
}

