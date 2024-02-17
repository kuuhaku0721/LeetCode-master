#include <iostream>
#include <string>
using namespace std;

/*
* 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
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
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return head;
		
		ListNode* pre = new ListNode(-1);
		pre->next = head;
		ListNode* res = pre;
		
		while (head != NULL && head->next != NULL)
		{
			ListNode* tmp = head->next;
			head->next = head->next->next;
			tmp->next = head;
			pre->next = tmp;
			pre = head;
			head = head->next;
		}
		return res->next;
	}
};




int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

