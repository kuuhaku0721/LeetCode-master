#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
/*
* 其实完全可以转存，排序，然后置换
* 但是题目下面有个进阶要求常数级别的空间，所以就得原地置换了
* 链表级别的...冒泡？试试吧，不行我就直接转存
* 这也能超时啊........
* 很好，摘出来重建吧，简单高效还好用
* 代码查重率100%，很好，大家都是一样的想法
*/

class Solution {
public:
	ListNode* sortList1(ListNode* head) {
		if (head == NULL) return NULL;
		int len = 0;
		ListNode* root = head;
		while (root != NULL)
		{
			len++;
			root = root->next;
		}
		for (int i = 0; i < len; i++)
		{
			root = head;
			while (root->next != NULL)
			{
				if (root->val > root->next->val)
				{
					int tmp = root->val;
					root->val = root->next->val;
					root->next->val = tmp;
				}
				root = root->next;
			}
		}
		return head;
	}
	ListNode* sortList(ListNode* head) {
		if (head == NULL) return NULL;
		vector<int> vec;
		ListNode* root = head;
		while (root != NULL)
		{
			vec.push_back(root->val);
			root = root->next;
		}
		sort(vec.begin(), vec.end());
		root = head;
		int i = 0;
		while (root != NULL)
		{
			root->val = vec[i];
			root = root->next;
			++i;
		}
		return head;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

