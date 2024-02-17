#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
* 神奇字符串 s 仅由 '1' 和 '2' 组成，并需要遵守下面的规则：
神奇字符串 s 的神奇之处在于，串联字符串中 '1' 和 '2' 的连续出现次数可以生成该字符串。
s 的前几个元素是 s = "1221121221221121122……" 。如果将 s 中连续的若干 1 和 2 进行分组，可以得到 "1 22 11 2 1 22 1 22 11 2 11 22 ......" 。
每组中 1 或者 2 的出现次数分别是 "1 2 2 1 1 2 1 2 2 1 2 2 ......" 。上面的出现次数正是 s 自身。
给你一个整数 n ，返回在神奇字符串 s 的前 n 个数字中 1 的数目。
*/

/*
* 完全看不出来规律呢...所以放弃，直接看大佬总结出来的规律
* str的构造：
* index = 0，str = “”，尾部添加一个'1'，str更新为“1”
* index = 1，str = “1”，尾部添加str[index] - '0' = 2个 ‘2’，str 更新为 “122”，
* index = 2，str = “122”，尾部添加str[index] - '0' = 2个 ‘1’，str 更新为 “122 11”，
* index = 3，str = “12211”，尾部添加str[index] - '0' = 1个 ‘2’，str更新为“12211 2”
* index = 4，str = “122112”，尾部添加str[index] - '0' = 1个 ‘1’，str更新 “122112 1”，
* index = 5，str = “1221121”，尾部添加str[index] - '0' = 2个 ‘2’，str更新为“1221121 22”
* index = 6，str = “122112122”，尾部添加str[index] - '0' = 1个‘1’，str 更新 “122112122 1”，
* index = 7，str = “1221121221”，尾部添加str[index] - '0' = 2个‘2’，str更新为“1221121221 22”
* ...
* 先构造字符串str，然后统计1的数量是结果，可以在构造时直接统计下来1的数量
* 给的n当作构造次数长度一定是比n要长的
* 0 和 1 对不上，也就是要直接从2开始
*/


class Solution {
public:
	int magicalString(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 1;
		string str = "122";

		for (int i = 2; i <= n; i++)
		{
			if (i % 2 == 0)
			{ //追加1
				for (int j = 0; j < (int)(str[i] - '0'); j++)
				{
					str += "1";
				}
			}
			else
			{ //追加2
				for (int j = 0; j < (int)(str[i] - '0'); j++)
				{
					str += "2";
				}
			}
		}
		str = str.substr(0, n);
		return count(str.begin(), str.end(), '1');
	}
};


int main()
{
	cout << "hello world" << endl;
	int n = 6;
	n = Solution().magicalString(n);
	cout << n << endl;


	system("pause");
	return 0;
}

