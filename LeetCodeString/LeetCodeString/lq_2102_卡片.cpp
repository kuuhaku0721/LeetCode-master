#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
* 0到9的卡片各2021张，共20210张，请问小蓝可以从1拼到多少?
* 
* 求数量的，那好说，直接映射表算数就行了
*/

int CardNumber()
{
	unordered_map<char, int> umap;
	umap.insert(make_pair('0', 2021));
	umap.insert(make_pair('1', 2021));
	umap.insert(make_pair('2', 2021));
	umap.insert(make_pair('3', 2021));
	umap.insert(make_pair('4', 2021));
	umap.insert(make_pair('5', 2021));
	umap.insert(make_pair('6', 2021));
	umap.insert(make_pair('7', 2021));
	umap.insert(make_pair('8', 2021));
	umap.insert(make_pair('9', 2021));
	while (true)
	{
		for (int i = 1; i < INT_MAX; ++i)
		{
			string s = to_string(i);
			for (char c : s)
			{
				if (umap[c] != 0)
					--umap[c];
				else
					return i - 1;
			}
		}
	}
	return 0;
}

int main()
{
	cout << CardNumber() << endl;

	system("pause");
	return 0;
}

