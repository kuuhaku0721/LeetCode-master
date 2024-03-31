#include <iostream>
#include <string>
using namespace std;

/*
* 原本只有1个
* ①Ctrl+A，全选目前文本；②Ctrl+S，选择单个文本；③Ctrl+C，复制所选文本；④Ctrl+V，粘贴所复制的文本。
* 求达到目标数量的最少操作次数
*/

// 假设第一步AC已经做过了
// 还不对 ACV是三次，可能只要再VV两次就能到的不需要再三次
//		  需要达成的  当前大小	当前复制大小
int Opera(int total, int m, int& size, int& now)
{
	int next = 0;
	int step;
	if (m - size <= 3)
	{
		step = m - size;
		size = m;
		now = 1;
	}
	else
	{
		next = Opera(total, m / 2, size, now);
		if ((total - size) / now <= 3)
		{
			step = (total - size) / now;
			size = total;
		}
		else
		{
			step = 3;
			now = size;
			size *= 2;
		}
	}
	return step + next;
}
void CtrlCV()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int m;
		cin >> m;
		if (m == 1)
		{
			cout << "0" << endl;
			continue;
		}

		int size = 1, now = 0;
		// 原本就有一个,要达到的目标数是m
		if (m % 2 == 0)
		{	// 偶数直接返回
			// 2 代表最开始的一次AC
			cout << 2 + Opera(m, m, size, now) << endl;
		}
		else
		{	// 奇数要判断一下当前复制的是多少个
			// 如果还是1个，就追加1 即V，不是只能追加3 即 S C V
			int res = 2 + Opera(m - 1, m - 1, size, now);
			if (now == 1)
				res += 1;
			else
				res += 3;
			cout << res << endl;
		}
	}
}


int main()
{
	CtrlCV();

	system("pause");
	return 0;
}

