#include <iostream>
#include <string>
using namespace std;

/*
* 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
* 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
* 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
* 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格
*/

/*
* c++并不提供trim和split，因此这道题就是让自己写一个split
*/

/*
* 虽然写出来了吧，但是吧，时间空间全都是倒数水平，啧啧啧啧
*/

#include <vector>
class Solution {
public:
	string reverseWords(string s) {
		string result = "";
		vector<string> v;
		auto begin = s.begin();
		while (*begin == ' ') begin++; //到这里找到第一个不为空的字符
		while(begin != s.end())
		{
			auto mid = find(begin, s.end(), ' ');  //截取一个单词
			for (auto it = begin; it != mid; it++)
				result += *it;
			v.push_back(result);
			result = "";
			if (mid == s.end()) break;
			begin = mid++;  //begin移动到刚才已经截取过的单词的末尾
			while (*begin == ' ') begin++;  //然后接着移动到下一个不是空的字符前
		}
		result = "";
		for (int i = v.size() - 1; i >= 0; i--)
		{
			if (i == 0)
				result += v[i];
			else
				result = result + v[i] + " ";
		}

		return result;
	}
};

int main()
{
	cout << "hello world" << endl;

	string str = "the sky is blue";
	str = Solution().reverseWords(str);
	cout << str << endl;

	system("pause");
	return 0;
}

