#include <iostream>
#include <string>
using namespace std;

/*
* 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
/*
* k值可以非常大，所有先算链表长度，然后让k值取模，剩下的就是真正需要移动的格数
*/
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL) return head;
		ListNode* ori = head;
		int len = 0;
		while (ori->next != NULL)
		{
			len++;
			ori = ori->next;
		}
		len++; //把跳出循环的最后一个补上
		k = k % len;

		//有了链表长度，有了真正的k值，可以计算移动了
		ori->next = head;
		for (int i = 1; i < len - k; i++)
		{
			head = head->next;
		}
		ListNode* tmp = head;
		head = head->next;
		tmp->next = NULL;
		return head;
	}
};



int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

