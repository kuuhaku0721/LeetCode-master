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
	ListNode* newHead;
	ListNode* reverseList(ListNode* head) {
		Reverse(nullptr, head);
		return newHead;
	}

	void Reverse(ListNode* prev, ListNode* curr)
	{
		if (curr == nullptr)
		{
			newHead = prev;
			return;
		}
		
		Reverse(curr, curr->next);
		curr->next = prev;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

