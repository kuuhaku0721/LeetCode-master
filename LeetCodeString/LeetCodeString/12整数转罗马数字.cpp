#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

/*
* 罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
字符          数值
I             1
IV			  4
V             5
IX		      9

X             10
XL			  40
L             50
XC			  90

C             100
CD			  400
D             500
CM			  900

M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，
所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给你一个整数，将其转为罗马数字。
*/
/*
* 问题：先判断等于，还是先判断大于
* 1994
* 1000 900 90 4
* 1 <= num <= 3999
*/


class Solution {
public:
	string intToRoman(int num) {
		vector<int> vec;
		while (num > 0)
		{
			vec.push_back(num % 10);
			num /= 10;
		}

		string res = "";
		for (int i = 0; i < vec.size(); i++)
		{
			if (i == 0) //个位
			{
				res.insert(0, numClassification(vec[i], 0));
			}
			else if (i == 1) //十位
			{
				res.insert(0, numClassification(vec[i], 1));
			}
			else if (i == 2) //百位
			{
				res.insert(0, numClassification(vec[i], 2));
			}
			else if (i == 3) //千位
			{
				for (int j = 0; j < vec[i]; j++)
				{
					res.insert(0, "M");
				}
			}
		}

		return res;
	}

	string numClassification(int& num, int status) //0：个位 1十位 2：百位
	{
		string res = "";
		while (num > 0)
		{
			if (num == 9)
			{
				if (status == 0)
					res += "IX";
				else if (status == 1)
					res += "XC";
				else if (status == 2)
					res += "CM";
				break;
			}
			else if (num < 9 && num > 5)
			{
				if (status == 0)
					res += "V";
				else if (status == 1)
					res += "L";
				else if (status == 2)
					res += "D";
				num -= 5;
			}
			else if (num == 5)
			{
				if (status == 0)
					res += "V";
				else if (status == 1)
					res += "L";
				else if (status == 2)
					res += "D";
				break;
			}
			else if (num == 4)
			{
				if (status == 0)
					res += "IV";
				else if (status == 1)
					res += "XL";
				else if (status == 2)
					res += "CD";
				break;
			}
			else if (num < 4)
			{
				for (int i = 0; i < num; i++)
				{
					if (status == 0)
						res += "I";
					else if (status == 1)
						res += "X";
					else if (status == 2)
						res += "C";
				}
				break;
			}
		}
		return res;
	}
};

int main()
{
	cout << "hello world" << endl;
	int num = 1994;
	string res = Solution().intToRoman(num);
	cout << res << endl;

	system("pause");
	return 0;
}

