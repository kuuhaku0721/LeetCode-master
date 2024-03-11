#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 样例输入
* 3
* 样例输出
* 4
* 2
* 4
*/


/*
* 遍历循环的时候，循环到谁将谁置0，除它以外的其他人++
* 先从左到右，到头之后从右到左
* 不管想法是啥，首先要解决的问题是：什么时候结束
* 首先很显然能知道的是，第一棵树何时最高？是第二轮修建到它之前
* 比如一共4棵，第一次将1置0，然后从第二次开始循环，下次再到它之前一共有两轮
* 也就是 2 3 4 3 2 1，一直到第6次才会再次轮到它，没轮到它的时候它都可以偷偷长大
* 那它的最大长度就是6，同样的对最后一个来说也是一样的，只不过最后一个是从第一轮结束开始，第三轮结束为止
* 这里要注意一下，轮到它的当天它也会长大1
* 列举一下前面几天就能找到规律了
* N = 3	  4 2 4
* N = 4	  6 4 4 6
* N = 5   8 6 4 6 8
* N = 6   10 8 6 6 8 10
* 
* 数学思维，如果能找到规律，通过不难
* 找不到，easy题也是困难
*/

void CutPlant()
{
	int N;
	cin >> N;
	// 0 1 2 单独输出
	if (N == 0) cout << "0" << endl;
	if (N == 1) cout << "0" << endl;
	if (N == 2) cout << "1\n1" << endl;

	if (N % 2 == 0)
	{
		vector<int> vec(N / 2);
		vec[N / 2 - 1] = N;
		for (int i = N/2 - 2; i >= 0; --i)
		{
			vec[i] = 2 + vec[i + 1];
		}
		for (auto i : vec)
			cout << i << endl;
		for (int i = vec.size() - 1; i >= 0; --i)
		{
			cout << vec[i] << endl;
		}
	}
	else
	{
		vector<int> vec(N / 2);
		vec[N / 2 - 1] = N + 1;
		for (int i = N/2 - 2; i >= 0; --i)
		{
			vec[i] = 2 + vec[i + 1];
		}
		for (auto i : vec)
			cout << i << endl;
		cout << N - 1 << endl;
		for (int i = vec.size() - 1; i >= 0; --i)
		{
			cout << vec[i] << endl;
		}
	}
}

int main()
{
	cout << "hello world" << endl;
	CutPlant();

	system("pause");
	return 0;
}

