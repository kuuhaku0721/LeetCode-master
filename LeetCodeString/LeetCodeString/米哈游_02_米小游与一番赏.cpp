#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// 一个队列的模拟外加对map的使用，也不难，很好很好，第三题难它难去，大不了不做
// 能写出来两题，很不错了

void Eiji()
{
	vector<string> vec;
	map<string, int> mp;
	int total, minNum, q;
	cin >> total >> minNum >> q;
	for (int i = 0; i < q; i++)
	{
		if (total <= 0) continue;
		int cmd;
		cin >> cmd;
		string name;
		int cnt;
		switch(cmd)
		{
		case 1:
			cin >> name;
			vec.emplace_back(name);
			mp.insert(make_pair(name, 0));
			break;
		case 2:
			cin >> name;
			vec.erase(find(vec.begin(), vec.end(), name));
			break;
		case 3:
			cin >> cnt;
			total -= cnt;
			mp[vec[0]] += cnt;
			break;
		case 4:
			cout << vec.size() << endl;
			break;
		}
		if (total <= minNum)
		{
			mp[vec[0]] += total;
			total -= minNum;
		}
	}
	for (auto pair : mp)
	{
		cout << pair.first << " " << pair.second << endl;
	}
}



int main()
{
	Eiji();

	system("pause");
	return 0;
}

