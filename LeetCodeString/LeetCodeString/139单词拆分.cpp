#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
* 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
* 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
*/

/*
* 就这么用哈希表会解决不了一个情况，如果同一个字母开头的不止一个的话，就没法判断了
* 可以用unordered_multimap，于是乎，想到了回溯，因为要一个个判断是否符合.
* 很好，写不出来
* 还少判断一个条件，没看单词是否相等，目前是只判断了开头的有没有，然后直接加长度了，没看这个单词对不对
* CV吧还是
*/

class Solution1 {
public:
	unordered_multimap<char, string> umultimap;
	bool wordBreak(string s, vector<string>& wordDict) {
		for (string str : wordDict)
		{
			umultimap.insert(make_pair(str[0], str));
		}

		// 从unordered_multimap中find Key出来结果是个链表，然后需要从这个链表一个个判断
		bool flag = false;
		int i;
		for (i = 0; i < s.size();)
		{
			int cnt = umultimap.count(s[i]);
			if (cnt > 1)
			{
				auto range = umultimap.equal_range(s[i]);
				int p = i;
				for (auto it = range.first; it != range.second; it++)
				{
					flag |= Tracking(s, i + it->second.size());
					p = max(p, (int)(i + it->second.size()));
				}
				i = p;
			}
			else if (cnt <= 0)
			{
				flag |= false;
				break;
			}
			else
			{	// 就一个，原地直接判断
				i += umultimap.find(s[i])->second.size();
			}
		}
		return flag;
	}

	bool Tracking(string s, int pos)
	{
		bool flag = false;
		int i;
		for (i = pos; i < s.size();)
		{
			int cnt = umultimap.count(s[i]);
			if (cnt > 1)
			{
				auto range = umultimap.equal_range(s[i]);
				int p = i;
				for (auto it = range.first; it != range.second; it++)
				{
					flag |= Tracking(s, i + it->second.size());
					p = max(p, (int)(i + it->second.size()));
				}
				i = p;
			}
			else if (cnt <= 0)
			{
				flag |= false;
				break;
			}
			else
			{
				i += umultimap.find(s[i])->second.size();
			}
		}
		return flag;
		/*if (i >= s.size()) 
			return true;
		else
			return flag;*/
	}
};

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); i++) 
		{   // 遍历背包
			for (int j = 0; j < i; j++) 
			{   // 遍历物品
				string word = s.substr(j, i - j); //substr(起始位置，截取的个数)
				if (wordSet.find(word) != wordSet.end() && dp[j]) 
				{
					dp[i] = true;
				}
			}
		}
		return dp[s.size()];
	}
};


int main()
{
	cout << "hello world" << endl;
	string s = "abcd";
	vector<string> wordDict{ "a", "abc", "b", "c", "cd"};
	cout << Solution().wordBreak(s, wordDict) << endl;

	system("pause");
	return 0;
}

