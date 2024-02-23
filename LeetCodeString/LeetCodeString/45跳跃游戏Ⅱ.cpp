#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
* 每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
* 0 <= j <= nums[i] 
* i + j < n
* 返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
*/

/*
* 我感觉，上一题的写法，能用，而且题目也说了，一定能到最后一个
* 那就一格一格的走，保留最小值就行了，但是这样的话，可能需要双层循环了
* 感觉不太行，没法确定外层循环从第二次循环开始，在它之前跳过几次，既然是贪心，那就得透过现象看本质
* 单纯根据现有的测试用例可以先假设：当前位置可到达的范围内，如果有比它大的，那就先到大数那里，如果没有，那就尽最大的跳
* 如果是这样的话，就不是找跳数最少的了，而是直接跳最少的然后统计次数了
* 我cv了，我有罪...
*/

class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		int curDistance = 0;    // 当前覆盖最远距离下标
		int ans = 0;            // 记录走的最大步数
		int nextDistance = 0;   // 下一步覆盖最远距离下标
		for (int i = 0; i < nums.size(); i++) {
			nextDistance = max(nums[i] + i, nextDistance);  // 更新下一步覆盖最远距离下标
			if (i == curDistance) {                         // 遇到当前覆盖最远距离下标
				ans++;                                  // 需要走下一步
				curDistance = nextDistance;             // 更新当前覆盖最远距离下标（相当于加油了）
				if (nextDistance >= nums.size() - 1) break;  // 当前覆盖最远距到达集合终点，不用做ans++操作了，直接结束
			}
		}
		return ans;
	}
};


int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 2,3,1,1,4 };
	int res = Solution().jump(nums);
	cout << res << endl;

	system("pause");
	return 0;
}

