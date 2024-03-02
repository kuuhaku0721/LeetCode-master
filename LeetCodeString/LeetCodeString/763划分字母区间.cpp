#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
* 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
* 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
* 返回一个表示每个字符串片段的长度的列表。
*/

/*
* 还真是，应该考察的是map而不是贪心
* 直接记录每个字母出现的最后位置
* 然后记录一个初始位置
* 开始遍历整个字符串，因为已经存储过了最后出现位置
* 直接用存储的值减去当前位置就是长度，然后保存一个最长长度就行了
* 还要保存一个end值，用来当作切换分组的标志
*/

class Solution {
public:
	vector<int> partitionLabels(string s) {
		unordered_map<char, int> mapChar;
		for (int i = 0; i < s.size(); i++)
		{
			mapChar[s[i]] = i;	// 记录每一个字母出现的最后位置
		}
		vector<int> res;
		int beg = 0, end = 0; // 当前这一组的起始和结束下标
		int len = 0;
		for (int i = 0; i < s.size(); i++)
		{
			beg = min(beg, i); // 起始下标保持在子串开头
			end = max(end, mapChar[s[i]]); // 结束下标是最长位置
			len = max(len, mapChar[s[i]] - beg + 1);
			if (i == end)
			{
				res.push_back(len);
				len = 0;
				beg = i + 1;
			}
		}
		return res;
	}
};

int main()
{
	cout << "hello world" << endl;
	string s = "ababcbacadefegdehijhklij";
	auto res = Solution().partitionLabels(s);
	for (int i : res)
	{
		cout << i << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

