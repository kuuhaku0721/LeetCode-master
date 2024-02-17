#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
* 请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。
函数 myAtoi(string s) 的算法如下：
读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
返回整数作为最终结果。
注意：
本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
*/

/*
* 快看快看，这个人，他写了个屎山欸
*/

//-------------------------------------------------------------------------------------------
class Solution1 {
public:
	int myAtoi(string s) {
		int index;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != 32)
			{
				index = i;
				break;
			}
		}
		s = s.substr(index, s.size() - index);
		string temp = "";
		if (s[0] >= 0 + '0' && s[0] <= 9 + '0')
			temp += s[0];
		else if (s[0] == '+' || s[0] == '-' && (s[1] >= 0 + '0' && s[1] <= 9 + '0'))
			temp += s[0];
		else
			return 0;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] >= 0 + '0' && s[i] <= 9 + '0')
			{
				temp += s[i];
			}
			else
				break;
		}
		cout << temp << endl;
		//现在数字已经存到了temp里面，需要从temp转成int
		//还少一个开头的0没有处理  0不用管，0再多乘出来结果也是0
		//现在的temp一定是一个符号或没有符号，后跟0-9的数字，现在要去掉前驱0
		string str = "";
		int i = 0;
		if (temp[0] == '-' || temp[0] == '+')
		{
			str += temp[0];
			i = 1;
		}
		for (; i < temp.size(); i++)
		{
			if (temp[i] != '0') break;
		}
		for (; i < temp.size(); i++)
			str += temp[i];


		if (str.size() > 11)
		{
			if(str[0] == '-')
				return -2147483648;
			else
				return 2147483647;
		}
		
		i = 0;
		bool flag;
		long res = 0;
		if (str[0] == '-')
		{
			i = 1;
			flag = false;
		}
		else if (str[0] == '+')
		{
			i = 1;
			flag = true;
		}
		else
		{
			i = 0;
			flag = true;
		}
		for (; i < str.size(); i++)
		{
			int t = str[i] - '0';
			for (int j = 0; j < str.size() - i - 1; j++)
			{
				t *= 10;
			}
			res += t;
		}
		
		

		if (flag)
		{
			if (res > 2147483647)
				return 2147483647;
			return (int)res;
		}
		else
		{
			if (res > 2147483648)
				return -2147483648;
			return int(0 - res);
		}
	}
};
//-------------------------------------------------------------------------------------------------
//官方题解
class Automaton {
	string state = "start";
	unordered_map<string, vector<string>> table = {
		{"start", {"start", "signed", "in_number", "end"}},
		{"signed", {"end", "end", "in_number", "end"}},
		{"in_number", {"end", "end", "in_number", "end"}},
		{"end", {"end", "end", "end", "end"}}
	};

	int get_col(char c) {
		if (isspace(c)) return 0;
		if (c == '+' or c == '-') return 1;
		if (isdigit(c)) return 2;
		return 3;
	}
public:
	int sign = 1;
	long long ans = 0;

	void get(char c) {
		state = table[state][get_col(c)];
		if (state == "in_number") {
			ans = ans * 10 + c - '0';
			ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
		}
		else if (state == "signed")
			sign = c == '+' ? 1 : -1;
	}
};

class Solution {
public:
	int myAtoi(string str) {
		Automaton automaton;
		for (char c : str)
			automaton.get(c);
		return automaton.sign * automaton.ans;
	}
};


int main()
{
	cout << "hello world" << endl;
	string s = "20000000000000000000";
	int res = Solution().myAtoi(s);
	cout << res << endl;

	system("pause");
	return 0;
}

