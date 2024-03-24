#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == nullptr) return NULL;
		ListNode* root = new ListNode(-1);
		root->next = head;
		ListNode* res = root;
		while(root->next != nullptr)
		{
			if (root->next->val == val)
			{
				root->next = root->next->next;
			}
			else
				root = root->next;
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

