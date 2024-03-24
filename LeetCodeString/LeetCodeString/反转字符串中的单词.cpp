#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		vector<string> vec;
		string str{};
		for (char c : s)
		{
			if (c == ' ')
			{
				if(str != "")
				{
					vec.push_back(str);
					str = "";
				}
			}
			else
				str += c;
		}
		if (str != "") vec.push_back(str);

		reverse(vec.begin(), vec.end());
		str = "";
		for (string t : vec)
			str += t + " ";
		str.resize(str.size() - 1);

		return str;
	}
};

int main()
{
	cout << "hello world" << endl;
	string s = "hello world 1 2 3 4  5   6   7   8    9";
	cout << Solution().reverseWords(s) << endl;

	system("pause");
	return 0;
}

