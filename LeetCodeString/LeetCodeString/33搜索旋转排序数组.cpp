#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 整数数组 nums 按升序排列，数组中的值 互不相同 。
* 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，
* 使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
* 例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
* 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
* 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
*/

/*
* 看到O(logn)就知道是二分，也确实就是二分，只不过不能排序，不能复原，就得从它(min)出发
* 但是min_element复杂度是个O(n)，这和直接排序有什么区别？
* 直接sort排序复杂度是O(nlogn)，也不行....
* 所以卡在了怎么找最小值上...
* 很好，用二分找最小值
* 然后再二分找target
* 
* 桥豆麻袋....两个有序的，我为啥不二分两次呢？
* 啊？为啥呢？
* 行吧，两次二分反倒是最慢的
*/
class Solution {
public:
	int search1(vector<int>& nums, int target) {
		// 先找最小值在的地方
		int minus = 0;
		int right = nums.size() - 1;

		while (minus < right)
		{
			int mid = minus + (right - minus) / 2;
			if (nums[mid] > nums[right])
				minus = mid + 1;
			else
				right = mid;
		}
		// 现在minus存的就是最小值所在的下标
		int maxnum = ((minus - 1) + nums.size()) % nums.size();  // 最大值就是它左边那个，只不过要循环
		if (nums[minus] > target || nums[maxnum] < target) return -1;
		int flag = 0;	// 0初始态，-1：max < min的时候  1 max > min的时候
						// 判断的基准就是，如果从max > min的状态变到了max < min的状态，说明没找到，可以return了

		while (1)
		{
			int mid;
			if (maxnum < minus)
			{
				mid = (minus + ((maxnum + nums.size()) - minus) / 2) % nums.size();
				if (flag == 1)
					return -1;
				flag = -1;
			}
			else if (maxnum > minus)
			{
				mid = minus + (maxnum - minus) / 2;
				flag = 1;
			}
			else
			{
				if (nums[minus] != target)
					return -1;
				else
					return minus;
			}


			if (nums[mid] > target)
				maxnum = ((mid - 1) + nums.size()) % nums.size();
			else if (nums[mid] < target)
				minus = ((mid + 1) + nums.size()) % nums.size();
			else
				return minus;
		}
		return -1;
	}

	int search(vector<int>& nums, int target) {
		// 先找最小值在的地方
		int minus = 0;
		int right = nums.size() - 1;

		while (minus < right)
		{
			int mid = minus + (right - minus) / 2;
			if (nums[mid] > nums[right])
				minus = mid + 1;
			else
				right = mid;
		}
		// 从minus中断开，左边是个二分，右边也是个二分，然后就结束了
		int left = 0, minus2 = minus;
		minus = ((minus - 1) + nums.size()) % nums.size();
		// 先左边
		while (left <= minus)
		{
			int mid = left + (minus - left) / 2;
			if (nums[mid] > target)
				minus = mid - 1;
			else if (nums[mid] < target)
				left = mid + 1;
			else
				return mid;
		}
		right = nums.size() - 1;
		while (minus2 <= right)
		{
			int mid = minus2 + (right - minus2) / 2;
			if (nums[mid] > target)
				right = mid - 1;
			else if (nums[mid] < target)
				minus2 = mid + 1;
			else
				return mid;
		}
		return -1;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 1, 3 };
	int target = 1;
	int index = Solution().search(nums, target);
	cout << index << endl;

	system("pause");
	return 0;
}

