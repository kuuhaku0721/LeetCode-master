#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

/*
* 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
* n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
* 就是每两个皇后之间不能同行，同列，同斜列
* 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
* 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
*/

/*
* 困难题，做不出来大不了抄答案
* 所以嘛，别着急，先理一理思路
* 不能同行同列同斜，那从第一个皇后的第一个位置开始遍历二维数组，同样的还要准备一个true false数组
* 当皇后放进去一个位置之后把她所在的这一行这一列和斜列全部置位false，如果最后全部都是false并且皇后还没放完
* 那就没有答案，直接返回，如果全部都为false并且皇后数量也放够了，那就存储结果
* 我觉着，这个思路可以，应该可以写
* 最后还得去重。。。。。。
* 
* 还算不错的，写出来了，结果也是对的，直到6为止
* 从七开始，超时了...........烦诶......
* 好不容易写对了的说
* 
* 笑死，八皇后它跑了十分钟才跑出来结果....暴力破解，恐怖如斯
* 算法是这样，但是生产环境，我可以开线程啊2333333
*/

class Solution1 {
private:
	enum BOOL
	{
		TRUE = 1,
		FALSE = 0,
		OCCUPY = -1
	};
public:
	vector<vector<string>> result; 
	unordered_set<string> uset;
	vector<vector<string>> solveNQueens(int n) {
		if (n == 0) return result;
		if (n == 1) {
			vector<string> v(1, "Q");
			result.push_back(v);
			return result;
		}
		vector<vector<BOOL>> used(n, vector<BOOL>(n, TRUE));
		BackTracking(used, 0, n);
		// 把结果从set里挪出来到result里面
		for (string str : uset)
		{
			string s{};
			vector<string> vec;
			for (int i = 0; i < str.size(); i++)
			{
				if (str[i] == '|')
				{
					vec.push_back(s);
					s = "";
				}
				else
					s += str[i];
			}
			result.push_back(vec);
		}

		return result;
	}

	void BackTracking(vector<vector<BOOL>> used, int occupied, int n)
	{
		if (occupied == (n * n))
		{
			// Trace("!!!!!!!!当剩余为0的时候，此时的used现状：!!!!!!!!!!!", used);

			// 已经全部都用掉了，需要判断queen数量够不够
			int queen = 0;
			for (vector<BOOL> v : used)
			{
				for (BOOL b : v)
				{
					if (b == OCCUPY) queen++;
				}
			}
			if (queen == n)
			{
				// cout << "!@#$%@!#$!@#$@#$%  找到一个正确结果   !@#$%^&##$%" << endl;
				// queen的数量够，这个可以存起来了
				string s = "";
				for (vector<BOOL> v : used)
				{
					for (BOOL b : v)
					{
						if (b == OCCUPY)
							s += "Q";
						else
							s += ".";
					}
					s += "|";
				}
				uset.insert(s);
				return;
			}
			else
				return;
		}

		// 循环开始，主要思路是，找一个位置，放进去一个true，然后同一行，同一列，同斜列，只要为false全都置为true，同时统计数量
		// 然后继续下一轮循环

		// 这里的意思是，判断的时候用used，修改用flags，然后把flags当作参数传递出去，这样不影响继续回溯
		for (int i = 0; i < used.size(); i++)
		{
			for (int j = 0; j < used[i].size(); j++)
			{
				if (used[i][j] == TRUE)
				{
					auto flags = used;
					int cnt = occupied;
					// 找到一个空位，占用，然后处理其他位置的
					flags[i][j] = OCCUPY;
					cnt++;
					// 同一行
					for (int k = 0; k < n; k++)
					{
						if (flags[i][k] == TRUE)
						{
							flags[i][k] = FALSE;
							cnt++;
						}
					}
					// 同一列
					for (int k = 0; k < n; k++)
					{
						if (flags[k][j] == TRUE)
						{
							flags[k][j] = FALSE;
							cnt++;
						}
					}
					// 同一斜
						// 右斜
					int row = i, col = j;
					while (row >= 0 && col >= 0)
					{
						if (flags[row][col] == TRUE)
						{
							flags[row][col] = FALSE;
							cnt++;
						}
						row--;
						col--;
					}
					row = i, col = j;
					while (row < n && col < n)
					{
						if (flags[row][col] == TRUE)
						{
							flags[row][col] = FALSE;
							cnt++;
						}
						row++;
						col++;
					}
						// 左斜
					row = i, col = j;
					while (row >= 0 && col < n)
					{
						if (flags[row][col] == TRUE)
						{
							flags[row][col] = FALSE;
							cnt++;
						}
						row--;
						col++;
					}
					row = i, col = j;
					while (row < n && col >= 0)
					{
						if (flags[row][col] == TRUE)
						{
							flags[row][col] = FALSE;
							cnt++;
						}
						row++;
						col--;
					}

					string msg = "当前位置：" + to_string(i) + "--" + to_string(j) + " 处理完毕之后的棋盘现状";
					Trace(msg, flags);

					// 全部处理完之后，下一轮循环
					// cout << "!!!!!!!!!!!此时的cnt = " << cnt << endl;
					BackTracking(flags, cnt, n);
				}
			}
		}
	}

	void Trace(string msg, vector<vector<BOOL>> used)
	{
		cout << "-----" << msg << "-----" << endl;
		for (int i = 0; i < used.size(); i++)
		{
			for (int j = 0; j < used[i].size(); j++)
			{
				if (used[i][j] == FALSE)
					cout << ".";
				else if (used[i][j] == TRUE)
					cout << "#";
				else if (used[i][j] == OCCUPY)
					cout << "Q";
			}
			cout << endl;
		}
		cout << "----------------------------------------\n" << endl;
	}
};

/*
* 这是答案，其实思路是差不多的
* 区别在于，答案有一点是我的写法里没有实现的：如果这一行已经放进去一个并且验证可行的情况下，剩下的就不用看了，直接下一行
*/
class Solution {
private:
	vector<vector<string>> result;
	// n 为输入的棋盘大小
	// row 是当前递归到棋盘的第几行了
	void backtracking(int n, int row, vector<string>& chessboard) {
		if (row == n) {
			result.push_back(chessboard);
			return;
		}
		for (int col = 0; col < n; col++) {
			if (isValid(row, col, chessboard, n)) { // 验证合法就可以放
				chessboard[row][col] = 'Q'; // 放置皇后
				backtracking(n, row + 1, chessboard);
				chessboard[row][col] = '.'; // 回溯，撤销皇后
			}
		}
	}
	bool isValid(int row, int col, vector<string>& chessboard, int n) {
		// 检查列
		for (int i = 0; i < row; i++) { // 这是一个剪枝
			if (chessboard[i][col] == 'Q') {
				return false;
			}
		}
		// 检查 45度角是否有皇后
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
			if (chessboard[i][j] == 'Q') {
				return false;
			}
		}
		// 检查 135度角是否有皇后
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
			if (chessboard[i][j] == 'Q') {
				return false;
			}
		}
		return true;
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		result.clear();
		std::vector<std::string> chessboard(n, std::string(n, '.'));
		backtracking(n, 0, chessboard);
		return result;
	}
};

int main()
{
	cout << "hello world" << endl;
	int n = 8;
	auto result = Solution().solveNQueens(n);
	for (vector<string> vec : result)
	{
		for (string s : vec)
		{
			cout << s << " | ";
		}
		cout << "\n----------------------------" << endl;
	}

	system("pause");
	return 0;
}

