#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
* 回文串 是正着读和反着读都一样的字符串。
*/

/*
* 要求是进行分割，然后让每个子串都是回文串...
* 每个..这是个难点
* 从第一个开始遍历，找到第一个可以成为回文串的长度，然后以它为根节点，接着往下找
* 还是回溯的思想，假设到了第二层，找到第一个回文串长度之后，分支出去一个子树，然后加大这个长度，然后再继续
*/

/*
* 哟西,回溯法，真好用
* 不上不下，中规中矩（一般就是50%上下的意思）
*/

class Solution {
public:
	vector<vector<string>> result;
	vector<string> vec;
	vector<vector<string>> partition(string s) {
		if (s.size() == 0) return result;
		BackTracking(s, 0);
		return result;
	}

	void BackTracking(string s, int index)
	{
		if (index == s.size())
		{
			result.push_back(vec);
			return;
		}

		string cur{};
		for (int i = index; i < s.size(); i++)
		{
			cur += s[i];
			if (IsPalindrome(cur))
			{	// 找到一个回文串
				vec.push_back(cur);
				BackTracking(s, i + 1);
				vec.pop_back();
			}
		}
	}

	bool IsPalindrome(string s)
	{
		string remain = s;
		reverse(s.begin(), s.end());
		if (s == remain)
			return true;
		else
			return false;
	}
};

int main()
{
	cout << "hello world" << endl;
	string s = "aaaaa";
	vector<vector<string>> result = Solution().partition(s);
	for (vector<string> v : result)
	{
		for (string s : v)
			cout << s << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}

