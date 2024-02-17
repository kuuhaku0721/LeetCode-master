#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
* 给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的 频率 是它出现在字符串中的次数。
* 返回 已排序的字符串 。如果有多个答案，返回其中任何一个。
*/
//STL用完清空省时间

//比大小的谓词
class mySpare
{
public:
	bool operator()(pair<char, int> p1, pair<char, int> p2)
	{
		return p1.second > p2.second;
	}
};

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> ms;
		for (char c : s)
		{
			ms[c]++;
		}
		vector<pair<char, int>> vec(ms.begin(), ms.end());
		ms.clear();		//map用完了在这里清空
		sort(vec.begin(), vec.end(), mySpare());

		string res = "";
		for (auto it = vec.begin(); it != vec.end(); it++)
		{
			for (int i = 0; i < it->second; i++)
			{
				res += it->first;
			}
		}
		vec.clear();  //vector在这里清空
		return res;
	}
};

int main()
{
	cout << "hello world" << endl;
	string s = "Aabb";
	s = Solution().frequencySort(s);
	cout << s << endl;


	system("pause");
	return 0;
}

