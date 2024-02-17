#include <iostream>
#include <string>
#include <set>
using namespace std;


/*
* 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置
（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
不允许修改 链表。
*/

/*
* 用set，保留，查询，直接就过了，但是时间空间都是个位数
* 所以，等于没过
* 
* 
* 题解用的快慢指针
* 但是，管你啥指针
* 哈希就完事了
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == NULL) return NULL;
		set<ListNode*> node_set;
		while (head != NULL)
		{
			node_set.insert(head);
			head = head->next;
			if (node_set.find(head) != node_set.end())
			{
				return head;
			}
		}
		return NULL;
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

