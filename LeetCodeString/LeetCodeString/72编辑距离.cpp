#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

/*
* 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
* 
* 你可以对一个单词进行如下三种操作：
* 
* 插入一个字符
* 删除一个字符
* 替换一个字符
*/

/*
* 把word1转换成word2，并没有说谁比谁长，所以有可能2比1长，需要一直增加字母
* 先分开讨论吧，如果1比2长一个处理，1比2短一个处理，万一做出来了再往一块缩
* 
* 很好，完全 不明白
*/

class Solution1 {
public:
	int minDistance(string word1, string word2) {
		if (word1.size() >= word2.size())
		{	// 1的长度比2长，去掉已经相同的，仅保留不同的
			unordered_multiset<char> umulset(word2.begin(), word2.end());
			unordered_multiset<char> umulsetOper;
			// 我想要实现的是，如果word2的字符在word1里面已经有了，那就不管这个了
			// 如果没有，那就判断它
			// 不对劲...很不对劲...
			// 这tm是中等？
			for (char c : word1)
			{
				if (umulset.find(c) == umulset.end())
				{
					umulsetOper.insert(c);
				}
			}
		}
		else
		{

		}
	}
};

// 答案
class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		
		for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
		for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
		
		for (int i = 1; i <= word1.size(); i++) 
		{
			for (int j = 1; j <= word2.size(); j++) 
			{
				if (word1[i - 1] == word2[j - 1]) 
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else 
				{
					dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
				}
			}
		}
		return dp[word1.size()][word2.size()];
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

