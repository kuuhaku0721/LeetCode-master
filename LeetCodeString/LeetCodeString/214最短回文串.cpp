#include <iostream>
#include <string>
using namespace std;

/*
* 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
*/
/*
* 这是道困难题，所以就不去在意空间的使用了
* 先用一个索引位置找到中间位置，然后应该是左边比右边少的，从右边最后一个字符(也加索引)开始一个个往最前面加(加索引)
* 加一次 判断一次是不是回文串，如果是，退出，返回，不是，mid--，重复循环
*/

/*
* 123 / 123 个通过的测试用例  但是 超出内存限制
* 尼玛.....
*/

//官方题解
class Solution {
public:
	string shortestPalindrome(string s) {
		int n = s.size();
		int base = 131, mod = 1000000007;
		int left = 0, right = 0, mul = 1;
		int best = -1;
		for (int i = 0; i < n; ++i) {
			left = ((long long)left * base + s[i]) % mod;
			right = (right + (long long)mul * s[i]) % mod;
			if (left == right) {
				best = i;
			}
			mul = (long long)mul * base % mod;
		}
		string add = (best == n - 1 ? "" : s.substr(best + 1, n));
		reverse(add.begin(), add.end());
		return add + s;
	}
};

class Solution1 {
public:
	string shortestPalindrome(string s) {
		int mid = s.size() / 2;
		int beg = 0;
		int ed = s.size() - 1;
		while (mid != beg)
		{
			string left = s.substr(0, mid);
			string right;
			if (s.size() % 2 == 0)
			{
				right = s.substr(mid, s.size() - mid);
			}
			else
			{
				right = s.substr(mid + 1, s.size() - mid - 1);
			}
			reverse(left.begin(), left.end());
			if (left == right)
			{ //确定是回文串
				break;
			}
			else
			{ //不是回文串，继续循环
				string temp = "";
				temp += s[ed];
				s.insert(beg, temp);
				beg++;
				ed = s.size() - 1 - beg;
				mid = s.size() / 2;
			}
		}
		return s;
	}
};

int main()
{
	cout << "hello world" << endl;
	string s = "abbacd";
	s = Solution().shortestPalindrome(s);
	cout << s << endl;

	system("pause");
	return 0;
}

