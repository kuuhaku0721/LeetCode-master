#include <iostream>
#include <string>
using namespace std;

/*
* 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
* 删除倒数的，首先想到的就是，第一轮遍历统计数目 第二轮遍历删除
* 但是它是个中等题，所以多半不会让遍历两次
* 要停电力，所以抓紧写完才是真
*/
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL) return head;
		int count = 0;
		ListNode* dummyHead = new ListNode(-1);
		dummyHead->next = head;

		while (head != NULL)
		{
			count++;
			head = head->next;
		}

		if (count == 1 && n == 1)
			return NULL;

		//删除倒数第n个，就是删除正数count-n+1个
		ListNode* dum = dummyHead;
		for (int i = 0; i < count - n; i++)
		{
			dummyHead = dummyHead->next;
		}
		dummyHead->next = dummyHead->next->next;

		return dum->next;
	}
};



int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

