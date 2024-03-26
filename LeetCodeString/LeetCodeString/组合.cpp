#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
	vector<vector<int>> result;
	vector<int> path;
	vector<vector<int>> combine(int n, int k) {
		BackTracking(n, k, 0);
		return result;
	}

	void BackTracking(int n, int k, int idx)
	{
		if (path.size() == k)
		{
			result.push_back(path);
			return;
		}

		for (int i = idx + 1; i <= n; i++)
		{
			path.push_back(i);
			BackTracking(n, k, i);
			path.pop_back();
		}
	}
};

int main()
{
	cout << "hello world" << endl;
	

	system("pause");
	return 0;
}

