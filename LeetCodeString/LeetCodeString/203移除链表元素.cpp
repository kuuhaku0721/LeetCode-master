#include <iostream>
#include <string>
using namespace std;

/*
* 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* beg = new ListNode();
		beg->next = head;
		ListNode* prev = beg;
		while (prev->next != NULL)
		{
			if (prev->next->val == val)
			{
				prev->next = prev->next->next;
			}
			else
			{
				prev = prev->next;
			}
		}
		return beg->next;
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

