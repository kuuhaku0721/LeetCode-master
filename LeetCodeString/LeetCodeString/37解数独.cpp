#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。
*/

/*
* 上一题被8皇后难到了，但是思路还是可以用的
* N皇后里面每一行只用放一个，所以自己的写法超时，但是数独每一格都要放数字，所以每一行的每一列都要递归
* 那就又回到之前的写法了
* 试试，不行就CV
* 如果Solution变成了Solution1，那就是CV了
*/
// 我是SB，我还是乖乖研究答案去吧
// 答案是真nb啊...简单易懂还好抄，直接把Hard题变Easy题
class Solution1 {
public:
	void solveSudoku(vector<vector<char>>& board) {
        BackTracking(board);
	}

    bool BackTracking(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                // 先确定这一格是空的
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(i, j, c, board))
                        {   // 判断当前位置放c是否合适，合适放进去，否则回退，换下一个(回溯)
                            board[i][j] = c;
                            if (BackTracking(board)) return true;   // 返回bool是因为如果找到一组正确解，那就立刻返回
                            board[i][j] = '.'; // 回退
                        }
                    }
                    return false; // 九个数字都试过了还不行，说明前面有数填的不对，返回false不再继续往下进行
                }
            }
        }
        return true;
    }

    bool isValid(int row, int col, char c, vector<vector<char>>& board)
    {
        // 判断同一行是否有重复
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][col] == c)
                return false;
        }
        // 判断同一列是否有重复
        for (int i = 0; i < board.size(); i++)
        {
            if (board[row][i] == c)
                return false;
        }
        // 判断自身所在的九宫格内是否有重复
        int w = (row / 3) * 3;
        int h = (col / 3) * 3;
        for (int i = w; i < w+3; i++)
        {
            for (int j = h; j < h+3; j++)
            {
                if (board[i][j] == c)
                    return false;
            }
        }
        // 全部判断完毕，返回true
        return true;
    }
};

class Solution {
private:
    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {        // 遍历行
            for (int j = 0; j < board[0].size(); j++) { // 遍历列
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {     // (i, j) 这个位置放k是否合适
                        if (isValid(i, j, k, board)) {
                            board[i][j] = k;                // 放置k
                            if (backtracking(board)) return true; // 如果找到合适一组立刻返回
                            board[i][j] = '.';              // 回溯，撤销k
                        }
                    }
                    return false;  // 9个数都试完了，都不行，那么就返回false 
                }
            }
        }
        return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
    }
    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) { // 判断行里是否重复
            if (board[row][i] == val) {
                return false;
            }
        }
        for (int j = 0; j < 9; j++) { // 判断列里是否重复
            if (board[j][col] == val) {
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

