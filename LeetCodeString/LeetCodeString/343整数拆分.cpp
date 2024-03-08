#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/*
* 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
* 返回 你可以获得的最大乘积 。
* 
* 这是动规 这是动规 这是动规....
* 首先要确定dp数组
* 拆分后每一位数都是这一位数所得乘积的最大值，也就是从dp[2]开始每一步都是最优的
*/

class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1);
		dp[2] = 1;
		for (int i = 3; i <= n; i++) {
			for (int j = 1; j <= i / 2; j++) {
				dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
			}
		}
		return dp[n];
	}

	// 还有个简单的做法，但没点能力想不出来那种（评论区人均大佬）
	// 3生万物，不够的拆成2
	int integerBreak1(int n) {
		if (n <= 3) return n - 1;

		switch (n % 3)
		{
		case 0:
			return pow(3, n / 3);
		case 1:
			return pow(3, n / 3 - 1) * 4;  // 3 3 4 的乘积自然要比 3 3 3 1的乘积大
		case 2:
			return pow(3, n / 3) * 2;
		}
		return 0;
	}
};


int main()
{
	cout << "hello world" << endl;
	int n = 10;
	int res = Solution().integerBreak1(n);
	cout << res << endl;

	system("pause");
	return 0;
}

