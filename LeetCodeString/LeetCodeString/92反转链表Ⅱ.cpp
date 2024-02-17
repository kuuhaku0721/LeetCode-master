#include <iostream>
#include <string>
using namespace std;

/*
* 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
* 行吧，是我小看你了，这题原来有这么难的吗........
* 用头插法
* 现阶段，解决了一部分问题，仅限于长度足够的时候能够正常运行，长度太短，比如1 2 的时候，循环就会出问题
* 改改循环，多加一个虚拟头节点，让循环从0开始，这样就算长度短，开始的pre也能正常记录
* 结束
*/
 
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;
		ListNode* pre;
		ListNode* lef;
		ListNode* end;
		ListNode* res = dummyNode;  //保存最终结果
		for (int i = 0; i <= right; i++)
		{
			if (i == left - 1)
				pre = dummyNode;
			if (i == left)
				lef = dummyNode;
			dummyNode = dummyNode->next;
		}
		end = dummyNode; //全部循环完毕，head位置就是righ后一个

		ListNode* mid = lef->next;
		while (mid != end)
		{
			lef->next = mid->next;
			mid->next = pre->next;
			pre->next = mid;
			mid = lef->next;
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

