#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。
*/

/*
* 遇到的问题：
* 1、不能在函数里传递vector，不然每一组用的都是同一个vector，出不来结果
* 2、保存完一维vector之后不能直接clear，这样中间几轮保存的结果也就丢了
* 3、不能是保存完一维vector之后在去尾，这样会出现数量错误，保存完之后去尾，那从第二棵子树开始，不管加进去的是谁前面数量一定是够的，上一棵树的没摘干净
* 总结：
* 回溯法也很费时间，因为归根到底回溯也是穷举，也就是暴力，所以很慢
* 但是套路几乎是一样的，只要决定好参数就行
*/

class Solution {
public:
	vector<vector<int>> result;
	vector<int> vec;
	vector<vector<int>> combine(int n, int k) {
		BackTracking(0, n, k);
		return result;
	}

	void BackTracking(int cur, int n, int k)
	{
		if (vec.size() == k)
		{
			result.push_back(vec);
			return;
		}
		for (int i = cur + 1; i <= n; i++)
		{
			vec.push_back(i);
			BackTracking(i, n, k);
			vec.pop_back(); 
		}
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

