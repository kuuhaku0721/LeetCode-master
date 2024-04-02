#include <iostream>
#include <string>
using namespace std;

/*
* 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
* 完全平方数 是一个整数，其值等于另一个整数的平方；
* 换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
*/

/*
* 这题虽然是dp分组，但是如果用dp写，应该是麻烦了
* 不如数学算法
* 大佬的思路: 
*	任何正整数都可以拆分成不超过4个数的平方和 ---> 答案只可能是1,2,3,4
	如果一个数最少可以拆成4个数的平方和，则这个数还满足 n = (4^a)*(8b+7) ---> 因此可以先看这个数是否满足上述公式，如果不满足，答案就是1,2,3了
	如果这个数本来就是某个数的平方，那么答案就是1，否则答案就只剩2,3了
	如果答案是2，即n=a^2+b^2，那么我们可以枚举a，来验证，如果验证通过则答案是2	
	只能是3
*/

class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;  //判4
        if (n % 8 == 7) return 4;

        for (int i = 0; i * i <= n; ++i) {  //判1
            if (n - i * i == 0) return 1;
        }

        for (int i = 0; i * i < n; ++i) {   //判2
            for (int j = 0; j * j < n; ++j) {
                if (n - i * i - j * j == 0) return 2;
            }
        }
        return 3;   //4、1、2，都不是，直接返回3
    }
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

