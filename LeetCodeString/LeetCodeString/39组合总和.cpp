#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，
并以列表形式返回。你可以按 任意顺序 返回这些组合。
candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
对于给定的输入，保证和为 target 的不同组合数少于 150 个。
*/

/*
* 不出意外，还是一样的回溯法可以解决
* 这次的变化是需要的是总和，所以要多一个记录总和的数
* 哟西，成了，但不明白的是，大家都是回溯暴力，为啥写得多的反倒时间快捏....
* 中规中矩，但起码解决问题了,那就哟西
*/

class Solution {
public:
	vector<vector<int>> result;
	vector<int> vec;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.size() == 0) return result;
		BackTracking(candidates, 0, target, 0);
		return result;
	}

	void BackTracking(vector<int>& candidates, int index, int target, int sum)
	{
		if (sum == target)
		{
			result.push_back(vec);
			return;
		}
		if (sum > target)
			return;

		for (int i = index; i < candidates.size(); i++)
		{
			sum += candidates[i];
			vec.push_back(candidates[i]);
			BackTracking(candidates, i, target, sum);
			sum -= vec[vec.size() - 1];
			vec.pop_back();
		}
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

