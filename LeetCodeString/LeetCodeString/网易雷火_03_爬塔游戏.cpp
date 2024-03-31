#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
* 第一行输入三个整数p，n，m，分别表示玩家初始战斗力、数字塔的怪物房数量、boss数量。（10<=p<10^7，0<=n<=10^5, 1<=m<=10^5）

接下来n行，每行一个整数x，表示每个怪物房间的怪物战斗力，x单调递增（1<=x<=10^7）。

接下来m行，每行一个整数y，表示每个boss的战斗力（1<=y<=10^7）。

输入
10 0 1
12
输出
3

输入
20 7 1
10
10
10
10
10
10
10
130
输出
12
*/



void BossTower()
{
	int atk, n, m;
	cin >> atk >> n >> m;  // 战斗力、房间数、boss数
	vector<int> monster(n);
	for (int i = 0; i < n; i++)
	{
		cin >> monster[i];
	}
	vector<int> boss(m);
	for (int i = 0; i < m; i++)
	{
		int boss;
		cin >> boss;
		int cnt = 0;
		// 爬塔、 打boss
		/*
		* 需要判断情况有
		* 如果初始战斗力就已经大于boss：直接打boss，次数0结束
		* 战斗力不够，提升战力有两个选择：钞能力 或者 进入一个房间
		* 钞能力不限制次数，所以需要判断用哪个，无论哪个都算作加一次数
		* 可以每次都留大的那个,那这个逻辑好判断
		* 问题是每次如何去选择进入哪个房间,不能每次都从头遍历，需要有一个index值记录当前已经遍历到了哪个
		* 小怪房间递增排序
		* 还有几种情况：如果一开始就没有小怪房间，这样就只能每次都钞能力
		* 如果高等级小怪打完了，还是不够打boss，还得绕回来从最高的往下找
		* 如果全部小怪都打完了，那还是每次都得钞能力
		* 5%
		* 还有一种情况，能减少判断次数的情况
		* 如果当前的atk的十分之一，比monster最大的还要大，那就没必要继续看monster了，直接每次都钞能力就行了
		* 
		*/
		int maxMonster = 0;
		if (n > 0) maxMonster = monster[n - 1];
		int idx = 0;
		bool enter = !monster.empty();
		bool flag = true; // true: 正向  false: 反向
		while (atk <= boss)
		{
			if (enter)
			{	// 保证有小怪
				if (atk / 10 >= maxMonster)
				{
					enter = false;
					continue;
				}
				else
				{
					if (idx == -1 && flag == false)
					{	// 所有小怪都打完了，接下来只能用钞能力了
						enter = false;
						continue;
					}
					if (idx == monster.size())
					{	// 正着走，走到头了，还是不够，现在atk已经比所有的monster都要大了，那就倒着回去挨个打
						idx = monster.size() - 1;
						flag = false;
					}
					// 两个选择，一个是打小怪、一个是钞能力
					if (flag)
					{
						while (idx < monster.size() && monster[idx] != -1 && atk > monster[idx])
							++idx;
						--idx;
					}
					else
					{
						while (idx >= 0 && monster[idx] == -1)
							--idx;
					}
					if (idx >= 0)
					{
						maxMonster = monster[idx];
						if (atk / 10 >= maxMonster)
						{
							enter = false;
							continue;
						}
						int atk_hit = atk + monster[idx];
						int atk_money = atk * 1.1;
						monster[idx] = -1;
						atk = atk_money > atk_hit ? atk_money : atk_hit;
						++cnt;
						if (flag) ++idx;
						else --idx;
					}
				}
			}
			else
			{	// 没有小怪房间 或者 小怪打完了，每次只能钞能力
				atk *= 1.1;
				++cnt;
			}
		}

		cout << cnt << endl;
	}
}


int main()
{
	BossTower();

	system("pause");
	return 0;
}

