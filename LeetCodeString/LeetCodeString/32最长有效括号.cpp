#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
* 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
*/

// 这么算只能算连续，不连续的话就会出错，比如"()(()" 结果应该是2 但输出是4
class Solution {
public:
	int longestValidParentheses(string s) {
		stack<char> stk;
		int cnt = 0;
		int res = INT_MIN;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				stk.push(s[i]);
			}
			else if (s[i] == ')')
			{
				if (!stk.empty())
				{
					if (stk.top() == '(')
					{
						stk.pop();
						cnt++;
					}
				}
				else
				{
					res = max(res, cnt);
					cnt = 0;
				}
			}
		}
		res = max(res, cnt);
		return res * 2;
	}

	// gpt给的答案，你别说，好像还真可以
	int longestValidParentheses1(string s) {
		int n = s.length();
		stack<int> stk;
		int maxLen = 0;
		stk.push(-1); // 初始时在栈中放入一个索引值-1

		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				stk.push(i);
			}
			else {
				stk.pop();
				if (stk.empty()) {
					stk.push(
						i); // 当前右括号没有匹配的左括号，将当前右括号的索引入栈作为新的起始点
				}
				else {
					maxLen =
						max(maxLen, i - stk.top()); // 更新最长有效括号的长度
				}
			}
		}

		return maxLen;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

