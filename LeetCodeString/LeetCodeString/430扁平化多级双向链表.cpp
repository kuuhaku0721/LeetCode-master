#include <iostream>
#include <string>
using namespace std;

/*
* 你会得到一个双链表，其中包含的节点有一个下一个指针、一个前一个指针和一个额外的 子指针 。这个子指针可能指向一个单独的双向链表
也包含这些特殊的节点。这些子列表可以有一个或多个自己的子列表，以此类推，以生成如下面的示例所示的 多层数据结构 。
给定链表的头节点 head ，将链表 扁平化 ，以便所有节点都出现在单层双链表中。让 curr 是一个带有子列表的节点。
子列表中的节点应该出现在扁平化列表中的 curr 之后 和 curr.next 之前 。
返回 扁平列表的 head 。列表中的节点必须将其 所有 子指针设置为 null 。
*/


// Definition for a Node.
class Node {
public:
    Node() {}
    Node(int v)
    {
        val = v;
    }
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

/*
* 递归 func
* while(->next != NULL)
* x += node;
* if(x->child != NULL) 递归func(x, ->child)
* =  ->next
* 注意这是个双向链表，所以除了next需要维护以外，prev也要维护
* 
* 这样搞 如果它的child不等于空，就专门弄一个函数，拿到当前这一层整个链表，参数传入两个节点
* 两个节点分别代表链表头和链表尾  不行啊 还是得递归
* 
* 还是考虑递归的写法吧
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* res = head;
        while (head != NULL)
        {
            if (head->child != NULL)
            {
                Node* tmp = head->next;
                Node* beg = new Node();
                Node* end = new Node();
                getFloorList(head->child, beg, end);
                head->child = NULL;
                head->next = beg; beg->prev = head;
                if (tmp == NULL)
                    end->next = NULL;
                else
                {
                    end->next = tmp; tmp->prev = end;
                }
            }
            head = head->next;
        }
        return res;
    }

    void getFloorList(Node* head, Node*& beg, Node*& end)
    {
        beg = head;
        while (head->next != NULL)
        {
            head = head->next;
        }
        end = head;
    }
};

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);
    Node* node10 = new Node(10);
    Node* node11 = new Node(11);
    Node* node12 = new Node(12);

    node1->next = node2; node2->prev = node1;
    node2->next = node3; node3->prev = node2;
    node3->next = node4; node4->prev = node3;
    node4->next = node5; node5->prev = node4;
    node5->next = node6; node6->prev = node5;
    node6->next = NULL;
    node3->child = node7;
    node7->next = node8; node8->prev = node7;
    node8->next = node9; node9->prev = node8;
    node9->next = node10; node10->prev = node9;
    node10->next = NULL;
    node8->child = node11;
    node11->next = node12; node12->prev = node11;
    node12->next = NULL;

    Node* res = Solution().flatten(node1);
    

	system("pause");
	return 0;
}

