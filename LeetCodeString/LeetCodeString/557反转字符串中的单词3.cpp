#include <iostream>
#include <string>
using namespace std;

/*
* 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
*/

/*
* string也符合STL的使用规范 可以用迭代器可以用find 
* 利用迭代器，用find去寻找' '  这样分割出一个个单词 然后reverse
* 首先处理只有一个单词的情况
*/


class Solution {
public:
	string reverseWords(string s) {
		for (auto left = s.begin(); left != s.end();)
		{
			auto mid = find(left, s.end(), ' ');
			if (mid != s.end())
			{
				reverse(left, mid);
				left = mid;
				left++;
			}
			else
			{
				reverse(left, mid);
				break;
			}
		}
		return s;
	}
};

int main()
{
	cout << "hello world" << endl;

	string s = "Let's take LeetCode contest";
	s = Solution().reverseWords(s);
	cout << s << endl;


	system("pause");
	return 0;
}

