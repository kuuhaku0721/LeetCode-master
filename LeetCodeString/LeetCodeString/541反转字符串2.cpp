#include <iostream>
#include <string>
using namespace std;

/*
* 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
* 如果剩余字符少于 k 个，则将剩余字符全部反转。
* 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
*/

/*
* 有大小限制 先判断s.size()和k的大小
* 有每计数多少 用%
* 因为要将剩余也翻转 额外调用一个反转函数
* 尽量不用api
*/

/*
* 官方题解 一个i += 2*k的循环
* reverse(s.begin() + i, s.begin() + min(i + k, n));
* 用一下reverse 结束
*/
class Solution {
public:
	string reverseStr(string s, int k) {
		if (k == 1) return s;
		string result{};
		int cnt = 0;
		for (int i = 0; i < s.size(); i+=2*k)
		{
			if (s.size() - i < k)
			{
				for (int j = s.size() - 1; j >= i; j--)
				{
					result += s[j];
				}
			}
			else if ((s.size() - i >= k) && (s.size() - i < 2 * k))
			{
				for (int j = i+k - 1;  j >= i;  j--)
				{
					result += s[j];
				}
				for (int j = i+k; j < s.size(); j++)
				{
					result += s[j];
				}
			}
			else
			{
				cnt += 2 * k;
				for (int j = (cnt - k) - 1; j >= i; j--)
				{
					result += s[j];
				}
				for (int j = i + k;  j < cnt;  j++)
				{
					result += s[j];
				}
			}
		}
		return result;
	}
};


int main()
{
	cout << "hello world" << endl;

	string s = "krmyfshbspcgtesxnnljhfursyissjnsocgdhgfxubewllxzqhpasguvlrxtkgatzfybprfmmfithphckksnvjkcvnsqgsgosfxc";
	cout << s.size() << endl;
	s = Solution().reverseStr(s, 20);
	cout << s << endl;
	cout << "jlnnxsetgcpsbhsfymrkhfursyissjnsocgdhgfxtxrlvugsaphqzxllwebukgatzfybprfmmfithphccxfsogsgqsnvckjvnskk" << endl;


	system("pause");
	return 0;
}

