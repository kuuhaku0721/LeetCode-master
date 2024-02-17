#include <iostream>
#include <string>
using namespace std;

/*
* 给你两个版本号 version1 和 version2 ，请你比较它们。
版本号由一个或多个修订号组成，各修订号由一个 '.' 连接。每个修订号由 多位数字 组成，可能包含 前导零 。
每个版本号至少包含一个字符。修订号从左到右编号，下标从 0 开始，最左边的修订号下标为 0 ，下一个修订号下标为 1 ，
以此类推。例如，2.5.33 和 0.1 都是有效的版本号。
比较版本号时，请按从左到右的顺序依次比较它们的修订号。比较修订号时，只需比较 忽略任何前导零后的整数值 。
也就是说，修订号 1 和修订号 001 相等 。如果版本号没有指定某个下标处的修订号，则该修订号视为 0 。
例如，版本 1.0 小于版本 1.1 ，因为它们下标为 0 的修订号相同，而下标为 1 的修订号分别为 0 和 1 ，0 < 1 。
返回规则如下：
如果 version1 > version2 返回 1，
如果 version1 < version2 返回 -1，
除此之外返回 0。
*/

class Solution {
public:
	int compareVersion(string version1, string version2) {
		do
		{
			string temp1, temp2;

			int mid1 = version1.find('.');
			if (mid1 == -1)
			{
				temp1 = version1;
				version1 = "0";
			}
			else
				temp1 = version1.substr(0, mid1);
			int res1 = atoi(temp1.c_str());
			version1 = version1.substr(mid1 + 1, version1.size() - mid1 - 1);

			int mid2 = version2.find('.');
			if (mid2 == -1)
			{
				temp2 = version2;
				version2 = "0";
			}
			else
				temp2 = version2.substr(0, mid2);
			int res2 = atoi(temp2.c_str());
			version2 = version2.substr(mid2 + 1, version2.size() - mid2 - 1);

			if (res1 > res2)
				return 1;
			if (res1 < res2)
				return -1;

		} while (version1 != "0" || version2 != "0");
		return 0;
	}
};



int main()
{
	cout << "hello world" << endl;
	string version1 = "1.0.1";
	string version2 = "1";
	int res = Solution().compareVersion(version1, version2);
	cout << res << endl;

	system("pause");
	return 0;
}

