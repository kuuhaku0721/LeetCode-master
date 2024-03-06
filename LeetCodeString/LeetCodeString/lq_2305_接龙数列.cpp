#include <iostream>
#include <string>
using namespace std;

/*
* 样例输入
5
11 121 22 12 2023

样例输出
1

样例说明
删除22，剩余11 , 121 , 12 , 2023 是接龙数列。
*/

/*
* 很好，无能为力了
*/

void Solitaire()
{
	int cnt = 0;
	string str = "";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (str == "") str += s;
		else
		{
			if (str[str.size() - 1] == s[0])
				str += s;
			else
				cnt++;
		}
	}
	//cout << "str = " << str << endl;
	cout << cnt << endl;
}

int main()
{
	Solitaire();

	system("pause");
	return 0;
}

