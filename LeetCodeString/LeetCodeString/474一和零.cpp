#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
* 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
* 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
* 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
*/

/*
* 感觉回溯能写，但是这是动规的题，回溯肯定超时
* 但是起码得写出来吧，先试试回溯
* 然后cv动规
* 。。。艹，最多有...不是必须有...
* 好了，超时了
* 该cv动规了
*/

/*
* 回顾一下01背包的递推公式 迟早得背下来:dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
* 然后本题递推公式: 递推公式：dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
* dp[i][j]：最多有i个0和j个1的strs的最大子集的大小为dp[i][j]。
*/

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 默认初始化0
		for (string str : strs) { // 遍历物品
			int oneNum = 0, zeroNum = 0;
			for (char c : str) {
				if (c == '0') zeroNum++;
				else oneNum++;
			}
			for (int i = m; i >= zeroNum; i--) { // 遍历背包容量且从后向前遍历！
				for (int j = n; j >= oneNum; j--) {
					dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
				}
			}
		}
		return dp[m][n];
	}
};

class Solution1 {
public:
	int maxlen = INT_MIN;
	vector<string> path;
	int findMaxForm(vector<string>& strs, int m, int n) {
		BackTracking(strs, m, n, 0);
		if (maxlen == INT_MIN) 
			return 0;
		else
			return maxlen;
	}

	void BackTracking(vector<string>& strs, int m, int n, int startIndex)
	{
		if (!path.empty())
		{
			string s = "";
			for (auto str : path)
				s += str;
			int mzero = count(s.begin(), s.end(), '0');
			if (mzero <= m && (s.size() - mzero <= n))
				maxlen = max(maxlen, (int)path.size());
			//cout << "当次的s = " << s << " 其中 0 = " << mzero << " 1 = " << s.size() - mzero << endl;
		}

		for (int i = startIndex; i < strs.size(); i++)
		{
			path.push_back(strs[i]);
			BackTracking(strs, m, n, i + 1);
			path.pop_back();
		}
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<string> strs{ "10","0001","111001","1","0" };
	int m = 3;
	int n = 4;
	int res = Solution().findMaxForm(strs, m, n);
	cout << res << endl;

	system("pause");
	return 0;
}

