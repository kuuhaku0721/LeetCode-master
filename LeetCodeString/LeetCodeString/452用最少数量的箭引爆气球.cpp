#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，
* 其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。
* 一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，
* 若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。
* 可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。
* 给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。
*/

/*
* 这个题意理解起来很简单，其实就是合并区间
* 最后剩下来几个不相交的区间，那就需要几支箭
* 
* 好了，60分，过五分之三，之后的超时了
* 最终不还是cv吗岂可修
*/

class Solution1 {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.empty()) return 0;
		// 先排序，以起始点为基准升序排序，起始点相同以终止点为基准升序排序
		sort(points.begin(), points.end(), [](vector<int>& lp, vector<int>& rp) {
			return lp[0] == rp[0] ? lp[1] < rp[1] : lp[0] < rp[0];
			});
		// 排序完毕之后先放进去第一个，然后开始找交集
		vector<vector<int64_t>> res;
		vector<int64_t> tmp{ points[0][0], points[0][1] };
		res.push_back(tmp);
		int ind = 0;
		for (int i = 1; i < points.size(); ++i)
		{
			// 每次比对是否有交集只需比对上一个，因为排序过的
			auto intersection = hasIntersection(points[i], res[ind]);
			if (!intersection.empty())
			{	/*存在交集，把res中这个值切换成交集*/
				res[ind] = intersection;
			}
			else
			{	// 不存在交集，插入该值
				vector<int64_t> tmp{ points[i][0], points[i][1] };
				res.emplace_back(tmp);
				ind++;
			}
		}
		// 最后返回交集的数量，就是最终结果
		return res.size();
	}
	
	vector<int64_t> hasIntersection(vector<int>& point, vector<int64_t> vec)
	{
		vector<int64_t> result;
		int begin = vec[0] > point[0] ? vec[0] : point[0];
		for (int64_t i = vec[0]; i <= vec[1]; ++i)
		{
			if (i == begin) {
				result.push_back(i);
				break;
			}
		}
		int64_t end = vec[1] < point[1] ? vec[1] : point[1];
		for (int64_t i = point[0]; i <= point[1]; ++i)
		{
			if (i == end) {
				result.push_back(i);
				break;
			}
		}
		return result;
	}
};

/*
* 明明大致思路都是对上的，怎么我的就那么复杂呢
* 岂可修啊！！！
*/

class Solution {
private:
	static bool cmp(const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
	}
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.size() == 0) return 0;
		sort(points.begin(), points.end(), cmp);

		int result = 1; // points 不为空至少需要一支箭
		for (int i = 1; i < points.size(); i++) {
			if (points[i][0] > points[i - 1][1]) {  // 气球i和气球i-1不挨着，注意这里不是>=
				result++; // 需要一支箭
			}
			else {  // 气球i和气球i-1挨着
				points[i][1] = min(points[i - 1][1], points[i][1]); // 更新重叠气球最小右边界
			}
		}
		return result;
	}
};


int main()
{
	cout << "hello world" << endl;
	// 
	vector<vector<int>> points{
		{1,9},
		{7,16},
		{2,5},
		{7,12},
		{9,11},
		{2,10},
		{9,16},
		{3,9},
		{1,3}
	};
	int res = Solution().findMinArrowShots(points);
	cout << res << endl;

	system("pause");
	return 0;
}

