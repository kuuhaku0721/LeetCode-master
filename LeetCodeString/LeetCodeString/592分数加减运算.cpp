#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个表示分数加减运算的字符串 expression ，你需要返回一个字符串形式的计算结果。 
这个结果应该是不可约分的分数，即最简分数。 如果最终结果是一个整数，例如 2，你需要将它转换成分数形式，其分母为 1。所以在上述例子中, 2 应该被转换为 2/1。
*/


/*
* 以/为分界线，两个数组，一个存分子，一个存分母
* 分子分母分开运算
* 但是考虑到通分，两个数组要用同一个索引
* 先分母，要找它们的最小公倍数,这个或许得单独列一个函数出来
* 还有符号....
* 那就全换成加法
*/

class Solution {
public:
	string fractionAddition(string expression) {
		vector<int> muziko;
		vector<int> haha;
		while (expression.find('/') != -1)
		{
			int index = expression.find('/');
			string t = expression.substr(0, index); //分子
			muziko.push_back(atoi(t.c_str()));
			//cout << "分子进去了：" << t << endl;
			t = "";
			index++;
			while (expression[index] != '+' && expression[index] != '-' && index < expression.size())
			{
				t += expression[index];
				index++;
			}
			haha.push_back(atoi(t.c_str()));
			//cout << "分母进去了：" << t << endl;
			expression = expression.substr(index, expression.size() - index);
			//cout << "截掉一个之后的expression：" << expression << endl;
		}

		cout << "分子: ";
		for (int i : muziko)
			cout << i << " ";
		cout << endl << "分母: ";
		for (int i : haha)
			cout << i << " ";
		cout << endl;


		int lcm = 1;
		int mx = 1;
		for (int num : haha)
		{
			lcm = max(lcm, num);
			mx *= num;
		}
		for (int i = lcm; i <= mx; i++)
		{
			int j;
			for (j = 0; j < haha.size(); j++)
			{
				if (i % haha[j] != 0)
					break;
			}
			if (j == haha.size())
			{
				lcm = i;
				break;
			}
		}
		cout << "最小公倍数：" << lcm << endl;

		int res = 0;
		for (int i = 0; i < muziko.size(); i++)
		{
			if (muziko[i] == 0)
				res += 0;
			else
			{
				res += muziko[i] * (lcm / haha[i]);
			}
		}
		cout << "结果分子: " << res << endl;
		cout << "结果分母: " << lcm << endl;
		//找最大公约数
		int gcd = 1;
		int M = max(res, lcm);
		for (int i = M; i >= 1; i--)
		{
			if (res % i == 0 && lcm % i == 0)
			{
				gcd = i;
				break;
			}
		}
		cout << "最大公约数: " << gcd << endl;
		string result = "";
		if (res == 0)
			return "0/1";
		result += to_string(res / gcd);
		result += "/";
		result += to_string(lcm / gcd);

		return result;
	}
};



int main()
{
	cout << "hello world" << endl;
	//string expression = "4/7-2/1-4/1-9/7-1/3+2/5-9/2+3/2-5/9-1/2";
	string expression = "1/3-1/2";
	string res = Solution().fractionAddition(expression);
	cout << res << endl;

	system("pause");
	return 0;
}

