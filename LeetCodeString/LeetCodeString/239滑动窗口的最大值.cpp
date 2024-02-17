#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
* 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。
*/

/*
* 困难题，得认真对待一下
* 
* 前置需要知道的：
* 直接看是看不出来东西的，暴力破解就超时了，首先得知道这题要用队列解决
* 队列有两种，queue和deque、deque是双端队列
* 
* 先用队列写个试试，看能不能解决，然后再考虑单调队列的标准解法
* 这题的重点是学会单调队列这种写法
*/

/*
* 先尝试第一种
* 维护一个队列，队列里面存当前窗口的值，然后取这个队列里的最大值，保存到结果里面
* k一定小于等于length，所以要先往队列里存进去k个数，然后开始遍历
*/
class Solution1 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		queue<int> que;
		for (int i = 0; i < k; i++)
		{
			que.push(nums[i]);
		}
		vector<int> res;
		res.push_back(findMaxInQueue(que));
		for (int i = k; i < nums.size(); i++)
		{
			que.pop();
			que.push(nums[i]);
			res.push_back(findMaxInQueue(que));
		}
		return res;
	}

	int findMaxInQueue(queue<int> que)
	{
		int maxNum = INT_MIN;
		while (!que.empty())
		{
			if (que.front() >= maxNum)
			{
				maxNum = que.front();
				que.pop();
			}
			else
			{
				que.pop();
			}
		}
		return maxNum;
	}
};
//很好，跟预期的一样，超时了，测试用例粘进来vs就卡死

/*
* 该学单调队列的写法了
* 
* 单调队列方法区写这一题，主函数的写法和上面的方法几乎一样
* 区别在于队列，单调队列实现的难度在于单调队列如何去实现
* 单调队列的pop(value):如果窗口移除的元素value等于单调队列的出口元素，那么队列弹出元素，否则不用任何操作
* 单调队列的push(value):如果push的元素value大于入口元素的数值，那么就将队列入口的元素弹出，直到push元素的数值小于等于队列入口元素的数值为止
*/
class Solution {
public:
	class MonotonicQueue
	{
	private:
		deque<int> que;

	public:
		void pop(int value)
		{
			if (!que.empty() && value == que.front())
				que.pop_front();
		}

		void push(int value)
		{
			while (!que.empty() && value > que.back())
			{
				que.pop_back();
			}
			que.push_back(value);
		}

		int front()
		{
			return que.front();
		}
	};


	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		MonotonicQueue monque;
		//还是先把前k个数放进去队列
		for (int i = 0; i < k; i++)
		{
			monque.push(nums[i]);
		}
		vector<int> result;
		result.push_back(monque.front()); //放进去第一个窗口最大值
		for (int i = k; i < nums.size(); i++)
		{
			monque.pop(nums[i - k]); //这里的i-k取得值当前窗口将要出去的那个值,就是窗口最左边那个，窗口出去一个值，但是单调队列里面要看条件要不要出
			monque.push(nums[i]); //窗口出去一个值，然后再进去一个值，保证窗口的大小，但是在单调队列里面进不进去看条件
			result.push_back(monque.front());
		}
		return result;
	}
};
/*
* 单调队列得解法，没问题，了解了一丢丢
* 等待后续得再次巩固
* 虽然下次再遇到就不知道什么时候了
*/

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 1,-1};
	int k = 1;
	vector<int> res = Solution().maxSlidingWindow(nums, k);
	for (int i : res)
	{
		cout << i << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

