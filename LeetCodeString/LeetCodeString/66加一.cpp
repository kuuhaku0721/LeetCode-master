#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
*/	

/*
* 呵 简单题
* 轻松拿捏
* 直接100%
*/

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		reverse(digits.begin(), digits.end());
		digits[0]++;
		for (int i = 0; i < digits.size() - 1; i++)
		{
			if (digits[i] >= 10)
			{
				digits[i] -= 10;
				digits[i + 1] += 1;
			}
		}
		if (digits[digits.size() - 1] >= 10)
		{
			digits[digits.size() - 1] -= 10;
			digits.push_back(1);
		}
		reverse(digits.begin(), digits.end());
		return digits;
	}
};



int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

