#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
*/

/*
* 还是要先排序，但是有上一题的经验，排序完之后的判断可以不再一个个进行
* 可以直接判断右侧 分情况分析判断即可
* 排序完之后就很容易去实现：局部最优 进而推导 全局最优
*/

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.size() <= 1) return 0;
		// 先排序
		sort(intervals.begin(), intervals.end(), [](vector<int>& lp, vector<int>& rp) {
			return lp[0] == rp[0] ? lp[1] < rp[1] : lp[0] < rp[0];
			});

		cout << "输出排序后结果:" << endl;
		for (auto v : intervals)
		{
			cout << v[0] << "->" << v[1] << endl;
		}

		// 循环判断
		int beg = intervals[0][0], end = intervals[0][1];
		int res = 0;
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i][0] == beg && intervals[i][1] == end)
			{	// 区间相同
				++res;
			}
			else if (intervals[i][0] >= beg && intervals[i][1] <= end)
			{	// 重叠了更小的区间，更新区间范围
				++res; // 这个++加的是原本保存那个，不是现在这个
				beg = intervals[i][0];
				end = intervals[i][1];
			}
			else if (end > intervals[i][0] && end < intervals[i][1])
			{	// 结束点在另一个区间范围内 有重叠
				++res;
			}
			else
			{	// 无重叠 更新始终区间
				beg = intervals[i][0];
				end = intervals[i][1];
			}
		}
		return res;
	}
};

int main()
{
	cout << "hello world" << endl;
	//[[],[],[],[],[],[],[],[],[],[],[],[]]
	vector<vector<int>> intervals{
		{-52,31},
		{-73,-26},
		{82,97},
		{-65,-11},
		{-62,-49},
		{95,99},
		{58,95},
		{-31,49},
		{66,98},
		{-63,2},
		{30,47},
		{-40,-26}
	};
	int res = Solution().eraseOverlapIntervals(intervals);
	cout << res << endl;

	system("pause");
	return 0;
}

