#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>		// 优先级队列，默认降序，也就是大顶堆
using namespace std;

/*
* 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
* 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
* 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/

/*
* 虽然一个sort解决了，但是这题本意不是这么做的
* 要求用的堆，STL里面也是有堆的，大顶堆，小顶堆
* 这题..有人手写快排，有人首先大根堆，还有人直接sort，真就各路神通呗
*/

class Solution {
public:
	int findKthLargest1(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}

	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> pri_que;
		for (int i = 0; i < nums.size(); i++)
		{
			pri_que.push(nums[i]);
		}
		while (k > 1)
			pri_que.pop();
		return pri_que.top();
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

