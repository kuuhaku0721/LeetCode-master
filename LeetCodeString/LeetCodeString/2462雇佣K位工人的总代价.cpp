#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
* 给你一个下标从 0 开始的整数数组 costs ，其中 costs[i] 是雇佣第 i 位工人的代价。
* 同时给你两个整数 k 和 candidates 。我们想根据以下规则恰好雇佣 k 位工人：
* 总共进行 k 轮雇佣，且每一轮恰好雇佣一位工人。
* 在每一轮雇佣中，从最前面 candidates 和最后面 candidates 人中选出代价最小的一位工人，如果有多位代价相同且最小的工人，选择下标更小的一位工人。
* 比方说，costs = [3,2,7,7,1,2] 且 candidates = 2 ，第一轮雇佣中，我们选择第 4 位工人，因为他的代价最小 [3,2,7,7,1,2] 。
* 第二轮雇佣，我们选择第 1 位工人，因为他们的代价与第 4 位工人一样都是最小代价，而且下标更小，[3,2,7,7,2] 。注意每一轮雇佣后，剩余工人的下标可能会发生变化。
* 如果剩余员工数目不足 candidates 人，那么下一轮雇佣他们中代价最小的一人，如果有多位代价相同且最小的工人，选择下标更小的一位工人。
* 一位工人只能被选择一次。
* 返回雇佣恰好 k 位工人的总代价。
*/

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;   // 堆默认是大根堆，所以要注意这里小根堆的写法
        int left = candidates - 1, right = n - candidates;
        if (left + 1 < right) {
            for (int i = 0; i <= left; ++i) {
                q.emplace(costs[i], i);
            }
            for (int i = right; i < n; ++i) {
                q.emplace(costs[i], i);
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                q.emplace(costs[i], i);
            }
        }
        long long ans = 0;
        for (int _ = 0; _ < k; ++_) {
            auto [cost, id] = q.top();      // 这个是17的标准，很神奇，但是很难懂
            q.pop();
            ans += cost;
            if (left + 1 < right) {
                if (id <= left) {
                    ++left;
                    q.emplace(costs[left], left);
                }
                else {
                    --right;
                    q.emplace(costs[right], right);
                }
            }
        }
        return ans;
    }
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

