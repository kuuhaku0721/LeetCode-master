#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，
我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
*/

/*
* 不知道原数组是怎么样的，所以先排序两个数组
* 然后遍历第一个数组，其内部遍历第二个数组
* 第二个数组的拿着第二个数组的值去减第一个数组的值，不够减，继续往后，够减，置0，然后下一个
* 最后统计第一个数组里面0的数量，就是最终结果
* 喵个咪的不是减，是大于等于才能分配
* 
* 简单题还是轻轻松松的，跟答案思路也能对的上
* 这个写法属于答案里的第二种解法：小饼干先满足小胃口
*/

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int sStart = 0;
		for (int i = 0; i < g.size(); i++)
		{
			int j = sStart;
			for (; j < s.size(); j++)
			{
				if (s[j] != 0)
				{
					if (s[j] >= g[i])
					{
						s[j] = 0;
						g[i] = 0;
						sStart = j + 1;
						break;
					}
				}
			}
			// 如果j == s.size() 说明某一个孩子在用完饼干之后还是没有满足,因为排序过，后面就不可能满足了
			if (j == s.size())
				break;
		}
		int cnt = 0;
		for (int i : g)
		{
			if (i == 0) cnt++;
		}
		return cnt;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> g{ 1,2,3 };
	vector<int> s{ 3 };
	int res = Solution().findContentChildren(g, s);
	cout << "结果是：" << res << endl;

	system("pause");
	return 0;
}

