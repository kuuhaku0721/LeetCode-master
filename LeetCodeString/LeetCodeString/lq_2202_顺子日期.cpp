#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 也是填空题，原题是张图片，没法复制文本
* 
* 题意分析：
* 首先要求是2022年，所以年份就不用管了，因为不可能存在2022年34月
* 所以直接比较日期就行了
* 答案是14
* 但是这题，手算更方便，毕竟日期的限制在那儿
*/


void FluntDate()
{
	vector<int> months{ 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 1; i <= 12; i++)
	{
		string t = "";
		if (i < 10) t += "0";
		t += to_string(i);
		for (int j = 1; j <= months[i]; j++)
		{
			string s = t;
			if (j < 10) s += "0";
			s += to_string(j);
			// 判断
			if ((s[0] == s[1] - 1) && (s[1] == s[2] - 1) || ((s[1] == s[2] - 1) && (s[2] == s[3] - 1)))
				months[0]++;
		}
	}
	cout << months[0] << endl;
}

int main()
{
	cout << "hello world" << endl;
	FluntDate();

	system("pause");
	return 0;
}

