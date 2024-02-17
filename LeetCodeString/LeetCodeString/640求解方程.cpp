#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

/*
* 求解一个给定的方程，将x以字符串 "x=#value" 的形式返回。该方程仅包含 '+' ， '-' 操作，变量 x 和其对应系数。
如果方程没有解或存在的解不为整数，请返回 "No solution" 。如果方程有无限解，则返回 “Infinite solutions” 。
题目保证，如果方程中只有一个解，则 'x' 的值是一个整数。
*/

/*
* 出发点时把系数和常数装在两个vector中，然后分别运算，反正最后一定只剩一个数
* 问题是分别系数，正数，负数
* 题目方程式保证只有加减和几乘x的形式
*/

class Solution {
public:
	string solveEquation(string equation) {
		vector<int> coefficient; //存系数
		vector<int> constant; //存常数
		string t = "";
		bool flag = true;
		for (char c : equation)
		{
			if (c == '+')
			{
				if (t == "")
				{
					t += '+';
					continue;
				}
				else
				{
					if(flag)
						constant.push_back(atoi(t.c_str()));
					else
						constant.push_back(0 - atoi(t.c_str()));
					t = "+";
				}
			}
			else if (c == '-')
			{
				if (t == "")
				{
					t += '-';
					continue;
				}
				else
				{
					if (flag)
						constant.push_back(atoi(t.c_str()));
					else
						constant.push_back(0 - atoi(t.c_str()));
					t = "-";
				}
			}
			else if (c == 'x')
			{
				if (t == "" || t == "+" || t == "-")
				{ //一开始进来就碰到x，或者x前面没有系数只有运算符
					t += '1';
				}
				if(flag)
					coefficient.push_back(atoi(t.c_str()));
				else
					coefficient.push_back(0 - atoi(t.c_str()));
				t = "";
			}
			else if (c == '=')
			{
				if (t != "")
				{
					constant.push_back(atoi(t.c_str()));
				}
				t = "";
				flag = false;
			}
			else
				t += c;
		}
		//循环运算完，如果最后一个不是带x的话会被保留在t里面，需要最后手动添加进去
		if (t != "")
		{
			if(flag)
				constant.push_back(atoi(t.c_str()));
			else
				constant.push_back(0 - atoi(t.c_str()));
		}
		t = "";

		cout << "系数: ";
		for (int i : coefficient)
			cout << i << " ";
		cout << endl << "常数: ";
		for (int i : constant)
			cout << i << " ";
		cout << endl;

		int coeff = accumulate(coefficient.begin(), coefficient.end(), 0);
		int con = accumulate(constant.begin(), constant.end(), 0);
		con = 0 - con;
		cout << "系数：" << coeff << endl;
		cout << "常数: " << con << endl;

		if (coeff == con && coeff != 0)
		{ //系数等于常数，且不等于0 零解
			t = "x=1";
		}
		else if (coeff == con && coeff == 0)
		{ //系数等于常数还都是0 无限解
			t = "Infinite solutions";
		}
		else if(coeff == 0 && con != 0)
		{ //系数为0 常数不是0 无解
			t = "No solution";
		}
		else if (coeff != 0 && con == 0)
		{ //系数不是0 常数是0 解只有0一个
			t = "x=0";
		}
		else if(con % coeff != 0)
		{ //题目要求不是整数就是无解
			t = "No solution";
		}
		else
		{
			t = "x=";
			t += to_string(con / coeff);
		}

		return t;
	}
};


int main()
{
	cout << "hello world" << endl;
	string equation = "2=-x";
	equation = Solution().solveEquation(equation);
	cout << equation << endl;

	system("pause");
	return 0;
}

