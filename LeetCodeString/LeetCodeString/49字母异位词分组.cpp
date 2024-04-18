#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
* 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
* 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
*/
/*
* 神奇啊，虽然这个方法很耗空间，但是时间意外的快啊
*/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> vec;
		unordered_map<string, vector<string>> umap;
		for (string str : strs)
		{
			string s = str;
			sort(s.begin(), s.end());
			umap[s].push_back(str);
		}
		for (auto it = umap.begin(); it != umap.end(); it++)
		{
			vec.push_back(it->second);
		}
		return vec;
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

