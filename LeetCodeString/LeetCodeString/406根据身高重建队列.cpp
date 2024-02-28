#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
* 每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
* 请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，
* 其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
*/

/*
* 题目的意思大致换个说法：以ki为基准，它表示的是前面有几个人，ki大致以递增顺序进行
* hi表示的身高，它决定了ki的值
* 局部最优推导全局最优，局部最优推导全局最优
* 多念几遍，总能想起来办法的（想不出来就cv）
* 自己推导是能推导出来的，就看怎么具现化出来代码了
* 
* 两遍循环，第一遍先把ki按照它应该在的位置排好
* 第二遍循环再去单独细调每一个位置
* 第一遍循环的时候，用插入的方法，如果它将要插入的地方存在跟它ki相等的数，那就比大小往后循环
* 
* 好吧，还是想的不对
* 先按身高排序，排序完找个新的数组一个个插入
* 
* 挺好，学了一个sort的lambda表达式写法
*/

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), [](vector<int>& lp, vector<int>& rp) {
			//	    身高相等 比较次序，升序排列		身高不等 比较升高，降序排序
			return lp[0] == rp[0] ? lp[1] < rp[1] : lp[0] > rp[0];
			});
		vector<vector<int>> res;
		int len = people.size();
		for (int i = 0; i < len; i++)
			res.insert(res.begin() + people[i][1], people[i]);
		return res;
	}
};


int main()
{
	cout << "hello world" << endl;
	vector<vector<int>> people{
		{7,0},
		{4,4},
		{7,1},
		{5,0},
		{6,1},
		{5,2}
	};
	auto res = Solution().reconstructQueue(people);

	system("pause");
	return 0;
}

