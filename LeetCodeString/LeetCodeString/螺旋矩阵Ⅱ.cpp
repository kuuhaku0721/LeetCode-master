#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		int cur = 1;
		// 上下左右四个方向移动的起始位置，终止位置用0判断
		// 重点是判断四个门限值，然后退出条件是cur==n方，然后就是细心的问题了
		int up = n - 1, down = 0, left = n - 1, right = 0;
		while (cur <= n * n)
		{
			// 向右
			int i = right;
			while (i <= left && matrix[down][i] == 0)
			{
				matrix[down][i] = cur;
				++cur;
				++i;
			}
			++down;

			// 向下
			i = down;
			while (i <= up && matrix[i][left] == 0)
			{
				matrix[i][left] = cur;
				++cur;
				++i;
			}
			--left;

			// 向左
			i = left;
			while (i >= right && matrix[up][i] == 0)
			{
				matrix[up][i] = cur;
				++cur;
				--i;
			}
			--up;

			// 向上
			i = up;
			while (i >= down && matrix[i][right] == 0)
			{
				matrix[i][right] = cur;
				++cur;
				--i;
			}
			++right;

			// 一圈过后，循环继续，然后再次重复
		}
		return matrix;
	}
};

int main()
{
	cout << "hello world" << endl;
	auto matrix = Solution().generateMatrix(4);
	for (auto vec : matrix)
	{
		for (auto i : vec)
			cout << i << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}

