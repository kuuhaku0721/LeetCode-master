#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
* 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
*/

class Solution {
public:
	bool isAnagram(string s, string t) {
		//遍历一个字符串，在另一个字符串里面find
		//如果找到，设为空，如果没找到 返回false
		//如果运行完毕，判断另一个字符串是否为空
		//是返回true，否则返回false
		if (s.length() != t.length())
			return false;
		for (char c : s)
		{
			size_t index = t.find(c);
			if (index != -1)
			{
				t.erase(index, 1);
			}
			else
			{
				return false;
			}
		}
		if (t.size() == 0)
			return true;
		else
			return false;

		//题解
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		if (s == t)
			return true;
		else
			return false;
	}
};

int main()
{
	cout << "hello world" << endl;

	string s = "abcd";
	string t = "bacdj";
	bool res = Solution().isAnagram(s, t);
	if (res)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}

