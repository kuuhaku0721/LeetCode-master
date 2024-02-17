
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

* 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
*/

class Solution {
public:
	void reverseString(vector<char>& s) {
		int len = s.size() / 2;
		int beg = 0;
		int end = s.size() - 1;
		while (beg != end + 1)
		{
			char temp = s[beg];
			s[beg] = s[end];
			s[end] = temp;
			/*
			* 这一部分允许使用swap
			* 整道题目允许使用vector::reverse()
			*/
			beg++, end--;
		}
		for (char c : s)
		{
			cout << c;
		}
		cout << endl;
	}
};


int main()
{
	cout << "请输入:" << endl;
	vector<char> vc;

	string str{};
	cin >> str;
	char* pch = const_cast<char*>(str.c_str());
	int i = 0;
	while (pch[i] != '\0')
	{
		vc.push_back(pch[i]);
		i++;
	}

	Solution().reverseString(vc);

	system("pause");
	return 0;
}

