#include <iostream>
#include <string>
using namespace std;

/*
* 计算节点1到节点2021之间最短路径是多少
* 题目要求距离超过21(>21)就没有边相连了，那问题可以尝试转换为没21个为一组，求它们之间的最短长度
* 
* 这个写法不对，之后回过头来再次看这个的时候再更正吧
* 正确写法应该是动态规划，很标准的一个动规题
* 
*/

typedef long long LL;


int Zuixiaogongbeishu(int a, int b)
{
	for (int i = b; i <= a * b; ++i)
	{
		if (i % a == 0 && i % b == 0)
			return i;
	}
	return a * b;
}

void minRoute()
{
	LL res{};
	for (int i = 1; i <= 2021; i += 21)
	{
		if (i + 21 >= 2021)
			res += Zuixiaogongbeishu(i, 2021);
		else
			res += Zuixiaogongbeishu(i, i + 21);
	}
	cout << res << endl;
}



int main()
{
	cout << "hello world" << endl;
	minRoute();

	system("pause");
	return 0;
}

