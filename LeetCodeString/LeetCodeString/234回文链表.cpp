#include <iostream>
#include <string>
using namespace std;

/*
* 给你一个单链表的头节点 head ，请你判断该链表是否为 回文链表
* 如果是，返回 true ；否则，返回 false 。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
/*
* 能想到的就是保存下来判断回文串
* 暂时想不起来一边遍历一边判断的做法，待会看看答案
* 很好，大家都差不多的思路
*/

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		string s = "";
		while (head != NULL)
		{
			s += to_string(head->val);
			head = head->next;
		}
		bool flag = true;
		if (s.size() % 2 == 0)
		{
			int len = s.size() / 2;
			for (int i = 0, j = s.size() - 1; i < len, j >= len; ++i, --j)
			{
				if (s[i] != s[j])
				{
					flag = false;
					break;
				}
			}
		}
		else
		{
			int len = s.size() / 2;
			for (int i = 0, j = s.size() - 1; i < len, j > len; ++i, --j)
			{
				if (s[i] != s[j])
				{
					flag = false;
					break;
				}
			}
		}
		return flag;
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

