#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
* 给定一个许可密钥字符串 s，仅由字母、数字字符和破折号组成。字符串由 n 个破折号分成 n + 1 组。你也会得到一个整数 k 。
* 我们想要重新格式化字符串 s，使每一组包含 k 个字符，除了第一组，它可以比 k 短，但仍然必须包含至少一个字符。
* 此外，两组之间必须插入破折号，并且应该将所有小写字母转换为大写字母。
* 返回 重新格式化的许可密钥 。
*/

/*
* 先找到第一组，也就是第一个-的位置，然后拿到第一组的子串，判断第一个子串大小，如果比k小，那就保留
* 如果比k大，那只留下k个大小，然后从这个位置开始遍历原数组
* 需要一个计数器，每记够k个加一个-，如果碰到-计数器不累加
* 如果最后几个不够k个，那就直接加不用管
*/

class Solution {
public:
	string licenseKeyFormatting(string s, int k) {
		string res = "";
		
		for (int i = s.size() - 1, j = 0; i >= 0; i--)
		{
			if (s[i] == '-')
				continue;
			else
			{
				res += s[i];
				j++;
				if (j == k)
				{
					res += "-";
					j = 0;
				}
			}
		}
		reverse(res.begin(), res.end());
		if (res[0] == '-')
			res = res.substr(1, res.size() - 1);
		transform(res.begin(), res.end(), res.begin(), ::toupper);
		

		return res;
	}
};


int main()
{
	cout << "hello world" << endl;
	string s = "5F3Z-2e-9-w";
	string res = Solution().licenseKeyFormatting(s, 4);
	cout << res << endl;


	system("pause");
	return 0;
}

