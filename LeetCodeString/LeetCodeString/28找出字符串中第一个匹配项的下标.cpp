#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
* 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
* 如果 needle 不是 haystack 的一部分，则返回  -1 。
*/


/*
* 笑死，这题原本是用KMP解的，
* 但是吧，一个API调用解决，今天又是劳累的一天呢
*/
class Solution {
public:
	int strStr(string haystack, string needle) {
		return haystack.find(needle);
	}
};


int main()
{
	cout << "hello world" << endl;
	string haystack = "sadbutsad", needle = "sad";
	int res = Solution().strStr(haystack, needle);
	cout << res << endl;

	system("pause");
	return 0;
}

