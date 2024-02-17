#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
* 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
*/

/*
* 如果要保持重复，那么子串长度只能是原串的 /2到/自己的一半长，也就是2到s.size()/2的长度
* 这样写绝对超时，评论区给了一个nb的思路
* 直接用一个str=s+s；然后去除首尾元素之后，如果在剩下的子串中包含它自己，那一定返回true
*/

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		string str = s + s;
		cout << str << endl;
		str = str.substr(1, str.size() - 2);
		cout << str << endl;
		if (str.find(s) != -1)
			return true;
		else
			return false;
	}
};


int main()
{
	cout << "hello world" << endl;
	string s = "aba";
	bool res = Solution().repeatedSubstringPattern(s);
	if (res)
		cout << "true" << endl;
	else
		cout << "false" << endl;



	system("pause");
	return 0;
}

