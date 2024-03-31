#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
* 例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
* 整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，
* 如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。
* 如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
* 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
* 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
* 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
* 给你一个整数数组 nums ，找出 nums 的下一个排列。
* 必须 原地 修改，只允许使用额外常数空间。
*/

/*
* 倒着找，找第一个不是升序的位置，也就是从它开始往后都是降序，先锁定它的位置
* 然后继续倒着往前找，找到第一个小于它的，然后交换一下位置
* 比如  1 2 3 6 5 4  那么倒着第一个不满足升序的是6  然后继续往前，第一个小于它的是3，交换3的位置为前面已经遍历过的最小值4
* 然后从这个位置往后的，也就是 1 2 4 6 5 3 从4下一个开始，也就是6 5 3 升序排列
* 如果找不到这个变序位置，直接sort一下结束
* 
* 虽然个位数的百分比，但是起码过了不是吗
*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		// 分多轮遍历吧，第一轮找第一个不满足倒着升序的位置
		// 第二轮找比它大的最小值
		int i;
		for (i = nums.size() - 1; i > 0; --i)
		{
			if (nums[i] > nums[i - 1]) break;
		}
		if (i == 0)
		{	// 一口气遍历到了开头，说明现在整个数组处于降序状态
			sort(nums.begin(), nums.end());
			return;
		}
		--i; // 现在i的位置就是不满足的位置
		// 现在要找到的位置是，比i的位置大的最小值所在的下标及数字
		pair<int, int> currIdx(-1, INT_MAX);
		for (int j = nums.size() - 1; j > i; --j)
		{
			/*if (nums[j] > nums[i])
			{
				minIdx = nums[minIdx] < nums[j] ? minIdx : j;
			}*/
			if(nums[j] > nums[i])
			{
				if (nums[j] < currIdx.second)
				{
					currIdx.first = j;
					currIdx.second = nums[j];
				}
			}
		}
		// 现在 i 是被交换位置，minIdx是交换位置，交换这两个值
		int t = nums[currIdx.first];
		nums[currIdx.first] = nums[i];
		nums[i] = t;
		// 然后后面的直接排序
		sort(nums.begin() + i + 1, nums.end());
		
		// 输出验证一下
		for (int i : nums)
			cout << i << " ";
		cout << endl;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 2,3,1 };
	Solution().nextPermutation(nums);

	system("pause");
	return 0;
}

