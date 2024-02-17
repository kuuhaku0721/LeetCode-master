#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <map>
using namespace std;

/*
* 定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串，所以 base 看起来是这样的：
"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现。
*/

/*
* 直接在s里面找最大连续串
* 还有一种情况是...za...的情况，也就是非连续的情况算另外一种情况
* 只要能找到这两种连续串，然后再判断它们各有多少个子串就是结果
*/

/*
* 苦苦挣扎的结果：大部分情况是对的，大部分....应付不了特殊情况(a...za....za...z...)在za相连的时候判断有误
* 在计算子串数量的时候不对，计算是直接累加的，没有考虑重复的情况
* 放弃，看答案
*/
class Solution {
public:
	int findSubstringInWraproundString(string p) {
		vector<int> dp(26);
		int k = 0;
		for (int i = 0; i < p.length(); ++i) {
			if (i && (p[i] - p[i - 1] + 26) % 26 == 1) { // 字符之差为 1 或 -25
				++k;
			}
			else {
				k = 1;
			}
			dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
		}
		return accumulate(dp.begin(), dp.end(), 0);
	}
};


class Solution1 {
public:
	int findSubstringInWraproundString(string s) {
		//在s中找连续串
		//一个个遍历，用一个缓冲区来保存结果，如果它跟它的后一个只差一，那就保存他俩，然后继续遍历，直到他跟后面那个差距不是一
		//然后缓冲区置空，重新开始记录
		//最后还得判断一下s中一共用到了几个字符，最终结果得加几
		if (s.size() == 0) return 0;
		if (s.size() == 1) return 1;
		map<string, int> ms;
		int begin = -1, k = 1;
		for (int i = 1; i < s.size(); i++)
		{
			if ((s[i] - s[i - 1] == 1) || (s[i] - s[i-1] == -25))
			{
				if (begin == -1)
					begin = i - 1;
				k++;
			}
			else
			{
				if (begin == -1 || k == 1)
					continue;
				else
				{
					string buf = s.substr(begin, k);
					ms[buf]++;
					begin = -1, k = 1;
				}
			}
		}
		if (begin != -1 && k != 0)
		{
			string buf = s.substr(begin, k);
			ms[buf]++;
		}

		int res = 0;
		map<char, int> mp;
		for (auto it : ms)
		{
			for (int i = it.first.size() - 1; i >= 1; i--)
				res += i;
		}
		for (char c : s)
		{
			mp[c]++;
		}
		res += mp.size();

		for (auto it = ms.begin(); it != ms.end(); it++)
		{
			cout << it->first << "-->" << it->second << endl;
		}

		return res;
	}
};



int main()
{
	cout << "hello world" << endl;
	string s = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	int res = Solution1().findSubstringInWraproundString(s);
	cout << res << endl;


	system("pause");
	return 0;
}

