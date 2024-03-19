#define CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <crtdbg.h>
using namespace std;

/*
* 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
* 子数组是数组中元素的连续非空序列。
*/

/*
* 注意连续，非空，连续，连续
* 感觉是个滑动窗口的题，但是分类分到了子串，不知道为啥
* 看来双指针是不行了，它有负数.......你不要等我错完了再告诉我啊....
* 暴力双循环，超时...
* 学到个新东西，一个叫前缀和的东东
* 好家伙，这题是除了前缀和就没解法了吗，全都是前缀和
*/

class Solution {
public:
	int subarraySum1(vector<int>& nums, int k) {
		if (nums.empty()) return 0;
		if (nums.size() < 2) return nums[0] == k ? 1 : 0;

		int sum = 0;
		int wndSize = 1;
		int res = 0;
		while (wndSize <= nums.size())
		{
			for (int i = 0; i <= nums.size() - wndSize; i++)
			{
				int sum = 0;
				for (int j = i; j < i + wndSize; j++)
				{
					sum += nums[j];
				}
				if (sum == k) res++;
			}
			wndSize++;
		}
		return res;
	}
	int subarraySum(vector<int>& nums, int k) {
		int res = 0;
		// 前缀和好理解，只不过多一个第一个是0，不然后面没法判断
		vector<int> prefixsum(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); i++)
		{
			prefixsum[i + 1] = prefixsum[i] + nums[i];
		}
		// 然后是这个哈希表是如何判断的，哈希表判断(不管find还是count都一样，找存不存在)是拿当前位置的前缀和减去目标数
		// 如果减的结果等于0，说明这个位置的前缀和刚好就是目标结果，也就是从0开始一直加到当前位置，总和刚好就是结果
		// 如果减的结果不等于0，且在哈希表中存在，说明当前位置的前缀和（pre1）减去目标数之后的结果是另一个前缀和(pre2)
		// ，也就代表着从那个前缀和(pre2)的位置开始加，一直加到当前位置(pre1的位置)，总和刚好就是结果
		// 如果减的结果不等于0还在哈希表中没有，说明不存在某一段的总和结果能够等于结果
		unordered_map<int, int> umap;
		for (int i = 0; i < prefixsum.size(); i++)
		{
			if (umap.count(prefixsum[i] - k) != 0)
				res += umap[prefixsum[i] - k];
			umap[prefixsum[i]]++;
		}
		

		return res;
	}
};


int main()
{
	
	cout << "hello world" << endl;
	vector<int> nums{ 1, -1, 0 };
	int k = 0;
	int res = Solution().subarraySum(nums, k);
	cout << res << endl;
	int* iptr = new int(3);
	
	cout << "下面是测试" << endl;
	string s = "the blue";
	reverse(s.begin(), s.end());
	cout << s << endl;
	

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}

