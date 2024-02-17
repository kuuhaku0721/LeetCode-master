#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件：
实部 是一个整数，取值范围是 [-100, 100]
虚部 也是一个整数，取值范围是 [-100, 100]
i2 == -1
给你两个字符串表示的复数 num1 和 num2 ，请你遵循复数表示形式，返回表示它们乘积的字符串。
*/

/*
* 复数的实部和虚部之间一定是+，有负数会用1+-1i表示
* 因此，可以直接拆出来四部分，实部单独运算，虚部*虚部单独运算，剩下的正常加减
* 拆出来之后，第一部分和第四部分，一定是减的关系
* 第二部分和第三部分去掉i单独运算，结果加个i就行
* 所以难点在于，如何正确保存下来四个数字
*/

class Solution {
public:
	string complexNumberMultiply(string num1, string num2) {
		vector<int> vec;
		strToInt(num1, vec);
		strToInt(num2, vec);
		string res;
		res = to_string(vec[0] * vec[2] - vec[1] * vec[3]);
		res += "+";
		res += to_string(vec[0] * vec[3] + vec[1] * vec[2]);
		res += "i";
		return res;
	}

	void strToInt(string& num, vector<int>& vec)
	{
		int index = num.find('+');
		string t = num.substr(0, index);
		vec.push_back(atoi(t.c_str()));
		int index2 = num.find('i');
		t = num.substr(index + 1, index2 - index - 1);
		vec.push_back(atoi(t.c_str()));
	}
};


int main()
{
	cout << "hello world" << endl;
	string num1 = "1+-1i";
	string num2 = "1+-1i";
	string res = Solution().complexNumberMultiply(num1, num2);
	cout << res << endl;

	system("pause");
	return 0;
}

