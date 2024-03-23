#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
* 给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
* 构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
* 新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
* 复制链表中的指针都不应指向原链表中的节点 。
* 例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。
* 返回复制链表的头节点。
* 用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
* val：一个表示 Node.val 的整数。
* random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
* 你的代码 只 接受原链表的头节点 head 作为传入参数。
*/


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
* 失败的地方：想到了哈希表，但是看测试用例觉得哈希表不能存重复值而用例有重复
* 没想到其实可以直接存节点，直接存储节点的映射关系
* 可以用map直接存储，原始链表--拷贝链表 的映射关系
* 先遍历第一遍，保存上所有的节点【第一遍只创建了节点，next和random连接关系都没有创建
* 然后遍历第二遍，找random
* 好欸...虽然抄了答案的想法，但是写通了
*/

class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> umap;
        Node* copy_head = nullptr;
        Node* cur = head;
        while (cur != NULL)
        {
            Node* copy_cur = new Node(cur->val);
            if (copy_head == NULL) copy_head = copy_cur;
            umap[cur] = copy_cur;
            cur = cur->next;
        }
        cur = head; // 复位，准备第二轮循环
        while (cur != NULL)
        {
            auto it = umap.find(cur->next);
            if (it != umap.end())
            {
                umap[cur]->next = it->second;
            }
            it = umap.find(cur->random);
            if (it != umap.end())
            {
                umap[cur]->random = it->second;
            }
        }
        return copy_head;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copyRandomMap;
        Node* cur = head;
        Node* copyhead = nullptr, * copytail = nullptr;
        Node* copycur = nullptr;
        while (cur)
        {
            Node* copy = new Node(cur->val);
            copyRandomMap[cur] = copy;

            if (copytail == nullptr)
            {
                copytail = copyhead = copy;
            }
            else
            {
                copytail->next = copy;
                copytail = copytail->next;
            }
            cur = cur->next;
        }

        cur = head;
        Node* copy = copyhead;
        while (cur)
        {
            if (cur->random == nullptr)
            {
                copy->random = nullptr;
            }
            else
            {
                copy->random = copyRandomMap[cur->random];
            }

            cur = cur->next;
            copy = copy->next;
        }
        return copyhead;;
    }
};




int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

