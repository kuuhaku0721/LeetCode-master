#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
* 给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
*/

/*
* 看到题就会有一个想法，小于等于，那就直接拿它开始循环，往下减，每减1就比较一次是否符合递增
* 但是这么弄，多半超时，所以需要改进，但不管怎么说，先写出来再说
* 然后，现在就是需要缩小比较范围了
* 将这个数字每一位都保存下来，从头比较，让当前位都比下一位要小，是的话循环继续下一个
* 不是的话当前位 - 1，后面的全变9
* 
* 哟西！ 过了，而且时间100% perfect
*/

class Solution {
public:
	int monotoneIncreasingDigits(int n) {
		if (n < 10) return n;
		// 保存每一位数字
		vector<int> vec;
		while (n > 0)
		{
			vec.push_back(n % 10);
			n /= 10;
		}
		//reverse(vec.begin(), vec.end());
		// 从头开始保证递增（也可以倒着弄递减）
		for (int i = 0; i < vec.size() - 1;)
		{
			if (vec[i] < vec[i + 1])
			{
				for (int j = 0; j <= i; j++)
				{
					vec[j] = 9;
				}
				vec[i + 1] -= 1;
				continue;	// 不向前推进，继续从当前位置开始判断
			}
			++i;
		}
		// 最后再把数字拼回来
		reverse(vec.begin(), vec.end());
		int result = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			result += vec[i];
			if (i != vec.size() - 1) result *= 10;
		}
		return result;
	}
};



int main()
{
	cout << "hello world" << endl;
	//int n = 610112;
	int n = 332;
	int res = Solution().monotoneIncreasingDigits(n);
	cout << res << endl;

	system("pause");
	return 0;
}

