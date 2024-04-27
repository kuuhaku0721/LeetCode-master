#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个下标从 0 开始的 m x n 整数矩阵 grid 。矩阵中某一列的宽度是这一列数字的最大 字符串长度 。
* 比方说，如果 grid = [[-10], [3], [12]] ，那么唯一一列的宽度是 3 ，因为 -10 的字符串长度为 3 。
* 请你返回一个大小为 n 的整数数组 ans ，其中 ans[i] 是第 i 列的宽度。
* 一个有 len 个数位的整数 x ，如果是非负数，那么 字符串长度 为 len ，否则为 len + 1 。
*/

class Solution {
public:
	vector<int> findColumnWidth(vector<vector<int>>& grid) {
		vector<int> res;
		for (int j = 0; j < grid[0].size(); j++)
		{
			int maxlen = 0;
			for (int i = 0; i < grid.size(); i++)
			{
				maxlen = max(maxlen, (int)to_string(grid[i][j]).size());
			}
			res.push_back(maxlen);
		}
		return res;
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

