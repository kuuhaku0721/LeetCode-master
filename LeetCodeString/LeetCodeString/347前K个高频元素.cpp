#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/*
* 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
*/

//找个容器转存vector的数据，存的时候跟上它的数量，然后数量排序，找最大的两个
//map没法直接按值排序，所以可以用遍历解决
//遍历很麻烦，所以还是排序吧，map里面存的是个键值对，这个键值对是没有数据类型的，所以需要对map数据进行转存

bool mycmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second > p2.second;
}

class Solution {
public:
	

	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> map_nums;
		for (int i : nums)
		{
			map_nums[i]++;
		}

		/*cout << "map存的数据为：" << endl;
		for (auto it = map_nums.begin(); it != map_nums.end(); it++)
		{
			cout << it->first << "-->" << it->second << endl;
		}*/

		vector<pair<int, int>> vecPair;
		for (auto it = map_nums.begin(); it != map_nums.end(); it++)
		{
			vecPair.push_back(pair<int, int>(it->first, it->second));
		}
		sort(vecPair.begin(), vecPair.end(), mycmp); //注意这个函数要是全局的

		vector<int> res;
		for (int i = 0; i < k; i++)
		{
			res.push_back(vecPair[i].first);
		}
		return res;
	}
};


int main()
{
	cout << "hello world" << endl;
	vector<int> nums{ 1,1,1,2,2,3 };
	vector<int> res = Solution().topKFrequent(nums, 1);
	for (int i : res)
	{
		cout << i << "|";
	}
	cout << endl;

	system("pause");
	return 0;
}

