#include <iostream>
#include <string>
using namespace std;

/*
* 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
* 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
* 问总共有多少条不同的路径？
*/

/*
* 如果单纯只是看动态规划，那对不起，不会，没思路
* 但是要是单看这一题，不就是一个找路径吗，横着走n-1 竖着走m-1 一共走m+n-2步，在这其中找m-1步竖着走就行
* 题目给了3行7列，那么m+n-2=8 m-1=2  最后的结果就是C82（下8上2）
*/

class Solution {
public:
	int uniquePaths(int m, int n) {
		int x = m + n - 2;
		int y = m < n ? m - 1 : n - 1;
		cout << x << " " << y << endl;
		double res = 1;
		// 这里存数有个问题，连着乘存不下来，所以只能一边算一边存结果
		int end = y;
		while (y >= 1)
		{
			//cout << "x/y = " << x << "/" << y << endl;
			res = res * x / y;
			--x;
			--y;
			//cout << "res = " << res << endl;
		}
		return res;
	}
};

int main()
{
	cout << "hello world" << endl;
	int m = 5;
	int n = 5;
	cout << Solution().uniquePaths(m, n) << endl;

	system("pause");
	return 0;
}

