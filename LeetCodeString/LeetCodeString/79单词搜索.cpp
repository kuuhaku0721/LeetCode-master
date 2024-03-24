#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
* 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
*/

/*
* 笑死，难得一见的问题
* backTracking的函数，最后一个参数，如果用引用&，会出错，因为上下左右如果用的同一个数组会影响到其他位置的判断
* 但是如果不用引用，会出现：超出内存限制...233333
* 放弃，cv吧
*/
class Solution {
public:
	string word;
	bool exist(vector<vector<char>>& board, string word) {
		this->word = word;
		bool flag = false;
		vector<vector<char>> backup;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] == word[0])
				{
					backup = board;
					flag |= backTracking(0, i, j, backup);
				}
			}
		}
		return flag;
	}

	bool backTracking(int pos, int row, int col, vector<vector<char>> board)
	{
		if (pos == word.size() - 1)
		{
			if (word[pos] == board[row][col])
				return true;
			else
				return false;
		}

		bool flag_up = false, flag_down = false, flag_left = false, flag_right = false;
		if (board[row][col] == word[pos])
		{
			board[row][col] = '0';	// 用完之后置空 不然会被重复利用出错
			if (row - 1 >= 0)
			{
				flag_up = backTracking(pos + 1, row - 1, col, board);
			}
			if (row + 1 < board.size())
			{
				flag_down = backTracking(pos + 1, row + 1, col, board);
			}
			if (col - 1 >= 0)
			{
				flag_left = backTracking(pos + 1, row, col - 1, board);
			}
			if (col + 1 < board[row].size())
			{
				flag_right = backTracking(pos + 1, row, col + 1, board);
			}
		}

		return flag_up || flag_down || flag_left || flag_right;
	}
};


int main()
{
	cout << "hello world" << endl;
	vector<vector<char>> board {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'E', 'S'},
		{'A', 'D', 'E', 'E'}
	};
	string word = "ABCESEEEFS";
	cout << Solution().exist(board, word) << endl;

	system("pause");
	return 0;
}

