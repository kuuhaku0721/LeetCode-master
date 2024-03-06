#include <iostream>
#include <string>
using namespace std;

/*
* 样例输入
4
abababdb a b

样例输出
6

样例说明
符合条件的子串如下所示，中括号内是该子串：

[abab]abdb
[ababab]db
[abababdb]
ab[abab]db
ab[ababdb]
abab[abdb]

示例输入：a开头，b结尾，并且ab中间数量大于等于1 并且总长度大于K
so 双重循环？感觉会超时，但是能出结果就行 时间复杂度O(n!)
*/

// 不出意料的超时，但是规模能到10w级才超时，也就是10w以下是可以过的，那就万事大吉了，就这吧

void SubStr()
{
	int res = 0;
	int k;
	cin >> k;
	string str;
	cin >> str;
	char beg, end;
	cin >> beg >> end;
	
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == beg)
		{
			for (int j = i + k - 1; j < str.size(); ++j)
			{
				if (str[j] == end) res++;
			}
		}
	}
	cout << res << endl;
}


int main()
{
	SubStr();

	system("pause");
	return 0;
}

