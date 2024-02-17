#include <iostream>
#include <string>
using namespace std;

/*
* 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
图示两个链表在节点 c1 开始相交：
题目数据 保证 整个链式结构中不存在环。
注意，函数返回结果后，链表必须 保持其原始结构 。
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (headA == NULL || headB == NULL)
			return NULL;

		//先记录两个链表的长度
		int lenA = 0, lenB = 0;
		ListNode* rootA = headA;
		ListNode* rootB = headB;
		while (rootA->next != NULL)
		{
			lenA++;
			rootA = rootA->next;
		}
		lenA++;
			
		while (rootB->next != NULL)
		{
			lenB++;
			rootB = rootB->next;
		}
		lenB++;
		if (rootA->val != rootB->val)
			return NULL;

		//如果相等，用大的长度减去小的长度，差值 可以用作判断 具体判断，等会再说
		ListNode* longOne;
		ListNode* shortOne;
		if (lenA >= lenB)
		{
			longOne = headA;
			shortOne = headB;
		}
		else
		{
			longOne = headB;
			shortOne = headA;
		}
		for (int i = 0; i < abs(lenA - lenB); i++)
		{
			longOne = longOne->next;
		}

		while (longOne != shortOne)
		{
			longOne = longOne->next;
			shortOne = shortOne->next;
		}
		return longOne;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

