#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
* 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
* 如果可以，返回 true ；否则返回 false 。
* magazine 中的每个字符只能在 ransomNote 中使用一次。
*/

/*
* 过了，但是完成度很低，得看答案
*/

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		//把magazine里的字符全部存到map<char, int>里面
		//遍历ransomNote，看当前char在magazine中有没有
		//如果有int-1，没有或者int为0返回false
		map<char, int> chars;
		for (char c : magazine)
		{
			if (chars.find(c) == chars.end())
			{
				chars.insert(pair<char, int>(c, 1));
			}
			else
			{
				chars[c]++;
			}
		}
		for (char c : ransomNote)
		{
			auto it = chars.find(c);
			if (it == chars.end() || (it->second == 0))
				return false;
			else
				it->second--;
		}

		return true;
	}
};


int main()
{
	cout << "hello world" << endl;

	string ransomNote = "aa", magazine = "ab";
	bool res = Solution().canConstruct(ransomNote, magazine);
	if (res)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}

