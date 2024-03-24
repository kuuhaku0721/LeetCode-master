#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// map不能直接排序，所以可以转到vector里面再排序
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> mp;
		for (int i : nums)
			mp[i]++;
		vector<pair<int, int>> vec;
		for (auto pr : mp)
			vec.push_back(pr);
		sort(vec.begin(), vec.end(), [](pair<int, int>& lp, pair<int, int>& rp) {
			return lp.second > rp.second;
			});
		vector<int> result;
		for (int i = 0; i < k; i++)
		{
			result.push_back(vec[i].first);
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

