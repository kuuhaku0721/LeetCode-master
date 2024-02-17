#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
* 给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。

请你计算该表达式。返回一个表示表达式值的整数。

注意：

有效的算符为 '+'、'-'、'*' 和 '/' 。
每个操作数（运算对象）都可以是一个整数或者另一个表达式。
两个整数之间的除法总是 向零截断 。
表达式中不含除零运算。
输入是一个根据逆波兰表示法表示的算术表达式。
答案及所有中间计算结果可以用 32 位 整数表示。
*/

/*
* 基本思路就是：需要一个栈，遍历vector，如果遇到数字，就把它放到栈里
* 如果遇到运算符，就从栈里取出来俩数运算，算完再放进去
* 一直遍历到数组末尾
* 
* 轻松秒杀
*/

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> stk;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
			{
				//放入栈中
				stk.push(atoi(tokens[i].c_str()));
			}
			else
			{
				//取俩数出来运算
				int num2 = stk.top();
				stk.pop();
				int num1 = stk.top();
				stk.pop();
				if (tokens[i] == "+")
				{
					num1 = num1 + num2;
				}
				else if (tokens[i] == "-")
				{
					num1 = num1 - num2;
				}
				else if (tokens[i] == "*")
				{
					num1 = num1 * num2;
				}
				else if (tokens[i] == "/")
				{
					num1 = num1 / num2;
				}
				stk.push(num1);
			}
		}
		return stk.top();
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

