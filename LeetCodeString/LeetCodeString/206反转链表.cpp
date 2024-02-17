#include <iostream>
#include <string>
using namespace std;

/*
* 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
* 双指针，一个跟着链表走，一个负责记录上一个位置，然后将它的netx指向上一个
*/
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) return NULL;
		ListNode* pre = NULL;
		while (head != NULL)
		{
			ListNode* p = head->next;
			head->next = pre;
			pre = head;
			head = p;
		}
		return pre;
	}
};



int main()
{
	cout << "hello world" << endl;
	int arr[5] = { 1,2,3,4,5 };
	ListNode* head = new ListNode();
	ListNode* mark = new ListNode();
	mark = head;
	head->val = arr[0];
	for (int i = 1; i < 5; i++)
	{
		ListNode* p = new ListNode();
		p->val = arr[i];
		head->next = p;
		head = p;
	}
	head->next = NULL;
	head = Solution().reverseList(mark);
	while (head->next != NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}

	system("pause");
	return 0;
}

