#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
* 每行的元素从左到右升序排列。
* 每列的元素从上到下升序排列。
*/

/*
* 这个我会，两次二分就行了,但是，好像也没有那么容易..
* 那就多来几次二分，遍历每一行的第一个，只要满足条件，二分这一行
* 这一列能不能二分...似乎不太能，每一个都满足的话，没法保证它会出现在哪一行
* 
* 笑死，从最后一排开始往前找要比从前往后效率高....虽然写法都一样
*/

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[i][0] <= target && matrix[i][matrix[0].size() - 1] >= target)
			{	// 比开头大，比结尾下，说明可能出现在这一行，二分这一行，找到就return，没有就继续下一行
				int left = 0, right = matrix[i].size() - 1;
				while (left <= right)
				{
					int mid = left + (right - left) / 2;
					if (matrix[i][mid] < target)
					{
						left = mid + 1;
					}
					else if (matrix[i][mid] > target)
					{
						right = mid - 1;
					}
					else
						return true;
				}
			}
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

