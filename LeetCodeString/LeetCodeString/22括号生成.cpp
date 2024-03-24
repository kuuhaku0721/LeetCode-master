#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <functional>
using namespace std;

/*
* 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
*/

/*
* 起码，一眼看出来，应该是个回溯
* 穷举好说，但是怎么判断是个合法的括号？
* 一个个判断吗？
* 那，绝对会超时的吧...
* 特么的做不出来了....
*/
class Solution1 {
public:
	vector<string> result;
	string str;
	vector<char> thesis;
	vector<string> generateParenthesis(int n) {
		for (int i = 0; i < n; i++)
		{
			thesis.push_back('(');
			thesis.push_back(')');
		}
		BackTracking(n * 2, -1);
		return result;
	}

	void BackTracking(int len, int index)
	{
		if (str.size() == len)
		{
			cout << "当次的str = " << str << endl;
			if (str[0] == ')') return;
			if (isValid(str))
				result.push_back(str);
			return;
		}

		// 从左或者右括号里面取一个，然后继续回溯
		for (int i = index + 1; i < len; i++)
		{
			str += thesis[i];
			BackTracking(len, i);
			str.pop_back();
		}
	}

	bool isValid(string s)
	{
		if (s[0] == ')') return false;
		stack<char> stk;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(') stk.push(s[i]);
			else
			{
				if (!stk.empty())
				{
					char c = stk.top();
					if (c == '(')
						stk.pop();
				}
				else
					return false;
			}

		}
		if (stk.empty())
			return true;
		else
			return false;
	}
};

/*
* 这个方法也不错
*/
class Solution2 
{
	void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
		if (cur.size() == n * 2) {
			ans.push_back(cur);
			return;
		}

		if (open < n) {
			cur.push_back('(');
			backtrack(ans, cur, open + 1, close, n);
			cur.pop_back();
		}
		if (close < open) {
			cur.push_back(')');
			backtrack(ans, cur, open, close + 1, n);
			cur.pop_back();
		}
	}
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		string current;
		backtrack(result, current, 0, 0, n);
		return result;
	}
};

class Solution {
public:
	int m{};
	vector<string> ans;
	string path;
	vector<string> generateParenthesis(int n) {
		m = n * 2;
		string t(m, 0);
		path = t;

		dfs(0, 0);
		return ans;
	}

	void dfs(int i, int open)
	{
		if (i == m) 
		{	// 括号构造完毕
			ans.emplace_back(path); // 加入答案
			return;
		}


		if (open < m / 2) 
		{	// 可以填左括号
			path[i] = '(';			// 直接覆盖
			dfs(i + 1, open + 1);	// 多了一个左括号
		}
		if (i - open < open) 
		{	// 可以填右括号
			path[i] = ')';			// 直接覆盖
			dfs(i + 1, open);
		}
	}
};

int main()
{
	cout << "hello world" << endl;
	auto res = Solution().generateParenthesis(3);
	for (auto s : res)
		cout << s << endl;

	system("pause");
	return 0;
}

