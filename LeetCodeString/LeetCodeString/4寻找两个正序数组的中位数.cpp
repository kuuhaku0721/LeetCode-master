#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
* 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
* 算法的时间复杂度应该为 O(log (m+n)) 。
*/

/*
* 要求的时间复杂度log(m+n)意思就是解法是两次二分查找
* 然后取结果的平均值就完事了
* 但是啊，但是，它已经有序了，还有必要二分吗？直接取下标不好吗？
* 不好，是的，一点也不好
* 看测试用例能看出来，它要的中位数不是两个中位数取平均，而是两个数组组合起来之后的中位数
* so，如何先合并数组再取中位数计算，时间复杂度是O(n + logn) 很显然不是要求的O(log(m+n))
* 也就是说，解法就是两边同时二分
* 这就麻烦了啊.....怪不得你是困难
* 双二分的话，可以两个beg两个end，比较谁小动谁或者谁大动谁，那么问题就变成了：什么时候结束？
* 很好，知道咋做，但是不会做，笑死，这算什么事啊
*/
class Solution {
public:
	// 然后才是正经解法:已知两个有序数组，如何在这两个数组中进行二分查找
	// 先不考虑二分的事情，先直接四指针的去做
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		// 官解一轮先不管，下次来的时候再看
	}

	// 先保证题能写的出来
	// 另外一种写法是先确定两个起始位置
	// 然后比较大小，谁小谁往前移动一位，如果某一方一定到达末尾则只需移动另一个
	// 然后计算下标和，因为两个数组大小已知，那么它们的中位数的下标和就是已知的，所以直接计算下标和就可以了
	// 但是，这样复杂还是O(m+n)而不是O(log(m+n))，所以还是得看官解
	double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
		vector<int> vec(nums1.size() + nums2.size());
		for (int i = 0; i < nums1.size(); i++)
		{
			vec[i] = nums1[i];
		}
		for (int i = 0; i < nums2.size(); i++)
		{
			vec[nums1.size() + i] = nums2[i];
		}

		sort(vec.begin(), vec.end());
		if (vec.size() % 2 == 0)
			return double((vec[vec.size() / 2] + vec[vec.size() / 2 - 1]) / 2.0);
		else
			return vec[vec.size() / 2] * 1.0;
	}
};



int main()
{
	cout << "hello world" << endl;
	vector<int> nums1{ 1,3 };
	vector<int> nums2{ 2,7 };
	double res = Solution().findMedianSortedArrays(nums1, nums2);
	cout << res << endl;


	system("pause");
	return 0;
}

