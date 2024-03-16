#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
*/

/*
* 先遍历循环找0的位置，然后对每一个0进行处理
* 
* 所以.....就你还是中等？就这？
*/
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		vector<pair<int, int>> vec;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (matrix[i][j] == 0)
					vec.emplace_back(make_pair(i, j));
			}
		}
		for (auto pr : vec)
		{
			// 所在行
			for (int i = 0; i < matrix[0].size(); i++)
			{
				matrix[pr.first][i] = 0;
			}
			// 所在列
			for (int i = 0; i < matrix.size(); i++)
			{
				matrix[i][pr.second] = 0;
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

