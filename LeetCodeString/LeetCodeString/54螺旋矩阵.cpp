#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*/

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int up = matrix.size() - 1, down = 0, left = matrix[0].size() - 1, right = 0;
		int total = matrix.size() * matrix[0].size();
		vector<int> res;
		while (res.size() < total)
		{
			// 向右
			int i = right;
			while (i <= left)
			{
				res.push_back(matrix[down][i]);
				++i;
			}
			++down;

			// 向下
			i = down;
			while (i <= up)
			{
				res.push_back(matrix[i][left]);
				++i;
			}
			--left;

			// 向左
			i = left;
			while (i >= right)
			{
				res.push_back(matrix[up][i]);
				--i;
			}
			--up;

			// 向上
			i = up;
			while (i >= down)
			{
				res.push_back(matrix[i][right]);
				--i;
			}
			++right;
		}
		return res;
	}

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
	auto vec = Solution().spiralOrder(matrix);
	for (int i : vec)
		cout << i << " ";
	cout << endl;

	system("pause");
	return 0;
}

