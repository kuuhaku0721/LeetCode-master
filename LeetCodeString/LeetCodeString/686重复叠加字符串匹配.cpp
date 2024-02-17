#include <iostream>
#include <string>
using namespace std;

/*
* 给定两个字符串 a 和 b，寻找重复叠加字符串 a 的最小次数，使得字符串 b 成为叠加后的字符串 a 的子串，如果不存在则返回 -1。
注意：字符串 "abc" 重复叠加 0 次是 ""，重复叠加 1 次是 "abc"，重复叠加 2 次是 "abcabc"。
*/
/*
* 终止长度 2*A+B 自己找也不是不可以，但是不如直接看别人总结来的快啊
* 不行啊，你作为一个中等难度的题明显不够格啊
*/

class Solution {
public:
	int repeatedStringMatch(string a, string b) {
		if (b == "") return 0;
		string t = a;
		int res = 1;
		while (t.size() <= (2*a.size() + b.size()))
		{
			if (t.find(b) != -1)
			{
				return res;
			}
			else
			{
				t += a;
				res++;
			}
		}
		return -1;
	}
};


int main()
{
	cout << "hello world" << endl;
	string a = "abcd";
	string b = "cdabcdab";
	int res = Solution().repeatedStringMatch(a, b);
	cout << res << endl;

	system("pause");
	return 0;
}

