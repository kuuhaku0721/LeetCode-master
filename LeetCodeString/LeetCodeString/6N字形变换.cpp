#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
请你实现这个将字符串进行指定行数变换的函数：
string convert(string s, int numRows);
*/

/*
* 根据传进去的numRows定义一个string数组，然后只需要找规律添加就行了
* 假设numRows是4 那么对于s来说每一位所在的行就是 1234321234321234321
* 如果numRows是3 那么对于s来说每一位就是1232123212321
* 然后只需要对应位置放进去对应的字符串就行
* 大佬的想法，只要有了大佬的想法，实现起来意外的简单
*/

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		vector<string> vec;
		for (int i = 0; i < numRows; i++)
		{
			vec.push_back("");
		}
		int index = 0, direction = 1;
		for (int i = 0; i < s.size(); i++)
		{
			if (index == 0)
			{
				direction = 1;
			}
			if (index == numRows - 1)
			{
				direction = -1;
			}
			vec[index] += s[i];
			index += direction;
		}
		string res = "";
		for (string str : vec)
		{
			res += str;
		}
		return res;
	}
};



int main()
{
	cout << "hello world" << endl;
	string s = "PAYPALISHIRING";
	int num = 4;
	s = Solution().convert(s, num);
	cout << s << endl;

	system("pause");
	return 0;
}

