#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/

/*
* 慢指针标记左边位置，然后向右找第一个大于等于它的
* 找到之后计算中间空余部分大小，就是能接的大小
* 然后更新慢指针位置，快指针继续向前
* 从左到右扫描不行了，第一个用例就过不去，会掉最后一个
* 那就试试从上到下
*/

class Solution1 {
public:
	int trap1(vector<int>& height) {
		int res = 0;
		int slow = 0, fast = 0;
		// 从第一个非0位置开始
		while (height[slow] == 0)
			++slow;
		fast = slow + 1;
		while (fast < height.size())
		{
			if (height[fast] < height[slow])
				++fast;
			else
			{
				// 累计雨水
				for (int i = slow; i < fast; ++i)
				{
					res += height[slow] - height[i];
				}
				// 更新左边位置
				slow = fast;
				++fast;
			}
		}
		return res;
	}
};

/*
* 官解的双指针写法
* 写法本身是不难的，难的在于怎么能想到那儿去
* 官解的双指针是从左右两端往中间去
* 我自己的写法是快慢指针往最右端去，这会有一个问题，最后一个没法加上
* 而官解的解决办法是一边走一遍加，因为只要维护好了最大值，那中间的就都可以直接加上了
*/
class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		int left = 0, right = height.size() - 1;
		int leftMax = 0, rightMax = 0;
		while (left < right) 
		{
			leftMax = max(leftMax, height[left]);
			rightMax = max(rightMax, height[right]);
			
			if (height[left] < height[right]) 
			{
				ans += leftMax - height[left];
				++left;
			}
			else 
			{
				ans += rightMax - height[right];
				--right;
			}
		}
		return ans;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> heights{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	int res = Solution().trap(heights);
	cout << res << endl;

	system("pause");
	return 0;
}

