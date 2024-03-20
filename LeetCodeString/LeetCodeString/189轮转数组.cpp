#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
* 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
*/


/*
* 说，你和右旋字符串什么关系
* 进阶版要求O(1)的空间，也就是原地变
* 测试用例通过了但是耗时太长，也就是不能把最后一个插到队头然后扔出去最后一个
* 但是还要原地变换
* 那用队列吧，刚好先进先出，出去的立马进入
* 但是用队列不就还是多用空间了吗？ 嘶.....那就用吧
*/
class Solution {
public:
	void rotate1(vector<int>& nums, int k) {
		int len = nums.size();
		k = k % nums.size();
		for (int i = 0; i < k; ++i)
		{
			nums.insert(nums.begin(), nums[nums.size() - 1]);
			nums.resize(len);
			cout << "当前nums = ";
			for (int i : nums)
				cout << i << " ";
			cout << endl;
		}
	}
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		queue<int> que;
		// 转存到队列
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			que.push(nums[i]);
		}
		// 然后弹出，进入
		while (k > 0)
		{
			int n = que.front();
			que.pop();
			que.push(n);
			--k;
		}
		// 再存回去vector
		nums.clear();
		while (!que.empty())
		{
			int n = que.front();
			nums.push_back(n);
			que.pop();
		}
		reverse(nums.begin(), nums.end());
	}
};


int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 1,2,3,4,5,6,7 };
	int k = 3;
	Solution().rotate(nums, k);
	for (int i : nums)
		cout << i << " ";
	cout << endl;

	system("pause");
	return 0;
}

