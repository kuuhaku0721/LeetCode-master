#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
文本的最后一行应为左对齐，且单词之间不插入额外的空格。
注意:
单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
*/

/*
* 从第一个开始遍历，每遍历一个都记录下来它的size，一直遍历到总size大于maxwidth，然后取前面几个组成一个string
* 计算在不大于maxwidth的前提下，还剩几个位置，这几个位置就是空格的数量，然后需要一个vector来记录刚才记录下来的下标
* 这个下标vecor的size -1 就是空挡的位置，拿空格数量除去空档数量 就是每个空档需要有的空格数量
* 记录空格数量需要减去空档数量，剩下的才是可分配的空格数量，因为每个单词之间必定有一个空格
* 然后开始构造字符串，构造完毕向结果vector添加，然后下一轮循环
* 最后一个先不管，最后单独处理最后一行
*/

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		vector<string> temp;
		int sumsize = 0;
		for (int i = 0; i < words.size();)
		{
			sumsize += words[i].size();
			if ((sumsize + temp.size() - 1) < maxWidth)
			{
				temp.push_back(words[i]);
				i++;
			}
			else
			{
				sumsize -= words[i].size();
				int remainlen = maxWidth - sumsize - temp.size() + 1;
				string sumstr = "";
				if (temp.size() == 1)
				{
					sumstr = temp[0];
					for (int i = 0; i < remainlen; i++)
					{
						sumstr += " ";
					}
					res.push_back(sumstr);
					temp.clear();
					sumsize = 0;
					continue;
				}
				else
				{
					for (int i = 0; i < temp.size(); i++)
					{
						sumstr += temp[i];
						if (i == temp.size() - 1)
						{
							break;
						}
						else
							sumstr += " ";
						for (int i = 0; i < remainlen / (temp.size() - 1); i++)
						{
							sumstr += " ";
						}
					}
				}
				if (sumstr.size() < maxWidth)
				{
					for (int i = 0; i < sumstr.size(); i++)
					{
						if (sumstr[i] == ' ')
						{
							sumstr.insert(i, " ");
							if (sumstr.size() == maxWidth)
								break;
							while (sumstr[i] == ' ')
								i++;
						}
					}
				}
				//cout << "-->" << sumstr << endl;
				int idx = sumstr.size() - 1;
				while (sumstr[idx] == ' ')
					idx--;
				sumstr = sumstr.substr(0, idx + 1);
				res.push_back(sumstr);
				temp.clear();
				sumsize = 0;
			}
		}
		//上面的运行完毕之后，最后一行需要的单词还在temp里面存着
		string last = "";
		for (int i = 0; i < temp.size(); i++)
		{
			last += temp[i];
			if (i != temp.size() - 1)
				last += " ";
		}
		while (last.size() < maxWidth)
			last += " ";
		res.push_back(last);

		return res;
	}
};



int main()
{
	cout << "hello world" << endl;
	vector<string> vec = { "The","important","thing","is","not","to","stop","questioning.","Curiosity","has","its","own","reason","for","existing." };
	int maxWidth = 17;
	vector<string> res = Solution().fullJustify(vec, maxWidth);
	cout << "Result: " << endl;
	for (string s : res)
	{
		cout << s << "|" << endl;
	}

	system("pause");
	return 0;
}

