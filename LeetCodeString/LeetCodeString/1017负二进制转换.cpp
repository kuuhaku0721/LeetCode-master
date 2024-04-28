#include <iostream>
#include <string>
using namespace std;

/*
* 给你一个整数 n ，以二进制字符串的形式返回该整数的 负二进制（base -2）表示。
* 注意，除非字符串就是 "0"，否则返回的字符串中不能含有前导零。
*/

/*
 数学方法，进制模拟
*/
class Solution {
public:
    string baseNeg2(int n) {
        string res = n == 0 ? "0" : "";
        int temp = 0;
        while (n != 0)
        {
            temp = n % (-2);
            n /= (-2);
            if (temp == -1)
            {
                n++;
                res.insert(0, "1");
            }
            else
            {
                res.insert(0, to_string(temp));
            }
        }
        return res;
    }
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

