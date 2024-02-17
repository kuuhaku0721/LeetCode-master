#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示
*/

/*
* 感觉难点在于，12:00和 00:00的区分，以及转换成分钟数
* 那就试试，从vector中拿出来数之后，用if判断它是不是00:00,如果是的话，需要分两种情况 一种是24:00,一种是00:00
* 如果不是，那就只有一种情况
* 再写一个函数用来将string转换为int
* 要找的是最小时间差，那先给它排个序不就好了？
* 排序之后只需要比对相邻两个之间的时间差就行了，最后一个和第一个相邻，用环..可能不行，环的话循环退出条件不好解决，那就手动判断
* 单独用一个容器来保存相邻之间的比对结果
*/

class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		int res = 1440;
		sort(timePoints.begin(), timePoints.end());
		for (int i = 0; i < timePoints.size(); i++)
		{
			int left = strToInt(timePoints[(i + timePoints.size()) % timePoints.size()]);
			int right = strToInt(timePoints[(i + 1 + timePoints.size()) % timePoints.size()]);
			if (i == timePoints.size() - 1)
			{ //最后一个减第一个的时候得特殊处理
				right += 24 * 60; //再加一圈
			}
			if (right - left < 0)
				res = min(res, left - right);
			else
				res = min(res, right - left);
			cout << timePoints[(i + 1 + timePoints.size()) % timePoints.size()] << " - " << timePoints[(i + timePoints.size()) % timePoints.size()] << " = " << (right - left) << endl;
		}

		return res;
	}

	int strToInt(string s)
	{
		int res = 0;
		int index = s.find(':');
		string t = s.substr(0, index);
		res += atoi(t.c_str()) * 60;
		t = s.substr(index + 1, s.size() - index - 1);
		res += atoi(t.c_str());
		return res;
	}
};



int main()
{
	cout << "hello world" << endl;
	vector<string> vec;
	vec.push_back("05:31");
	vec.push_back("22:08");
	vec.push_back("00:35");
	/*vec.push_back("14:58");
	vec.push_back("20:07");
	vec.push_back("17:09");
	vec.push_back("08:25");*/
	int time = Solution().findMinDifference(vec);
	cout << time << endl;
	

	system("pause");
	return 0;
}

