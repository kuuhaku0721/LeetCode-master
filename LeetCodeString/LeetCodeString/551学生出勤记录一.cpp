#include <iostream>
#include <string>
using namespace std;

/*
* 给你一个字符串 s 表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：
'A'：Absent，缺勤
'L'：Late，迟到
'P'：Present，到场
如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：
按 总出勤 计，学生缺勤（'A'）严格 少于两天。
学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
如果学生可以获得出勤奖励，返回 true ；否则，返回 false 。

意思就是
连续的'L'要小于3
总共的'A'要小于2
*/

class Solution {
public:
	bool checkRecord(string s) {
		if (count(s.begin(), s.end(), 'A') >= 2)
			return false;
		auto begin = s.begin();
		auto mid = begin;
		while (begin != s.end())
		{
			begin = find(begin, s.end(), 'L');
			if (begin == s.end())
				break;
			mid = begin;
			while (*mid == 'L') mid++;
			if (mid - begin >= 3)
				return false;
			begin = mid;
		}

		return true;
	}
};



int main()
{
	cout << "hello world" << endl;

	string str = "PPALLP";
	bool res = Solution().checkRecord(str);
	if (res)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}

