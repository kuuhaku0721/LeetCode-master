#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
* 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，
* 下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
* 
* 示例 1:
* 
* 输入: temperatures = [73,74,75,71,69,72,76,73]
* 输出: [1,1,4,2,1,1,0,0]
* 
* 这个...就....不就一遍历？
* 难不成就这还二分？后边没排序怎么二分啊
* 我就知道....直接遍历就超时
* 官方解法是单调栈，但是看不懂，啧啧啧
* 哦，它原本就在栈的分类里面啊...
*/

class Solution {
public:
	vector<int> dailyTemperatures1(vector<int>& temperatures) {
		vector<int> answer(temperatures.size(), 0);
		for (int i = 0; i < temperatures.size(); i++)
		{
			int j = i + 1;
			while (j < temperatures.size() && temperatures[j] <= temperatures[i])
				j++;
			if (j != temperatures.size()) answer[i] = j - i;
		}
		return answer;
	}
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int n = temperatures.size();
		vector<int> ans(n);
		stack<int> s;
		for (int i = 0; i < n; ++i) 
		{	// 栈非空是必要考虑条件，栈存的下标	如果当天比栈顶指的值要大，那就换栈顶
			while (!s.empty() && temperatures[i] > temperatures[s.top()]) 
			{	// 单调栈的思路是先往后遍历，然后往前找走过的路里面比自己小的
				int previousIndex = s.top();
				ans[previousIndex] = i - previousIndex;
				s.pop();
			}
			s.push(i);
		}
		return ans;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> temperatures{ 73,74,75,71,69,72,76,73 };
	auto res = Solution().dailyTemperatures(temperatures);
	for (int i : res)
		cout << i << " ";
	cout << endl;

	system("pause");
	return 0;
}

