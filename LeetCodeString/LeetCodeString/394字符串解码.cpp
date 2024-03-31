#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
* 给定一个经过编码的字符串，返回它解码后的字符串。
* 
* 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
* 
* 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
* 
* 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
* 
* 输入：s = "3[a2[c]]"
* 输出："accaccacc"
*/

class Solution {
public:
	string decodeString(string s) {
		stack<char> stk;
		for (int i = 0; i < s.size(); i++)
		{
			stk.push(s[i]);
			if (s[i] == ']')
			{
				stk.pop();  // 先把]弹出去，不进行运算
				string str = "";
				while (stk.top() != '[')
				{
					str += stk.top();
					stk.pop();
				}
				stk.pop();
				int num = 0, rate = 1;
				while (!stk.empty() && stk.top() >= '0' && stk.top() <= '9')
				{
					int n = (stk.top() - '0') * rate;
					stk.pop();
					num += n;
					rate *= 10;
				}
				// 如果超时，就在这儿优化一下
				for (int j = 0; j < num; j++)
				{
					for (int k = str.size() - 1; k >= 0; --k)
					{
						stk.push(str[k]);
					}
				}
			}
		}
		string res = "";
		while (!stk.empty())
		{
			res += stk.top();
			stk.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
	cout << "hello world" << endl;
	string s = "100[leetcode]";
	s = Solution().decodeString(s);
	cout << s << endl;

	system("pause");
	return 0;
}

