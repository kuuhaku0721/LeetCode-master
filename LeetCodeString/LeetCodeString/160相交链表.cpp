#include <iostream>
#include <string>
using namespace std;

/*
* 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* a = headA;
		ListNode* b = headB;
		int lena = 0, lenb = 0;
		while (a != NULL)
		{
			++lena;
			a = a->next;
		}
		while (b != NULL)
		{
			++lenb;
			b = b->next;
		}
		if (lena > lenb)
		{
			for (int i = 0; i < lena - lenb; i++)
			{
				headA = headA->next;
			}
		}
		else
		{
			for (int i = 0; i < lenb - lena; i++)
			{
				headB = headB->next;
			}
		}
		while (headA == headB)
		{
			headA = headA->next;
			headB = headB->next;
		}
		return headA;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

