#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
* 
* 直接复制的答案，我有罪，
* 
* 日后谈：二刷了，我会了，很棒
*		 值得纪念，你是第一个答案变成Solution1的题
*/

class Solution1 {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int count = 1; // 用来给矩阵中每一个空格赋值
        int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
        int i, j;
        while (loop--) {
            i = startx;
            j = starty;

            // 下面开始的四个for就是模拟转了一圈
            // 模拟填充上行从左到右(左闭右开)
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // offset 控制每一圈里每一条边遍历的长度
            offset += 1;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};
class Solution {
public:
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

	system("pause");
	return 0;
}

