#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

/*
* 给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
* 所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。
* 例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
* 假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。
*/

/*
* 既然已经规定了必须从JFK出发，那其实可以暴力解决，但是估计应该是会超时
* 先锁定第一个是JFK，然后循环查找，如果遇到两个是一样的情况，那就比大小，小的那一个保存下来
* 每一组只能用一次，所以还需要一个used数组
* 提交检查出来一个错误点，在比大小的时候，不止要比较字典序的大小，同时还要保证这条路径存在
* 好吧，还是不行，只是简单的判断比大小和存在它开头的并不能保证他能成为一条通路，可能在中途就断掉了，不能保证全都用上并连通
* 结果困难题还是要看答案嘛
*/

class Solution1 {
public:
	vector<string> result;
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		if (tickets.size() == 0) return result;
		vector<bool> used(tickets.size(), false);
		// 先保留JFK
		result.push_back("JFK");
		while (result.size() != 1 + tickets.size())
		{
			vector<int> tmp;
			for (int i = 0; i < tickets.size(); i++)
			{
				if (used[i]) continue;
				if (tickets[i][0] == result[result.size() - 1])
					tmp.push_back(i);
			}
			if (tmp.size() == 1)
			{
				result.push_back(tickets[tmp[0]][1]);
				used[tmp[0]] = true;
			}
			else
			{
				vector<bool> flags(tmp.size(), false);
				for (int i = 0; i < tmp.size(); i++)
				{
					for (vector<string> v : tickets)
					{
						if (tickets[tmp[i]][1] == v[0])
						{
							flags[i] = true;
							break;
						}
					}
				}

				string s = "ZZZ";
				int ind = 0;
				for (int i = 0; i < tmp.size(); i++)
				{
					if (flags[i])
					{
						if (tickets[tmp[i]][1] < s)
						{
							s = tickets[tmp[i]][1];
							ind = i;
						}
					}
				}
				result.push_back(tickets[tmp[ind]][1]);
				cout << "当前存入：" << result[result.size() - 1] << endl;
				used[tmp[ind]] = true;
			}
		}
		return result;
	}
};

/*
* 代码随想录的答案
* 真要往这儿想，还是有点难的
* STL用的还是不够熟练啊...
*/

class Solution {
private:
	// unordered_map<出发机场, map<到达机场, 航班次数>> targets
	unordered_map<string, map<string, int>> targets;
	bool backtracking(int ticketNum, vector<string>& result) {
		if (result.size() == ticketNum + 1) {
			return true;
		}
		for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
			if (target.second > 0) { // 记录到达机场是否飞过了
				result.push_back(target.first);
				target.second--;
				if (backtracking(ticketNum, result)) return true;
				result.pop_back();
				target.second++;
			}
		}
		return false;
	}
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		targets.clear();
		vector<string> result;
		for (const vector<string>& vec : tickets) {
			targets[vec[0]][vec[1]]++; // 记录映射关系
		}
		result.push_back("JFK"); // 起始机场
		backtracking(tickets.size(), result);
		return result;
	}
};


int main()
{
	cout << "hello world" << endl;
	// [],["EZE","HBA"],["AXA","TIA"],["JFK","AXA"],["ANU","JFK"],
	// [],["TIA","AUA"],[],[],["ADL","EZE"],
	// [],["AXA","EZE"],["AUA","AXA"],["JFK","AXA"],[],
	// [],[],[],[],[]
	vector<vector<string>> tickets{ {"EZE","TIA"}, {"EZE","HBA"}, {"AXA","TIA"},{"JFK","AXA"},{"ANU","JFK"},
		{"ADL","ANU"},{"TIA","AUA"},{"ANU","AUA"},{"ADL","EZE"},{"ADL","EZE"},
		{"EZE","ADL"},{"AXA","EZE"},{"AUA","AXA"},{"JFK","AXA"},{"AXA","AUA"},
		{"AUA","ADL"},{"ANU","EZE"},{"TIA","ADL"},{"EZE","ANU"},{"AUA","ANU"} };
	auto res = Solution().findItinerary(tickets);
	for (string s : res)
	{
		cout << s << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

