#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 给你一个整数数组 salary ，数组里每个数都是 唯一 的，其中 salary[i] 是第 i 个员工的工资。
* 请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。
*/

class Solution {
public:
	double average(vector<int>& salary) {
		sort(salary.begin(), salary.end());
		double sum = 0.0;
		for (int i = 1; i < salary.size() - 1; i++)
		{
			sum += salary[i] * 1.0;
		}
		return sum / (salary.size() - 2);
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

