#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

/*
* 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/


/*
* 总归是要遍历，索性遍历次数越少越好，也就是避免嵌套循环
* 那么就用O(n)的一次遍历解决
* 用一个数组记录当前字符上次出现的位置
* 当它再次出现的时候就减去它上次出现的位置，结果就是中间子串长
* 最后返回这个数组的最大值就行
* 如果一次字符出现了超过两次，那么每次只留最大的
* 
* 如果这么弄的话，其实map比较方便，key是字符，value是出现位置
* 
* 
* 没做出来，等等之后回来再看吧 
*/

/*
* 好的，我又回来了
* 看看分类，这题属于滑动窗口，所以要用窗口的思想去做
* 希望能做出来
* 滑动窗口，窗口就拿一个字符串当，如果不存在相同的，就++，如果存在，那就找到第一个出现的位置，把前面的位置全清掉
* 然后继续循环，窗口往前增长，每次增长都要保留长度
* 
* 你猜我卡在哪了？ 通过用例985/987 卡在了 s = " "  预期1实际输出0
* 好了，100%，我感觉我进步了，毕竟上次见到你卡半天不会写
*/

class Solution1 {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) return 0;
		string str = "";
		str += s[0];
		int ans = str.size();
		for (int i = 1; i < s.size(); i++)
		{
			if (str.find(s[i]) != -1)
			{
				auto it = find(str.begin(), str.end(), s[i]);
				str.erase(str.begin(), it + 1);
				str += s[i];
			}
			else
				str += s[i];
			ans = max(ans, (int)str.size());
		}
		return ans;
	}
};

/*
* 二刷
* 那这么看的话，这题写三遍了，笑死wwwwww
* 反正都要用find，那索性就让find也更快一点
* 嘶.....反倒没有上面那个快，很神奇
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> uset;
		int ans = 0;
		string str = "";
		int cnt = 0;
		for (int i = 0; i < s.size();)
		{
			if (uset.find(s[i]) == uset.end())
			{
				str += s[i];
				uset.insert(s[i]);
				cnt++;
				i++;
			}
			else
			{
				ans = max(ans, cnt);
				uset.erase(str[0]);
				str.erase(str.begin());
				cnt = str.size();
				// 这里i不再++，清空完窗口之后，从当前位置重新开始
			}
		}
		ans = max(ans, cnt);
		return ans;
	}
};

int main()
{
	cout << "hello world" << endl;
	// string str = "abba";			// 2
	// string str = "abcabcbb";		// 3
	// string str = "bbbbb";		// 1
	string str = "dvdf";			// 3
	cout << Solution().lengthOfLongestSubstring(str) << endl;

	system("pause");
	return 0;
}

