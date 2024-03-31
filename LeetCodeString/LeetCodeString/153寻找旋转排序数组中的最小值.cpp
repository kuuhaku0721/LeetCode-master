#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
* 若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
* 若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
* 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
* 
* 给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
* 
* 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
*/

/*
* 翻译一下就是用二分法去找最小值
* 跟前面那道题很像（我指旋转部分）,但是前面那道题是事先先找到最小值然后再二分
* 所以还得有个办法去找这个最小值
*/

class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;

		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] > nums[right])
				left = mid + 1;
			else
				right = mid;
		}
		return nums[left];
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

