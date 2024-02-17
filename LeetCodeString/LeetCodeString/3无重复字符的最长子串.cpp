#include <iostream>
#include <string>
#include <map>
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
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> mapLastIndex;
		int res = 0;
		int coil = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (mapLastIndex.count(s[i]) == 0)
			{
				mapLastIndex[s[i]] = i;
				coil++;
			}
			else
			{
				res = max(res, i - mapLastIndex[s[i]]);
				mapLastIndex[s[i]] = i;
				coil = 1;
				continue;
			}
			res = max(res, coil);
		}
		return res;
	}
};

int main()
{
	cout << "hello world" << endl;
	string str = "abba";
	cout << Solution().lengthOfLongestSubstring(str) << endl;

	system("pause");
	return 0;
}

