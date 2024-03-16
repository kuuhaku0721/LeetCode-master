#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 模拟情况，用不上什么高深的算法，不算难
void SiRaiMu()
{
	int n;
	cin >> n;
	vector<int> jump(n);
	vector<int> siraimu(n);
	for (int q = 0; q < n; q++)
	{
		cin >> jump[q];
		siraimu[q] = q + 1;
	}
	
	for (int i = 0; i < n; i++)
	{
		// 当=0或=n+1时 说明跳出了格子外面
		for (int j = 0; j < n; j++)
		{
			if (jump[i])
			{	// 1往右 只会+
				if (siraimu[i] == n + 1) continue;
				siraimu[i]++;
			}
			else
			{	// 0往左 只会-
				if (siraimu[i] == 0) continue;
				siraimu[i]--;
			}
		}
		cout << count(siraimu.begin(), siraimu.end(), 0) + count(siraimu.begin(), siraimu.end(), n + 1) << " ";
	}
}

int main()
{
	SiRaiMu();

	system("pause");
	return 0;
}

