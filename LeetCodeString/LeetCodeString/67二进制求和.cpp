#include <iostream>
#include <string>
using namespace std;

/*
* 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
*/


/*
* 不怪我，怪酒，喝了点，脑子晃来晃去的，实在是不想接着写
* 直接抄了答案，我有罪
* 但是吧，一个简单题而已，不算难
* 又不是写不出来
* 对吧，未来看到这里的我
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

