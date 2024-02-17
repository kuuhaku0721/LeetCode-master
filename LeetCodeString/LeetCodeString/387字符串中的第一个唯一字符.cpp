#include <iostream>
#include <string>
using namespace std;

/*
* 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 
*/
/*
* 喵的笑死，怎么就没想到左查查右查查这办法呢
* 官方答案倾向于使用hash表，也就是unordered_map 利用键值对的特性两次循环，感觉不如直接调用api 但是值得学习
*/
class Solution {
public:
	int firstUniqChar(string s) {
		for (int i = 0; i < s.size(); i++)
		{
			if (s.find(s[i]) == s.rfind(s[i]))
				return i;
		}
		return -1;
	}
};


int main()
{
	cout << "hello world" << endl;

	string str = "aaaabbbbc";
	int index = Solution().firstUniqChar(str);
	cout << index << endl;

	system("pause");
	return 0;
}

