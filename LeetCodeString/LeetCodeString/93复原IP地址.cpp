#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
* 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
* 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，
* 这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
*/

/*
* 上一题，也就是131里面，进行了判断是否是回文串然后选择插入
* 那这一题就可以把判断的函数稍加修改再次利用
* 这次判断的标准是：长度要到最大，也就是每个数都要用上，然后拆出来的四个部分每部分都要在0-255范围内，然后才能插入
* 
* 哟西~~~~~~~！！
* 不妄我奋战一个小时的成功啊
* 总算是自己做出来了
* 虽然中规中矩还是50%，但毕竟回溯，慢点能理解
*/

class Solution {
public:
	vector<string> result;
	vector<string> vec;
	vector<string> restoreIpAddresses(string s) {
		if (s.size() == 0) return result;
		BackTracking(s, -1);
		return result;
	}

	void BackTracking(string s, int index)
	{
		if (vec.size() == 3)
		{
			string lastone = s.substr(index + 1, s.size() - index - 1);
			if (!isValid(lastone) || lastone == "") return;

			string res = "";
			for (string s : vec)
			{
				if (isValid(s))
					res += s + ".";
				else
					return;
			}
			res += lastone;
			result.push_back(res);
			return;
		}

		string cur{};
		for (int i = index + 1; i < s.size(); i++)
		{
			cur += s[i];
			cout << "当前放入的cur字符串是: " << cur << endl;
			vec.push_back(cur);
			BackTracking(s, i);
			vec.pop_back();
		}
	}

	bool isValid(const string& s) 
	{
		if (s[0] == '0' && s.size() != 1) 
		{
			return false;
		}
		int num = 0;
		for (int i = 0; i < s.size(); i++) 
		{
			if (s[i] > '9' || s[i] < '0') 
			{
				return false;
			}
			num = num * 10 + (s[i] - '0');
			if (num > 255) 
			{ 
				return false;
			}
		}
		return true;
	}
};


int main()
{
	cout << "hello world" << endl;

	string s = "25525511135";
	vector<string> res = Solution().restoreIpAddresses(s);
	for (string s : res)
	{
		cout << s << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

