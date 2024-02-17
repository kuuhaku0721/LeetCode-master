#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
* 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
* 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

/*
* 思考切入点1、数字到字母的映射，首先想到的就是map
* 但是因为数字很少，只有2-9，所以其实用不着map，一个数组就足够了
* 
* 好啊，回溯法真好用啊....这不万能解吗这不是...
* 突然就意识到了，pop_back是去掉最后一个，不是开头那个
* 所以其实是现决定最前面的，然后从最后一组开始循环
* 然后再往前倒数第二个
* 最后才换掉第一个
*/

class Solution {
public:
	const string letterMap[10] = {
		"",	// 0
		"", // 1
		"abc",	// 2
		"def",	// 3
		"ghi",	// 4
		"jkl",	// 5
		"mno",	// 6
		"pqrs", // 7
		"tuv",	// 8
		"wxyz"  // 9
	};
	vector<string> result;
	string s = "";
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return result;
		BackTracking(digits, -1);
		for (string s : result)
		{
			cout << s << endl;
		}
		return result;
	}

	void BackTracking(string digits, int idx)
	{
		if (s.size() == digits.size())
		{
			result.push_back(s);
			return;
		}

		for (int i = idx + 1; i < digits.size(); i++)
		{
			int curNum = digits[i] - '0';
			for (int j = 0; j < letterMap[curNum].size(); j++)
			{
				s += letterMap[curNum][j];
				BackTracking(digits, i);
				s.pop_back();
			}
		}
	}
};

int main()
{
	string s = "2345";
	Solution().letterCombinations(s);

	system("pause");
	return 0;
}

