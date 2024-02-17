#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

/*
* 你在和朋友一起玩 猜数字（Bulls and Cows）游戏，该游戏规则如下：
写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下述信息的提示：
猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls"，公牛），
有多少位属于数字猜对了但是位置不对（称为 "Cows"，奶牛）。也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。
给你一个秘密数字 secret 和朋友猜测的数字 guess ，请你返回对朋友这次猜测的提示。
提示的格式为 "xAyB" ，x 是公牛个数， y 是奶牛个数，A 表示公牛，B 表示奶牛。
请注意秘密数字和朋友猜测的数字都可能含有重复数字。
*/

//仅仅根据题目来看，数字对位置对 A++，数字对位置不对B++
//但是难点在于有重复的
//数字对位置对的A比较简单，可以一个个比对
//问题是数字对位置不对的，虽然可以find，但是find应付不了重复的情况


//不对，比对的早了，如果是1122 | 1222的情况 虽然第二个数不对位置能对上，但是后面的两个都能对上所以其实它不能算数
//可以试试，先把对不上的下标记录下来，然后把全部的先遍历一遍，遍历完能对上的之后，单独比对对不上的
//位置不对，需要检查数字对不对
//可以把secret全装进一个map中，然后通过遍历guess在map中查找，找到了就计数-1，找不到就继续循环,如果计数是0也继续循环

class Solution {
public:
	string getHint(string secret, string guess) {
		int length = min(secret.size(), guess.size());
		map<char, int> mc;
		vector<char> vec;
		for (char c : secret)
		{
			mc[c]++;
		}
		int A = 0, B = 0;
		for (int i = 0; i < length; i++)
		{
			if (secret[i] == guess[i]) //位置对数字对
			{
				A++;
				mc[secret[i]]--;
			}
			else 
			{    
				vec.push_back(guess[i]); //不对的话先保存
			}
		}
		for (char c : vec)
		{
			if (mc[c] == 0 || mc[c] == NULL)
			{
				continue;
			}
			else
			{
				B++;
				mc[c]--;
			}
		}


		string res = to_string(A) + "A" + to_string(B) + "B";

		return res;
	}
};


int main()
{
	cout << "hello world" << endl;
	string secret = "1122";
	string guess = "1222";
	string res = Solution().getHint(secret, guess);
	cout << res << endl;

	/*map<char, int> mc;
	for (char c : secret)
		mc[c]++;

	for (auto it = mc.begin(); it != mc.end(); it++)
	{
		cout << it->first << "-->" << it->second << endl;
	}
	char t = '9';
	cout << mc[t] << endl;
	if (mc[t] == NULL)
		cout << "NULL" << endl;*/

	system("pause");
	return 0;
}

