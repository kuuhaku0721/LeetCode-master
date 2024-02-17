#include <iostream>
#include <string>

using namespace std;

/*
* 给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
*/

class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.empty()) return 0;
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);

		int index = s.rfind(" ");
		string lastStr = s.substr(index + 1);
		return lastStr.size();
	}
};


int main()
{
	cout << "hello world" << endl;

	string s = "  hello world  ";
	cout << Solution().lengthOfLastWord(s) << endl;

	system("pause");
	return 0;
}

