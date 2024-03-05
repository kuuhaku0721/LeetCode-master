#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
* 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*/

/*
* 这一题不能硬想，得找规律
* 首先，分类在动态规划，那自然得首先想动规怎么做
* 然后找前面的有啥规律，不难发现，每多一层台阶的方法数量都是前面的累加
* 比如n=1有一种， n=2有两种，而n=3就是n=2数加上n=1数，即(n=3) = (n=2) + (n=1)
* 那么实现起来就简单了
* 为什么是-1 和 -2，就拿5层来举例，因为每次只能跨1或者2，所以想要到5就有了先到4或者先到3这两种情况
* 也就说，想要到5，一定会经历4或者3，而现在4或者3的方法数是已知的，把它俩加起来就是到5的方法数
* 然后往前递推就行了
*/

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 1) return 1;
		vector<int> vec(n + 1);
		// 0不填，方便统一下标
		vec[0] = n; // 这里填的是大小，占位用
		vec[1] = 1;
		vec[2] = 2;
		for (int i = 3; i <= n; ++i)
		{
			vec[i] = vec[i - 1] + vec[i - 2];
		}
		return vec[n];
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

