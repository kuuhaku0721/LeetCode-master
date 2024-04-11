#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
* 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
* 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
* 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
*/

/*
* string有find函数可以用
* 然后就是，求的是子序列
* 所以可能是第一个的子和第二个的子，不一定第二个全都能用得上
* 所以大致思路就是：循环遍历短的那个，然后用find找每一个字符是否存在
* 不存在，那就下一个，存在，继续往下
*/

/*
* 看答案吧，这个dp数组代表的含义都搞不清楚
* 多看几遍总能看会的，大概
*/

class Solution1 {
public:
	int longestCommonSubsequence(string text1, string text2) {
		string base, cmp;
		if (text1.size() > text2.size())
		{
			base = text1;
			cmp = text2;
		}
		else
		{
			base = text2;
			cmp = text1;
		}
		int size = 0;
		for (int i = 0; i < cmp.size(); i++)
		{
			int pos = base.find(cmp[i]);
			if (pos != string::npos)
			{	// 当前字符在base里面能找到，从它开始继续往后比较
				int len = 0;
				int off = pos;
				for (int j = i; j < cmp.size(); j++)
				{	// 只要找到第一个就得循环到结尾，因为子串不一定连续   ...  这会超时的吧www
					int p = base.find(cmp[j], off);
					if (p != string::npos)
					{
						++len;
						off = p + 1;
					}
				}
				size = max(size, len);
			}
		}
		return size;
	}
};

class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) 
	{
		vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
		
		for (int i = 1; i <= text1.size(); i++) 
		{
			for (int j = 1; j <= text2.size(); j++) 
			{
				if (text1[i - 1] == text2[j - 1]) 
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else 
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		// 打印dp数组查看一下结果
		for (auto vec : dp)
		{
			for (int i : vec)
				cout << i << " ";
			cout << endl;
		}

		return dp[text1.size()][text2.size()];
	}
};


int main()
{
	cout << "hello world" << endl;
	string s1 = "abcde";
	string s2 = "ace";
	int res = Solution().longestCommonSubsequence(s1, s2);
	cout << res << endl;

	system("pause");
	return 0;
}

