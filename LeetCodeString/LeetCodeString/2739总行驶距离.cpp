#include <iostream>
#include <string>
using namespace std;

/*
* 卡车有两个油箱。给你两个整数，mainTank 表示主油箱中的燃料（以升为单位），additionalTank 表示副油箱中的燃料（以升为单位）。
* 该卡车每耗费 1 升燃料都可以行驶 10 km。每当主油箱使用了 5 升燃料时，如果副油箱至少有 1 升燃料，则会将 1 升燃料从副油箱转移到主油箱。
* 返回卡车可以行驶的最大距离。
* 注意：从副油箱向主油箱注入燃料不是连续行为。这一事件会在每消耗 5 升燃料时突然且立即发生。
*/

class Solution {
public:
	int distanceTraveled(int mainTank, int additionalTank) {
		int sum = 0;
		while (mainTank != 0)
		{
			if (mainTank < 5)
			{
				sum += mainTank * 10;
				break;
			}
			else
			{
				mainTank -= 5;
				sum += 50;
				if (additionalTank > 0)
				{
					additionalTank -= 1;
					mainTank += 1;
				}
			}
		}
		return sum;
	}
};


int main()
{
	cout << "hello world" << endl;
	int res = Solution().distanceTraveled(5, 10);
	cout << res << endl;

	system("pause");
	return 0;
}

