#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
* 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
* 给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。
*/

/*
* "测试用例通过了，但耗时太长。"
* 第一次见，很是新鲜，希望下次不要再见(草泥马微笑脸)
*/

class Solution1 {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		// 先找到第一个gas大于cost的位置
		// 减，取余，然后从下一个位置开始循环
		// while条件是再次回到i的位置，如果不够减，跳出循环，找下一个
		// 如果回到i的位置，返回i
		// 全都循环一遍还是不行，return -1
		for (int i = 0; i < gas.size(); i++)
		{
			if (gas[i] == 0) continue;
			int remain = gas[i] - cost[i];
			int beg = (i + 1) % gas.size();
			while (remain > 0 && beg != i)
			{
				remain = remain + gas[beg] - cost[beg];
				beg = (beg + 1) % gas.size();
			}
			if (remain >= 0 && beg == i) return i;
		}
		return -1;
	}
};

// cv的 直接从全局最优的角度出发的答案
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int curSum = 0;
		int min = INT_MAX; // 从起点出发，油箱里的油量最小值
		for (int i = 0; i < gas.size(); i++) {
			int rest = gas[i] - cost[i];
			curSum += rest;
			if (curSum < min) {
				min = curSum;
			}
		}
		if (curSum < 0) return -1;  // 情况1
		if (min >= 0) return 0;     // 情况2
		// 情况3
		for (int i = gas.size() - 1; i >= 0; i--) {
			int rest = gas[i] - cost[i];
			min += rest;
			if (min >= 0) {
				return i;
			}
		}
		return -1;
	}
};


int main()
{
	cout << "hello world" << endl;
	vector<int> gas{ 2,3,4 };
	vector<int> cost{ 3,4,3 };
	int res = Solution().canCompleteCircuit(gas, cost);
	cout << res << endl;

	system("pause");
	return 0;
}

