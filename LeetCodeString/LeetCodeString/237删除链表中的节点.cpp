#include <iostream>
#include <string>
using namespace std;

/*
* 有一个单链表的 head，我们想删除它其中的一个节点 node。
给你一个需要删除的节点 node 。你将 无法访问 第一个节点  head。
链表的所有值都是 唯一的，并且保证给定的节点 node 不是链表中的最后一个节点。
删除给定的节点。注意，删除节点并不是指从内存中删除它。这里的意思是：
给定节点的值不应该存在于链表中。
链表中的节点数应该减少 1。
node 前面的所有值顺序相同。
node 后面的所有值顺序相同。
自定义测试：
对于输入，你应该提供整个链表 head 和要给出的节点 node。node 不应该是链表的最后一个节点，而应该是链表中的一个实际节点。
我们将构建链表，并将节点传递给你的函数。
输出将是调用你函数后的整个链表。
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

/*
* 题目的意思，给的是一个链表中的一个节点，要求删除链表中这个节点
* 没法访问节点头，也就是要在不知道链表是何的时候，找到当前节点的前驱和后继
* 个屁啊
* 如何让自己杀死自己？先让自己变成另外一个人，然后杀掉那个人，那"自己"不久没了？
* woc，评论区真实个个都是人才
*/

class Solution {
public:
	void deleteNode(ListNode* node) {
		int t = node->next->val;   //先窃取他人身份
		node->next = node->next->next; //然后干掉那个人
		node->val = t; //最后自己成为那个人
		//完成
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

