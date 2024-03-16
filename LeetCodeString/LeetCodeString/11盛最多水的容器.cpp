#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
* 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
* 返回容器可以储存的最大水量。
* 说明：你不能倾斜容器。
*/

/*
* 外层循环，循环遍历每一个数
* 内层循环，从右向左找第一个小于等于它的数，然后算底乘高，得到的值就是盛水量
* 然后保存最大值
* 很好，嵌套循环不行，超时了
* 莫急，这一题是双指针的题，大分类这么告诉我们了，那就按双指针写
*/

class Solution {
public:
	int maxArea(vector<int>& height) {
		int ans = 0;
		int left = 0, right = height.size() - 1;
		while (left < right)
		{
			int lower = min(height[left], height[right]);
			ans = max(ans, (right - left) * lower);
			if (height[left] <= height[right])
				++left;
			else
				--right;
		}
		return ans;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 1,8,6,2,5,4,8,3,7 };
	int res = Solution().maxArea(nums);
	cout << res << endl;

	system("pause");
	return 0;
}

