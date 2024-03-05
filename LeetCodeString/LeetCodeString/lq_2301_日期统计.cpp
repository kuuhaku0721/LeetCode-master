#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
* 问题描述,,填空题
* 小蓝现在有一个长度为100,100100,的数组，数组中的每个元素的值都在0,00,到9,99,的范围之内。数组中的元素从左至右如下所示：
* 
* 5,6,8,6,9,1,6,1,2,4,9,1,9,8,2,3,6,4,7,7,5,9,5,0,3,8,7,5,8,1,5,8,6,1,8,3,0,3,7,9,2,7,0,5,8,8,5,7,0,9,9,1,9,4,4,6,8,6,3,3,8,5,1,6,3,4,6,7,0,7,8,2,7,6,8,9,5,6,5,6,1,4,0,1,0,0,9,4,8,0,9,1,2,8,5,0,2,5,3,3
* 
* 现在他想要从这个数组中寻找一些满足以下条件的子序列：
* 
* 子序列的长度为8；
* 这个子序列可以按照下标顺序组成一个yyyymmdd,格式的日期，并且要求这个日期是2023,年中的某一天的日期，例如20230902，20231223。yyyy,表示年份，mm,表示月份，dd,表示天数，当月份或者天数的长度只有一位时需要一个前导零补充。
* 请你帮小蓝计算下按上述条件一共能找到多少个不同的2023,年的日期。
* 对于相同的日期你只需要统计一次即可。
*/

/*
* 大致思路：把数字全部保存到数组之后用map保存，然后直接减去2023，剩下就只需要判断月份和日期就行了
* 然后就用循环拼日期，拼出来一个日期之后遍历这个日期，让map里面的value值对应去减
* 如果某一个减完成负的了，那就说明不够用，总数减个1
*
*
* 很好，完全不对，tmd子序列只能顺着往下不能回退
* 捏嘛嘛的
*/

vector<int> nums{ 5,6,8,6,9,1,6,1,2,4,9,1,9,8,2,3,6,4,7,7,5,9,5,0,3,8,7,5,8,1,
				  5,8,6,1,8,3,0,3,7,9,2,7,0,5,8,8,5,7,0,9,9,1,9,4,4,6,8,6,3,3,
				  8,5,1,6,3,4,6,7,0,7,8,2,7,6,8,9,5,6,5,6,1,4,0,1,0,0,9,4,8,0,
				  9,1,2,8,5,0,2,5,3,3 };
vector<int> days{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };

void Findyyyymmdd()
{
	map<int, int> mapNums;
	for (auto i : nums)
	{
		mapNums[i]++;
	}
	mapNums[2]--;
	mapNums[0]--;
	mapNums[2]--;
	mapNums[3]--;

	for (auto m : mapNums)
	{
		cout << m.first << "--" << m.second << endl;
	}

	
	int minus = 0;
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j < days[i]; j++)
		{
			auto tmpMap = mapNums;
			string md = "";
			if (i < 10) md += "0";
			md += to_string(i);
			if (j < 10) md += "0";
			md += to_string(j);
			for (int i = 0; i < md.size(); i++)
			{
				if (--tmpMap[md[i] - '0'] < 0)
				{
					minus++;
					break;
				}
			}
		}
	}
	cout << 365 - minus << endl;
}

void answer()
{
	int ans = 0;
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= days[i]; j++) {
			string str = "2023";
			if (i < 10)str += "0";
			str += to_string(i);
			if (j < 10)str += "0";
			str += to_string(j);

			int k = 0;
			for (int l = 0; l < 100 && k < 8; l++) {
				if (nums[l] == str[k] - '0')
				{
					cout << "找到一个：l = " << l << ", str[k] = " << str[k] << endl;
					k++;
				}
			}
			if (k >= 8) ans++;
		}
	}
	cout << ans << endl;
}

int main()
{
	cout << "hello,world" << endl;
	Findyyyymmdd();
	answer();

	system("pause");
	return 0;
}

