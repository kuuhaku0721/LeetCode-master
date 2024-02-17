#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

/*
* 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
*/

/*
* 其实写法和上一题，也就是77的组合差不多
* 只是在77的基础上增加一个总和判断而已
* 
* 莫名其妙欸
* 明明方法都是一样的，但就是时间要慢的多
*/
class Solution {
public:
	vector<vector<int>> result;
	vector<int> vec;
	vector<vector<int>> combinationSum3(int k, int n) {
		
		BackTracking(0, k, n);
		return result;
	}

	void BackTracking(int cur, int k, int n)
	{
		if (vec.size() == k)
		{
			// 求总和
			int s = accumulate(vec.begin(), vec.end(), 0);
			if (s == n)
				result.push_back(vec);
			return;
		}

		for (int i = cur + 1; i <= 9; i++)
		{
			vec.push_back(i);
			BackTracking(i, k, n);
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

