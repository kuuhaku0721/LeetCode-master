/*
* 问题描述
* 小蓝有一个神奇的炉子用于将普通金属O 冶炼成为一种特殊金属X。这个炉子有一个称作转换率的属性V，V 是一个正整数，
* 这意味着消耗V 个普通金属O 恰好可以冶炼出一个特殊金属X，当普通金属O 的数目不足V 时，无法继续冶炼。
* 现在给出了N 条冶炼记录，每条记录中包含两个整数A 和B，这表示本次投入了A 个普通金属O，
* 最终冶炼出了B 个特殊金属X。每条记录都是独立的，这意味着上一次没消耗完的普通金属O 不会累加到下一次的冶炼当中。
* 根据这N 条冶炼记录，请你推测出转换率V 的最小值和最大值分别可能是多少，题目保证评测数据不存在无解的情况。
*
* 输入格式
* 第一行一个整数N，表示冶炼记录的数目。
* 接下来输入N 行，每行两个整数A、B，含义如题目所述。
*
* 输出格式
* 输出两个整数，分别表示V 可能的最小值和最大值，中间用空格分开。
*
* 样例输入
* 3
* 75 3
* 53 2
* 59 2
*
* 样例输出
* 20 25
*/

/*
* 已知 O 和 X 求 V 且满足 O/V >= X && O/V <= X+1
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

void metal()
{
	int n;
	cin >> n;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> par;
		cin >> par.first >> par.second;
		vec.push_back(par);
	}

	// 先确定一个最大值，直接拿输入数据相除，得到的数一定是一个满足某一组的最大，但不一定是符合要求的最大
	int biggest = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		biggest = max(biggest, vec[i].first / vec[i].second);
	}
	// 然后以它为起点开始遍历循环，找到符合要求的最大和最小即可
	// 为了省一步判断，直接把所有符合条件的全都保留下来，然后返回头尾就行了，反正不用吝啬内存
	vector<int> res;
	res.reserve(2);
	for (int i = biggest; i >= 1; --i)
	{
		bool flag = true;
		for (auto p : vec)
		{
			if ((p.first / i >= p.second + 1) || (p.first / i < p.second))
			{
				flag = false;
				break;
			}
		}
		if (flag)
			res.push_back(i);
	}
	// 这样做的目的是为了缩短循环遍历的次数，减少时间消耗，希望不要超时
	// 最后返回这个数组的头尾就行了
	if (res.size() <= 1)
		cout << res[0] << " " << res[0] << endl;
	else
	{
		res[1] = res[res.size() - 1];	// 这样比较冒险，但是题目说了不存在无解的情况，所以可以这么干
		res.resize(2);

		//cout << "最小：" << res[1] << ", 最大：" << res[0] << endl;
		cout << res[1] << " " << res[0] << endl;
	}
}

/*
* 超时，只能过60%，数据量超过1w就超时了
* 我是sb....
*/

void answer()
{
	int n;
	cin >> n;
	int ansMin = 0, ansMax = INT_MAX;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		ansMin = max(ansMin, a / (b + 1) + 1);
		ansMax = min(ansMax, a / b);
	}
	cout << ansMax << " " << ansMax << endl;
}

int main()
{
	// cout << "hello world" << endl;
	metal();
	answer();

	system("pause");
	return 0;
}

