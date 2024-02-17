#include <iostream>
#include <string>
using namespace std;

/*
* 编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
*/


/*
* 输入是个整数 也就是只有10位数，就算每一位都是9 撑死只循环81*10 = 810次 所以循环810次就够了
*/

class Solution {
public:
	bool isHappy(int n) {
		int i = 810;
		while (i > 0)
		{
			long sum = 0;
			while (n > 0)
			{
				sum += pow((n % 10), 2);
				n /= 10;
			}

			if (sum == 1)
				return true;

			cout << sum << endl;
			n = sum;
			sum = 0;
			i--;
		}

		return false;
	}
};


int main()
{
	cout << "hello world" << endl;

	bool res = Solution().isHappy(2);
	if (res)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}

