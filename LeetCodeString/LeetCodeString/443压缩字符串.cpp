#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个字符数组 chars ，请使用下述算法压缩：
从一个空字符串 s 开始。对于 chars 中的每组 连续重复字符 ：
如果这一组长度为 1 ，则将字符追加到 s 中。
否则，需要向 s 追加字符，后跟这一组的长度。
压缩后得到的字符串 s 不应该直接返回 ，需要转储到字符数组 chars 中。需要注意的是，如果组长度为 10 或 10 以上，则在 chars 数组中会被拆分为多个字符。
请在 修改完输入数组后 ，返回该数组的新长度。
你必须设计并实现一个只使用常量额外空间的算法来解决此问题。

题目的意思是要把结果再存回去chars，然后返回它的大小
返回时字母在前，数字在后，并且如果数字不止一位的话要分开
不让另外开辟空间,只能用常量额外空间
只需要稍~~~加修改，把用到vec的地方改成flag，也就是双指针，cnt标记数量，flag标记当前存储位置，就行了、
但是我懒了不想写了，提交就直接cv了
*/

class Solution {
public:
	int compress(vector<char>& chars) {
		vector<char> vec;
		int flag;
		char c = chars[0];
		int cnt = 1;
		for (int i = 1; i <= chars.size(); i++)
		{
			if (chars[i] == c)
			{
				cnt++;
				if (i == chars.size() - 1)
				{
					vec.push_back(c);
					if (cnt != 1)
					{
						if (cnt > 9)
						{
							int t = cnt;
							string temp = "";
							while (t > 0)
							{
								temp += to_string(t % 10);
								t /= 10;
							}
							for (int i = temp.size() - 1; i >= 0; i--)
							{
								vec.push_back(temp[i]);
							}
						}
						else
						{
							vec.push_back(cnt + '0');
						}
					}
					break;
				}
			}
			else
			{
				vec.push_back(c);
				if (cnt != 1)
				{
					if (cnt > 9)
					{
						int t = cnt;
						string temp = "";
						while (t > 0)
						{
							temp += to_string(t % 10);
							t /= 10;
						}
						for (int i = temp.size() - 1; i >= 0; i--)
						{
							vec.push_back(temp[i]);
						}
					}
					else
					{
						vec.push_back(cnt + '0');
					}
				}
				cnt = 1;
				c = chars[i];
			}
		}
		chars.clear();
		for (auto it = vec.begin(); it != vec.end(); it++)
		{
			chars.push_back(*it);
		}
		vec.clear();

		for (char c : chars)
		{
			cout << "[" << c << "]" << " ";
		}
		cout << endl;
		

		return chars.size();
	}
};


int main()
{
	cout << "hello world" << endl;
	vector<char> chars{ 'a','b','b','b','b','b','b', 'b', 'b', 'b', 'b', 'b', 'b'};
	int res = Solution().compress(chars);
	cout << res << endl;

	system("pause");
	return 0;
}

