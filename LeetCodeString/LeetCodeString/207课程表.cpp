#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
* 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
* 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，
* 表示如果要学习课程 ai 则 必须 先学习课程  bi 。
* 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
* 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
*/

/*
* 需要先找到第一门课学啥，第一门课不需要前驱课程，然后后面的就好说了
* 后面就可以定向去找了，但问题是这个第一门课不好找
* 先排序，排完序之后二分查起来会快一点，然后从第一个的第二个数开始找，找没有以它开头的那个数，那么它就是第一门课
* 
* 写法出来了，但是因为测试用例长度是个5000，所以应该是超时的
* 嘶...先不说超时不超时，有个用例：是 5  [[1,4],[2,4],[3,1],[3,2]]，它一共就四门课，为啥会有个5啊，结果为啥是true啊，超出常人理解了啊
* 好吧，原来意思是，有一门不依赖于任何一门课...
* 
* 很好，写不出来，放弃了，图论的题不适合暴力
*/
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if (prerequisites.empty()) return true;
		sort(prerequisites.begin(), prerequisites.end(), [&](vector<int>& lp, vector<int>& rp) {
			return lp[0] < rp[0];
			});
		vector<int> firstLessons;
		for (int i = 0; i < prerequisites.size(); ++i)
		{
			int curnum = prerequisites[i][1];
			int left = 0, right = prerequisites.size() - 1;
			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				if (prerequisites[mid][0] > curnum)
					right = mid - 1;
				else if (prerequisites[mid][0] < curnum)
					left = mid + 1;
				else    // 相等，那它就不能当第一节课，直接跳出就行
					break;
			}
			if (left > right)
			{	// 没找到，说明可以让它当作第一节课
				firstLessons.push_back(curnum);
			}
		}

		if (!firstLessons.empty())
		{
			/*cout << "可选的第一节课" << endl;
			for (int i : firstLessons)
				cout << i << " ";
			cout << endl;*/
			// 现在已知能够当作第一节课修的
			auto backup = prerequisites;
			unordered_set<int> uset;
			for (int first : firstLessons)
			{	// 直接把所有无依赖的先修课全部插入
				uset.insert(first);
			}
			bool flag = false;
			int cnt = 0;
			while (!flag)
			{
				for (int i = 0; i < backup.size(); ++i)
				{
					if (uset.find(backup[i][1]) != uset.end())
					{
						uset.insert(backup[i][0]);
						backup[i][0] = -1;
						backup[i][1] = -1;
						cnt++;
						flag = true;
					}
				}
				if (flag)
					flag = false;
				else
					break;
			}
			// 不能判断uset的大小了，得判断backup，因为上面已经置-1了，现在只需要判断是否全为-1就行了
			// 全为-1说明所有依赖关系都解决了
			if (cnt == backup.size())
				return true;
		}
		return false;
	}
};

int main()
{
	cout << "hello world" << endl;

	vector<vector<int>> lessons{
		{1, 4},
		{2, 4},
		{3, 1},
		{3, 2}
	};
	bool res = Solution().canFinish(5, lessons);
	if (res)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}

