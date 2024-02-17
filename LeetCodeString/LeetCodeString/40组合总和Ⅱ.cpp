#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
* 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。 
*/

/*
* 额...嗯，上一题，也就是39，其实就是这么写的来着
* 直接拿来用试试行不行
* 每个数字在每个组合中只可以用一次，不能有重复
* 目前的写法，也就是index+1的写法是没有问题的，只是少一步去重
* 需要把去重这一步想个地方加进去
* 可以先存下来全部，然后再一个个删除，但这样效率就会非常低
* 找到问题所在了，我每次在判断是否存在的时候都排序了，但是因为当次插入结果集结束后都返回去，然后popback
* 但是排完序之后，popback出来的结果就不对了，pop出去了原本不应该出去的数，所以结果就错了，
* 所以如果核心运算是像下面这么写的话，那么排序就不能在外面先排，也不能引用排，不能改变它原本的顺序
* 或者，在开始回溯之前，直接把原数组给排序掉，这样就不出出现排序玩pop错数的情况了
* 同时，经过这次调试也发现，回溯出来，每一次的结果叠起来看的话，就是一颗树的形状
* 二叉树，博大精深，恐怖如斯
*/

class Solution {
public:
	vector<vector<int>> result;
	vector<int> vec;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.size() == 0) return result;
		sort(candidates.begin(), candidates.end());
		BackTracking(candidates, -1, target);
		return result;
	}

	void BackTracking(vector<int>& candidates, int index, int target)
	{
		int sum = accumulate(vec.begin(), vec.end(), 0);
		if (sum > target)
			return;
		if (sum == target)
		{
			// cout << "\t当需要添加进去结果集的时候，现在的vec是："; for (int i : vec) cout << i << " "; cout << endl;
			
			sort(vec.begin(), vec.end());
			if (IsExists(vec) == false)
			{
				result.push_back(vec);	
			}
			return;
		}
		// [4,4,2,1,4,2,2,1,3]  6
		for (int i = index + 1; i < candidates.size(); i++)
		{
			vec.push_back(candidates[i]);
			
			// cout << "放进去:"; for (int i : vec) cout << i << " "; cout << endl;

			BackTracking(candidates, i, target);
			vec.pop_back();

			// cout << "    拿出来:"; for (int i : vec) cout << i << " "; cout << endl;
		}
	}

	bool IsExists(vector<int>& vec)
	{
		if (result.size() < 1) return false;
		// sort(vec.begin(), vec.end());
		bool flag = false;
		for (vector<int> v : result)
		{
			if (v.size() != vec.size()) continue;
			// sort(v.begin(), v.end());
			int i;
			for (i = 0; i < v.size(); i++)
			{
				if (vec[i] != v[i]) break;
			}
			if (i == v.size())
			{
				flag = true;
				break;
			}
		}
		return flag;
	}
};

/*
* 孩子，不必拘泥于眼前的苟且，还是看看远方的标准答案吧
* 你问为什么做出来了还要看答案？
* 超时了啊........
*/
class Solution2 {
private:
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
		if (sum == target) {
			result.push_back(path);
			return;
		}
		for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
			// used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
			// used[i - 1] == false，说明同一树层candidates[i - 1]使用过
			// 要对同一树层使用过的元素进行跳过
			if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
				continue;
			}
			sum += candidates[i];
			path.push_back(candidates[i]);
			used[i] = true;
			backtracking(candidates, target, sum, i + 1, used); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
			used[i] = false;
			sum -= candidates[i];
			path.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<bool> used(candidates.size(), false);
		path.clear();
		result.clear();
		// 首先把给candidates排序，让其相同的元素都挨在一起。
		sort(candidates.begin(), candidates.end());
		backtracking(candidates, target, 0, 0, used);
		return result;
	}
};

int main()
{
	cout << "hello world" << endl;
	vector<int> vec{ 4,4,2,1,4,2,2,1,3 };
	int target = 6;
	auto res = Solution().combinationSum2(vec, target);

	system("pause");
	return 0;
}

