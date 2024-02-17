#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
* 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/

/*
* 不能用循环套循环，四个数组，肯定超时
* 这题还被归类为了哈希表
* 所以得从哈希表的角度出发
* 
* 思路，很牛B啊..
*/

class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int, int> mapAB;

		for (int a : nums1)
		{
			for (int b : nums2)
			{
				int sum = a + b;
				mapAB[sum]++;
			}
		}
		int cnt = 0;
		for (int c : nums3)
		{
			for (int d : nums4)
			{
				int sum = c + d;
				if (mapAB.find(0 - sum) != mapAB.end())
					cnt += mapAB[0-sum];
			}
		}
		
		
		return cnt;
	}
};



int main()
{
	cout << "hello world" << endl;
	vector<int> nums1;
	vector<int> nums2;
	vector<int> nums3;
	vector<int> nums4;
	nums1.push_back(0);
	nums2.push_back(0);
	nums3.push_back(0);
	nums4.push_back(0);

	int res = Solution().fourSumCount(nums1, nums2, nums3, nums4);
	cout << res << endl;

	system("pause");
	return 0;
}

