#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
* 给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。
* 输入：s = "owoztneoer"
* 输出："012"
*/

/*
* 英文字母一定是匹配的，那就先排序
* zero one two three four five six seven eight nine
* 有z一定有zero	0
* 有w一定有two	2
* 有x一定有six	6
* 有g一定有eight	8
* 有u一定有four	4
* 剩下 one three five seven nine
* 有f一定有five	5
* 有s一定有seven	7
* 有o一定有one	1
* 有t一定有three	3
* 最后只剩下nine 9 有几个i就有几个9
*/

class Solution {
public:
	string originalDigits(string s) {
		string res = "";
		sort(s.begin(), s.end());
		string judge = "zwxgu";
		for (int i = 0; i < judge.size(); i++)
		{
			innerchange(s, judge[i], res);
			if (s == "") break;
		}
		judge = "fsot";
		for (int i = 0; i < judge.size(); i++)
		{
			innerchange(s, judge[i], res);
			if (s == "") break;
		}
		innerchange(s, 'i', res);

		sort(res.begin(), res.end());
		return res;
	}

	void innerchange(string &s, char c, string& res)
	{
		string alpha;
		string numer;
		switch (c)
		{
		case 'z':
			alpha = "zero";
			numer = "0";
			break;
		case 'w':
			alpha = "two";
			numer = "2";
			break;
		case 'x':
			alpha = "six";
			numer = "6";
			break;
		case 'g':
			alpha = "eight";
			numer = "8";
			break;
		case 'u':
			alpha = "four";
			numer = "4";
			break;
		case 'f':
			alpha = "five";
			numer = "5";
			break;
		case 's':
			alpha = "seven";
			numer = "7";
			break;
		case 'o':
			alpha = "one";
			numer = "1";
			break;
		case 't':
			alpha = "three";
			numer = "3";
			break;
		case 'i':
			alpha = "nine";
			numer = "9";
			break;
		}
		if (s.find(c) != -1)
		{
			int num = count(s.begin(), s.end(), c);
			for (int i = 0; i < alpha.size(); i++)
			{
				int index = s.find(alpha[i]);
				s.replace(index, num, "");
			}
			for (int i = 0; i < num; i++)
			{
				res += numer;
			}
		}
	}
};


int main()
{
	cout << "hello world" << endl;
	string s = "owoztneoer";
	s = Solution().originalDigits(s);
	cout << s << endl;


	system("pause");
	return 0;
}

