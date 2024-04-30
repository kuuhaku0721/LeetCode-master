#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
* 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
* 注意：
* 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
* 如果 s 中存在这样的子串，我们保证它是唯一的答案。
*/

/*
* 265/268 很好了，我挣扎了，我努力了，我做出来了
* 但是超时了，不管了，超时就超时
*/

class Solution1 {
public:
	string minWindow(string s, string t) {
		string resStr = "";
		if (s.size() < t.size()) return resStr;
		unordered_map<char, int> ump;  // char:t中的字符  int:该字符出现的次数
		for (char c : t)
			ump[c]++;
		vector<int> indices;
		for (int i = 0; i < s.size(); ++i)
		{
			if (ump.find(s[i]) != ump.end())
			{
				indices.push_back(i);
			}
		}

		string substr = "";
		bool flag = false;
		int cnt = 0;
		for (int& idx : indices)
		{
			auto bakup_mp = ump;
			for (int i = idx; i < s.size(); i++)
			{
				if (bakup_mp.find(s[i]) != bakup_mp.end())
				{
					if (bakup_mp[s[i]] != 0)
					{
						bakup_mp[s[i]]--;
						flag = true;
						substr += s[i];
						cnt++;
						if (cnt == t.size())
						{
							if (resStr == "")
								resStr = substr;
							else
								resStr = resStr.size() <= substr.size() ? resStr : substr;
							flag = false;
							cnt = 0;
							substr = "";
							break;
						}
					}
					else
						if (flag)
							substr += s[i];
				}
				else
				{
					if (flag)
						substr += s[i];
				}
			}
			// 如果上面的cnt != t.size()的话，运行到这里是没有经过重置这一步的，所以要再次判断，然后重置
			// TODO: 总和先不算了，反正已经退出来了，直接重置状态，等待进入下一轮循环就可以了
			flag = false;
			cnt = 0;
			substr = "";
		}
		return resStr;
	}
};

// 官解
class Solution {
public:
	unordered_map <char, int> ori, cnt;

	bool check() {
		for (const auto& p : ori) {
			if (cnt[p.first] < p.second) {
				return false;
			}
		}
		return true;
	}

	string minWindow(string s, string t) {
		for (const auto& c : t) {
			++ori[c];
		}

		int l = 0, r = -1;
		int len = INT_MAX, ansL = -1, ansR = -1;

		while (r < int(s.size())) {
			if (ori.find(s[++r]) != ori.end()) {
				++cnt[s[r]];
			}
			while (check() && l <= r) {
				if (r - l + 1 < len) {
					len = r - l + 1;
					ansL = l;
				}
				if (ori.find(s[l]) != ori.end()) {
					--cnt[s[l]];
				}
				++l;
			}
		}

		return ansL == -1 ? string() : s.substr(ansL, len);
	}
};

int main()
{
	cout << "hello world" << endl;
	string s = "aaaaaaaaaaaabbbbbcdd";
	string t = "abcdd";
	// 输出 bcddc
	// 预期 abbbbbcdd
	string res = Solution().minWindow(s, t);
	cout << res << endl;

	system("pause");
	return 0;
}

