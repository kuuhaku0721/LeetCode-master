#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 你打算利用空闲时间来做兼职工作赚些零花钱。
* 这里有 n 份兼职工作，每份工作预计从 startTime[i] 开始到 endTime[i] 结束，报酬为 profit[i]。
* 给你一份兼职工作表，包含开始时间 startTime，结束时间 endTime 和预计报酬 profit 三个数组，请你计算并返回可以获得的最大报酬。
* 注意，时间上出现重叠的 2 份工作不能同时进行。
* 如果你选择的工作在时间 X 结束，那么你可以立刻进行在时间 X 开始的下一份工作。
*/

/*官解 动规加二分
* 今天摆了，后天再说
*/
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = { startTime[i], endTime[i], profit[i] };
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int>& job1, const vector<int>& job2) -> bool {
            return job1[1] < job2[1];
            });
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int k = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, const vector<int>& job) -> bool {
                return st < job[1];
                }) - jobs.begin();
                dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

