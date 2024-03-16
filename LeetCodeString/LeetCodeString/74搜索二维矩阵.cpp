#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个满足下述两条属性的 m x n 整数矩阵：
* 每行中的整数从左到右按非严格递增顺序排列。
* 每行的第一个整数大于前一行的最后一个整数。
* 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
*/

/*
* 先找到这个数可能出现在哪一行
* 然后对这一行二分查找就行了
* 所以其实就是一个二分？先试试
* 所以，不用二分反倒比二分还快？啊？
*/

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int i;
		for ( i = 0; i < matrix.size(); i++)
		{
			if (target >= matrix[i][0] && target <= matrix[i][matrix[0].size() - 1])
				break;
		}
		if (i == matrix.size()) return false;
		int left = 0, right = matrix[i].size() - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (matrix[i][mid] > target)
				right = --mid;
			else if (matrix[i][mid] < target)
				left = ++mid;
			else
				return true;
		}
		return false;
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

