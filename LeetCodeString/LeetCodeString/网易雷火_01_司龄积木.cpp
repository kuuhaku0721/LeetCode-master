#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
*  从两年前开始，
* 有4款，分别对应一周年，三周年，六周年和十周年。
* 举例说明，如果某位员工今年刚好达到六年司龄，那么需要为他采购一周年，三周年，六周年共三件积木。
* 如果某位员工今年刚好达到八年司龄，那么他在2年前的时候刚好是六周年，那时候已经领取过六周年的积木了，这次只需要为他采购一周年和三周年两件积木。
* 第一行输入一个N （1<=N<=10000）,表示雷火的员工数量。
* 接下来一行是N个整数(1<=司龄<=20)，表示每个员工今年达到的司龄。
* 输入
* 4
* 1 3 6 8
* 输出
* 3 3 1 0
*/

void CampanyAge()
{
	int n;
	cin >> n;
	vector<int> ages(n);
	for (int i = 0; i < n; i++)
	{
		cin >> ages[i];
	}
	vector<int> count(4, 0);
	for (int i = 0; i < ages.size(); i++)
	{
		if (ages[i] == 1)
			++count[0];
		else if (ages[i] == 2)
			continue;
		else if (ages[i] == 3)
			++count[1];
		else if (ages[i] == 4 || ages[i] == 5)
			++count[0];
		else if (ages[i] >= 6 && ages[i] <= 8)
		{
			if (ages[i] == 6)
				++count[2];
			++count[0];
			++count[1];
		}
		else if (ages[i] >= 9 && ages[i] <= 12)
		{
			if (ages[i] == 10)
				++count[3];
			++count[0];
			++count[1];
			++count[2];
		}
		else
		{
			++count[0];
			++count[1];
			++count[2];
			++count[3];
		}
	}
	for (int i : count)
		cout << i << " ";
}


int main()
{
	CampanyAge();

	system("pause");
	return 0;
}

