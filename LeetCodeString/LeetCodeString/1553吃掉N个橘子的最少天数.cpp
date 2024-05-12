#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 这一题的官解是记忆化搜索，如果日后复习看到这里了，去看一下官解的说法


/*
* 厨房里总共有 n 个橘子，你决定每一天选择如下方式之一吃这些橘子：
* 吃掉一个橘子。
* 如果剩余橘子数 n 能被 2 整除，那么你可以吃掉 n/2 个橘子。
* 如果剩余橘子数 n 能被 3 整除，那么你可以吃掉 2*(n/3) 个橘子。
* 每天你只能从以上 3 种方案中选择一种方案。
* 请你返回吃掉所有 n 个橘子的最少天数。
*/

// 回溯可以做，但是超时了，从六百多开始全都超时了
class Solution1 {
public:
	int min_day = INT_MAX;
	int minDays(int n) {
		BackTracking(n, 0);
		return min_day;
	}

	void BackTracking(int n, int days)
	{
		if (n == 0)
		{
			min_day = min(min_day, days);
			return;
		}

		if (n % 2 == 0)
		{
			int curn = n - n / 2;
			BackTracking(curn, days + 1);
		}
		if (n % 3 == 0)
		{
			int curn = n - 2 * (n / 3);
			BackTracking(curn, days + 1);
		}

		int curn = n - 1;
		BackTracking(curn, days + 1);
	}
};

// 不能回溯，那就找数学规律吧
class Solution2 {
public:
	int minDays(int n) {
		// 很好，没找出来，oh fuck！
	}
};

// 官解的记忆化搜索，什么玩意啊都是....
class Solution {
private:
	unordered_map<int, int> memo;
public:
	int minDays(int n) {
		if (n <= 1) {
			return n;
		}
		if (memo.count(n)) {
			return memo[n];
		}
		return memo[n] = min(n % 2 + 1 + minDays(n / 2), n % 3 + 1 + minDays(n / 3));
	}
};

int main()
{
	cout << "hello world" << endl;
	int n = 10;
	int res = Solution().minDays(n);
	cout << res << endl;

	system("pause");
	return 0;
}

