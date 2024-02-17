#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

/*
* 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
*/

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> Set;
		for (int i : nums1)
		{
			Set.insert(i);
		}
		vector<int> result;
		for (int i : nums2)
		{
			if (Set.find(i) != Set.end())
			{
				if (find(result.begin(), result.end(), i) == result.end())
				{
					result.push_back(i);
				}
			}
		}
		return result;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

