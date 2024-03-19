#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
using namespace std;

/*
* 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
* 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
*/

/*
* 题目限定了长度，p的长度是固定的，所以就可以循环遍历了
* KMP....倒是用不上，大概，除非超时
* 考虑的写法是排序，要的是异位词，但没说必须顺序一致，都异位了，顺序肯定不用管吧
* 很好，超时了，字符串超过2w的长度就超时
*/

class Solution1 {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		if (s.size() < p.size()) return res;

		unordered_map<char, int> umapp;
		for (char c : p)
			umapp[c]++;
		int len = p.size();
		for (int i = 0; i <= s.size() - len; i++)
		{
			string str = s.substr(i, len);
			unordered_map<char, int> umap;
			for (char c : str)
				umap[c]++;
			
			bool flag = true;
			for(char c : p)
				if (umap[c] != umapp[c])
				{
					flag = false;
					break;
				}
			if (flag)
				res.push_back(i);
		}
		return res;
	}
};

/*
* 一个不会超时的答案
*/
class Solution {
public:
	vector<int> findAnagrams(string s, string p)
	{
		int slen = s.size(), plen = p.size(), sum = 0, init = 0;
		if (slen < plen)
			return vector<int>();

		char ch;
		for (int i = 0; i < plen; i++)
		{
			ch = s[i];
			sum = (sum + (ch * (ch - 18) * (ch - 'a'))) % 1584952641;
			ch = p[i];
			init = (init + (ch * (ch - 18) * (ch - 'a'))) % 1584952641;
		}

		vector<int> ans;
		for (int i = plen; i <= slen; i++)
		{
			if (init == sum)
				ans.push_back(i - plen);

			ch = s[i - plen];
			sum = sum - (ch * (ch - 18) * (ch - 'a'));
			ch = s[i];
			sum = (sum + (ch * (ch - 18) * (ch - 'a'))) % 1584952641;
		}
		return ans;
	}
};

int main()
{
	cout << "hello world" << endl;
	string s = "cbaebabacd";
	string q = "abc";
	auto vec = Solution().findAnagrams(s, q);
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;


	system("pause");
	return 0;
}

