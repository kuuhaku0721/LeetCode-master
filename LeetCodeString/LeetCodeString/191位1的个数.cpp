#include <iostream>
#include <string>
#include <bitset>
#include <Windows.h>
using namespace std;

/*
* 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
*/

/*
* 一看看过去就已经有三种方法了，有不等于会
* 直接转字符串数1的个数，只有32位，长度不会很长，很快
* 直接用bitset<32>(n)然后调用count数数量就完事了
* 位运算，这个就不好弄了
*/

class Solution {
public:
	// bitset开挂版
	int hammingWeight(uint32_t n) {
		return bitset<32>(n).count();
	}
	// 位运算版
	int hammingWeight_wei(uint32_t n) {
		int res = 0;
		while (n != 0)
		{
			res += n & 1;	// 1就是前面31个0，最后一个1
			n >>= 1;	// 然后右移一位
		}
		return res;
	}
	// 字符串版
	int hammingWeight_str(uint32_t n) {
		string str = to_string(n);
		int res = 0;
		for (char c : str)
			if (c == '1') res++;
		return res;
	}
};

int main()
{
	cout << "hello world" << endl;
	uint32_t n = 2147483647;
	DWORD start = GetTickCount64();
	cout << Solution().hammingWeight(n) << endl;
	DWORD end = GetTickCount64();
	cout << "第一个: " << end - start << endl;
	
	start = GetTickCount64();
	cout << Solution().hammingWeight_str(n) << endl;
	end = GetTickCount64();
	cout << "第二个: " << end - start << endl;

	start = GetTickCount64();
	cout << Solution().hammingWeight_wei(n) << endl;
	end = GetTickCount64();
	cout << "第三个: " << end - start << endl;

	system("pause");
	return 0;
}

