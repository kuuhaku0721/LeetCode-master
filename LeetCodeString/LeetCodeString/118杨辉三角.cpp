#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/
/*
* 哟西，直接100%
* 简单题我重拳出击
*/

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		vector<int> beg;
		beg.push_back(1);
		res.push_back(beg);
		if (numRows == 1) return res;

		for (int i = 0; i < numRows - 1; i++)
		{
			vector<int> t; //[i -1] + [i]
			for (int j = 0; j <= res[i].size(); j++)
			{
				int num = 0;
				if (j - 1 >= 0)
				{
					num += res[i][j - 1];
				}
				if(j < res[i].size())
					num += res[i][j];
				t.push_back(num);
			}
			res.push_back(t);
		}
		return res;
	}
};


int main()
{
	cout << "hello world" << endl;
	int numRows = 5;
	vector<vector<int>> rectangle = Solution().generate(numRows);
	for (vector<int> v : rectangle)
	{
		for (int i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

