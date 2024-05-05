#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <numeric>
using namespace std;

/*
* 有 n 名工人。 给定两个数组 quality 和 wage ，其中，quality[i] 表示第 i 名工人的工作质量，其最低期望工资为 wage[i] 。
现在我们想雇佣 k 名工人组成一个工资组。在雇佣 一组 k 名工人时，我们必须按照下述规则向他们支付工资：
1、对工资组中的每名工人，应当按其工作质量与同组其他工人的工作质量的比例来支付工资。
2、工资组中的每名工人至少应当得到他们的最低期望工资。
给定整数 k ，返回 组成满足上述条件的付费群体所需的最小金额 。在实际答案的 10-5 以内的答案将被接受。。
*/

/*
* class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = wage.length;
        double[][] wagePerQual = new double[n][2];
        for (int i = 0; i < n; i++) {
            wagePerQual[i][0] = i;
            wagePerQual[i][1] = (double) wage[i] / quality[i];
        }
        Arrays.sort(wagePerQual, Comparator.comparingDouble(a -> a[1]));
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        double res = Double.MAX_VALUE, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += quality[(int) wagePerQual[i][0]];
            pq.offer(quality[(int) wagePerQual[i][0]]);
            if (pq.size() > k) sum -= pq.poll();
            if (pq.size() == k) res = Math.min(res, sum * wagePerQual[i][1]);
        }
        return res;
    }
}
*/

class Solution1 {
public:
	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        vector<vector<double>> wagePerQual(n, vector<double>(2, 0.0));
        for (int i = 0; i < n; i++)
        {
            wagePerQual[i][0] = i;
            wagePerQual[i][1] = (double)wage[i] / quality[i] * 1.0;
        }
        sort(wagePerQual.begin(), wagePerQual.end(), [](auto& lp, auto& rp) {
            return lp[1] - rp[1];
            });
        priority_queue<int, vector<int>, greater<int>> pq;
        double res = INT_MAX * 1.0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += quality[(int)wagePerQual[i][0]];
            pq.push(quality[(int)wagePerQual[i][0]]);
            if (pq.size() > k) sum -= pq.top(); pq.pop();
            if (pq.size() == k) res = min(res, sum * wagePerQual[i][1]);
        }
        return res;
	}
};


// 官解，我做不出来
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<int> h(n, 0);
        iota(h.begin(), h.end(), 0);
        sort(h.begin(), h.end(), [&](int& a, int& b) {
            return quality[a] * wage[b] > quality[b] * wage[a];
            });
        double res = 1e9;
        double totalq = 0.0;
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < k - 1; i++) {
            totalq += quality[h[i]];
            q.push(quality[h[i]]);
        }
        for (int i = k - 1; i < n; i++) {
            int idx = h[i];
            totalq += quality[idx];
            q.push(quality[idx]);
            double totalc = ((double)wage[idx] / quality[idx]) * totalq;
            res = min(res, totalc);
            totalq -= q.top();
            q.pop();
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

