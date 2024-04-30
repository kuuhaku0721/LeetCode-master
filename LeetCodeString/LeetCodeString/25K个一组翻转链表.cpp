#include <iostream>
#include <string>
using namespace std;

/*
* 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
* k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
* 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
/*
* 简单概括一下题意就是：
* 每计数够K个，就截取下来，找个func去翻转，然后再拼接回来
* 省事起见，返回的时候可以尝试把头尾都返回，这样可以紧跟着尾巴继续向后遍历统计
* 找到难点在哪了，难点是翻转完之后，怎么获取到翻转完的链表，因为原本的链表翻转是带NULL值的，可以根据，也就是整个翻转，而且结尾不需要
* 但是如果首尾都有用的话，就不能简单的一个递归结束了
*/
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {

	}

	// TODO: 打断了一下，想不出来了，换个题做，待会再回来这个


	// 先写法翻转链表的函数出来吧
	void ReverseList(ListNode* beg, ListNode* end, ListNode* prev, ListNode* curr)
	{
		if (curr->next == end)
		{
			end->next = curr;
			// return end;
			return;
		}
		
		ReverseList(beg, end, curr, curr->next);
		curr->next = prev;
	}
};

int main()
{
	cout << "hello world" << endl;
	ListNode* lst = new ListNode(1);
	ListNode* head = lst;
	for (int i = 2; i <= 5; i++)
	{
		ListNode* curr = new ListNode(i);
		lst->next = curr;
		lst = lst->next;
	}
	cout << "prev: " << endl;
	ListNode* tmp = head;
	while (tmp != nullptr)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
	Solution().ReverseList(head, lst, NULL, head);
	auto res = lst;
	cout << "last: " << endl;
	if (res != nullptr)
	{
		while (res != nullptr)
		{
			cout << res->val << " ";
			res = res->next;
		}
	}

	system("pause");
	return 0;
}

