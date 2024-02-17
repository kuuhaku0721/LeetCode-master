#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
* 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
*/

/*
* 从给的字符数组第一个开始遍历，拿第一个为基准，在结果数组里面找是否有对应的同素异形体
* 如果有，跟在它的数组的后面，如果没有，那就以它为首字母再开一个数组
* 需要有一个比对同素异形体的函数
*/
/*
* 我在此郑重宣布，这题做出来了，但是如果字符串规模极大，那就莫得办法了，测试用例能到10w....
* 辛辛苦苦一小时，一交结果就超时
*/

class Solution {
public:

	/*官方题解*/
	/*
	* 答案的思路：用一个map映射表，从strs里面拿字符串，然后给它排序，排序完的结果当作key，把当前这个字符串当作value
	* 每过来一个str字符串都先排序，然后排序结果的key到map里去比对，如果存在就在它后面追加str本身(key是一个临时变量)
	* 如果不存在的话，map[key]会自动添加这么一个键值对进去
	* 全部处理完之后map的所有value就是要的最终结果，转到结果的vector里就行了
	*/
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> mp;
		for (string& str : strs) {
			string key = str;
			sort(key.begin(), key.end());
			mp[key].emplace_back(str);
		}
		vector<vector<string>> ans;
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			ans.emplace_back(it->second);
		}
		return ans;
	}



	vector<vector<string>> groupAnagrams2(vector<string>& strs) {
		vector<vector<string>> vec;
		
		vector<string> temp;
		temp.push_back(strs[0]);
		vec.push_back(temp);
		temp.clear();

		for (auto it = strs.begin() + 1; it != strs.end(); it++)
		{
			int i{};
			for (i = 0; i < vec.size(); i++)
			{
				if (isSame(*it, vec[i][0]))
				{
					vec[i].push_back(*it); //比对成功就直接退出
					break;
				}
			}
			//上面的全比对完还没有找到，那就说明里面没有，那就插入一个
			if (i == vec.size())
			{
				vector<string> newone;
				newone.push_back(*it);
				vec.push_back(newone);
			}
		}

		return vec;
	}

	bool isSame(string s, string t)
	{
		//首先得长度一样，不一样直接返回false
		//遍历s，在t中查找s的每一个字符，如果有一个找不到就返回false
		//如果都能找到返回true
		if (s.size() != t.size())
		{
			return false;
		}
		else
		{ //找到一个置空一个，最后看是不是全空
			for (char c : s)
			{
				int index = t.find(c);
				if (index == -1)
					return false;
				else
				{
					t[index] = '0';
				}
			}
		}
		string temp;
		temp.assign(t.size(), '0');
		if (t == temp)
			return true;
		else
			return false;
	}
};


int main()
{
	cout << "hello world" << endl;

	vector<string> strs;
	strs.push_back("ddddddddddg");
	strs.push_back("dgggggggggg");
	//strs.push_back("tan");
	//strs.push_back("ate");
	//strs.push_back("nat");
	//strs.push_back("bat");
	vector<vector<string>> vec = Solution().groupAnagrams(strs);
	cout << "result: " << endl;

	for (int i = 0; i < vec.size(); i++)
	{
		for (auto it = vec[i].begin(); it != vec[i].end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	
	


	system("pause");
	return 0;
}

