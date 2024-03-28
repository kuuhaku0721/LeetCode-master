#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
* 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
*/

/*
* 原地变换，不会了，如果可以申请额外空间的话倒是会
* 行吧，还是答案好使，先把矩阵对角线换位，然后每一列都倒序一下
* 很好，结束一个
*/

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		// 对角线反转，就是行变列，列变行,需要注意的是只翻上三角的
		// 不然就会刚反转完，又给反回去了
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size() - i; j++)
			{
				int change = matrix[i][j];
				matrix[i][j] = matrix[matrix[0].size() - 1 - j][matrix.size() - 1 - i];  // 行大小减当前行标是列
				matrix[matrix[0].size() - 1 - j][matrix.size() - 1 - i] = change;
			}
		}
		// 然后逐列倒序
		for (int j = 0; j < matrix[0].size(); j++)
		{
			int up = 0, down = matrix.size() - 1;
			while (up <= down)
			{
				int temp = matrix[up][j];
				matrix[up][j] = matrix[down][j];
				matrix[down][j] = temp;

				++up;
				--down;
			}
		}
	}
};



int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

