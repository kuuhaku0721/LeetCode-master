#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
* 样例输入
* 5 3
* 1 4 2 8 7
* 
* 样例输出
* 17 7
* 
* 样例说明
* 数列变化如下，中括号里的数是当次操作中被选择的数：
* 
* [1] 4 2 8 7
* 5 [2] 8 7
* [7] 10 7
* 17 7
*/

/*
* 很好，不出意外的超时，但是能撑到50w量级，也就是只要在50w量级以下，应该都没问题，就这样吧
*/

void DivideInteger()
{
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	vector<int> sorted = nums;
	for (int i = 0; i < k; i++)
	{
		sort(sorted.begin(), sorted.end());
		auto it = find(nums.begin(), nums.end(), sorted[0]);
		auto next = nums.erase(it);
		// 首先，找肯定能找到，但是删除之后返回的是下一个的迭代器，这时就要分情况了
		if (next == nums.end())
		{	// 只加前一个
			*(--next) += sorted[0];
		}
		else if (next == nums.begin())
		{	// 只加后一个
			*next += sorted[0]; // 此时next就是原本数据的后一个
		}
		else
		{	// 相邻的两边都加
			*next += sorted[0];		// 先加后一个  此时next就是原数据的后一个
			*(--next) += sorted[0];	// 然后加前一个
		}
		sorted = nums;
	}

	for (auto i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
}



int main()
{
	cout << "hello world" << endl;
	DivideInteger();

	system("pause");
	return 0;
}

