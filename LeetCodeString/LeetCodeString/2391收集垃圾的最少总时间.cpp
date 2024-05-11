#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
* 给你一个下标从 0 开始的字符串数组 garbage ，其中 garbage[i] 表示第 i 个房子的垃圾集合。garbage[i] 只包含字符 'M' ，'P' 和 'G' ，
* 但可能包含多个相同字符，每个字符分别表示一单位的金属、纸和玻璃。垃圾车收拾 一 单位的任何一种垃圾都需要花费 1 分钟。
* 同时给你一个下标从 0 开始的整数数组 travel ，其中 travel[i] 是垃圾车从房子 i 行驶到房子 i + 1 需要的分钟数。
* 城市里总共有三辆垃圾车，分别收拾三种垃圾。每辆垃圾车都从房子 0 出发，按顺序 到达每一栋房子。但它们 不是必须 到达所有的房子。
* 任何时刻只有 一辆 垃圾车处在使用状态。当一辆垃圾车在行驶或者收拾垃圾的时候，另外两辆车 不能 做任何事情。
* 请你返回收拾完所有垃圾需要花费的 最少 总分钟数。
*/

/*
* 简单来说就是，先确定PGM三辆车要走到哪，也就是PGM最后出现的位置然后一辆车一辆车的累加就完事了
* 最后出现的位置倒着找一下就可以了
*/
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char, int> distance;
        int res = 0, cur_dis = 0;
        for (int i = 0; i < garbage.size(); i++) {
            res += garbage[i].size();
            if (i > 0) {
                cur_dis += travel[i - 1];
            }
            for (auto c : garbage[i]) {
                distance[c] = cur_dis;
            }
        }
        for (auto& [k, v] : distance) {
            res += v;
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

