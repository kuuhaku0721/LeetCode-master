#include <iostream>
#include <string>
using namespace std;

/*
* 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 
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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* res = head;
		while (head->next != NULL)
		{
			if (head->val == head->next->val)
			{
				head->next = head->next->next;
			}

			head = head->next;
		}
		return res;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

