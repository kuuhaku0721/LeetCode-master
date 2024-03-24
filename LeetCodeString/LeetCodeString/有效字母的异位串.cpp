#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() < t.size())
		{
			string temp = t;
			t = s;
			s = temp;
		}
		unordered_map<char, int> umapS;
		for (char c : s)
			umapS[c]++;
		for (char c : t)
		{
			if (umapS[c] != NULL)
				umapS[c]--;
		}
		for (auto pr : umapS)
			if (pr.second != 0)
				return false;
		return true;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

