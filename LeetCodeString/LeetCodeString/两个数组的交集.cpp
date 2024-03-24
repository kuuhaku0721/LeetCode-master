#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> uset(nums1.begin(), nums1.end());
		unordered_set<int> uset2(nums2.begin(), nums2.end());
		vector<int> res;
		for (int i : uset2)
		{
			if (uset.count(i) != 0)
				res.push_back(i);
		}
		return res;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

