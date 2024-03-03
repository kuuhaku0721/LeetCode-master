#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
* 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
*/

/*
* 上上道题似乎好像也是这么整的来着
* 只不过那道题超时了，所以不能一次次判断，得吸取教训，用终结点的形式
* 然后就....轻松秒杀
*/

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() <= 1) return intervals;
		// 还是先排序
		sort(intervals.begin(), intervals.end(), [](vector<int>& lp, vector<int>& rp) {
			return lp[0] == rp[0] ? lp[1] < rp[1] : lp[0] < rp[0];
			});

		vector<vector<int>> res;
		vector<int> vec;
		int end = 0;
		for (int i = 0; i < intervals.size(); ++i)
		{
			if (vec.empty())									// 这一步，也就是存第一个区间的时候可以放外面做，判断开始条件 i = 1就行
			{	// 上一轮已经存储过一个 当前区间与前面的不接壤 需要重新记录
				vec.push_back(intervals[i][0]);
				end = intervals[i][1];
			}
			if (end >= intervals[i][0] && end <= intervals[i][1])
			{	// 当前区间与待判断区间接壤  更新终结点
				end = intervals[i][1];
			}
			else if (intervals[i][0] >= vec[0] && intervals[i][1] <= end)
			{	// 当前区间被包含在判断区间之内
				continue;
			}
			else if (intervals[i][0] > end)
			{	// 区间不接壤 保存
				vec.push_back(end);
				res.push_back(vec);
				vec.clear();
				vec.push_back(intervals[i][0]);
				end = intervals[i][1];
			}
		}
		if (end != 0)
		{	// 循环完毕，end不为0 说明最后一个没保存
			vec.push_back(end);
			res.push_back(vec);
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

