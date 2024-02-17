#include <iostream>
#include <string>
using namespace std;

/*
* 你可以选择使用单链表或者双链表，设计并实现自己的链表。
单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。
实现 MyLinkedList 类：
MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
*/

/*
* 完事，单纯链表操作，不算难
* 主要简单的地方在于，它错了，有输出啊.....
*/
class MyLinkedList {
public:
    struct Node
    {
        int val;
        Node* next;
        Node() { val = -1; next = NULL; }
        Node(int value) { val = value; next = NULL; }
    };

    Node* m_list;
    int len = 0;

    MyLinkedList() {
        m_list = new Node();
        len = 0;
    }

    int get(int index) {
        if (index >= len)
            return -1;
        int i = 0;
        Node* head = m_list->next;
        while (head != NULL)
        {
            if (i == index)
                return head->val;
            i++;
            head = head->next;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = m_list->next;
        m_list->next = node;
        len++;
    }

    void addAtTail(int val) {
        Node* node = m_list;
        while (node->next != NULL)
            node = node->next;
        Node* newOne = new Node(val);
        node->next = newOne;
        newOne->next = NULL;
        len++;
    }

    void addAtIndex(int index, int val) {
        if (index > len) return;
        Node* head = m_list;
        int i = 0;
        while (head != NULL)
        {
            if (i == index)
                break;
            head = head->next;
            i++;
        }
        Node* newOne = new Node(val);
        newOne->next = head->next;
        head->next = newOne;
        len++;
    }

    void deleteAtIndex(int index) {
        if (index >= len) return;
        Node* head = m_list;
        int i = 0;
        while (head != NULL)
        {
            if (i == index)
                break;
            head = head->next;
            i++;
        }
        head->next = head->next->next;
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

