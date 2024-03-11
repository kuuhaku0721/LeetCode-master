#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个 N×M的矩阵 A，请你统计有多少个子矩阵 (最小 1×1，最大 N×M) 
* 满足子矩阵中所有数的和不超过给定的整数 K?
* 
* 玛德犯ptsd了，美团笔试第一轮第三题就是这个，还是做半天做不出来那个
*/

// 还有一点就是 直接用数组要比用vector更快
// 如果没有可变长的需求的话，还是尽量用数组吧

int matrix[510][510];

void SubMatrix()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> matrix[i][j];
			matrix[i][j] += matrix[i - 1][j];
		}
	}
	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			for (int l = 1, r= 1, sum = 0; r <= m; r++)
			{
				sum += matrix[j][r] - matrix[i - 1][r];
				while (sum > k)
				{
					sum -= matrix[j][l] - matrix[i - 1][l];
					l++;
				}
				res += r - l + 1;
			}
		}
	}
	cout << res << endl;
}

// 输出一个二维矩阵的所有子矩阵
void PrintSubMatrices() {
	
	int N, m, k;
	cin >> N >> m >> k;
	vector<vector<int>> matrix(N, vector<int>(m));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
		}
	}

	int n = matrix.size();

	// 遍历所有子矩阵的起始行和列
	for (int startRow = 0; startRow < n; startRow++) 
	{
		for (int startCol = 0; startCol < n; startCol++) 
		{
			// 遍历当前子矩阵的行数和列数
			for (int rows = 1; startRow + rows <= n; rows++) 
			{
				for (int cols = 1; startCol + cols <= n; cols++) 
				{
					// 输出当前子矩阵
					for (int i = startRow; i < startRow + rows; i++) 
					{
						for (int j = startCol; j < startCol + cols; j++) 
						{
							cout << matrix[i][j] << " ";
						}
						cout << endl;
					}
					cout << endl;
				}
			}
		}
	}
}


int main()
{
	// SubMatrix();
	PrintSubMatrices();

	system("pause");
	return 0;
}

