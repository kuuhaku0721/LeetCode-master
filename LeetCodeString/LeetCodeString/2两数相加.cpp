#include <iostream>
#include <string>
using namespace std;

/*
* 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		string num1 = "";
		while (l1 != NULL)
		{
			num1 += to_string(l1->val);
			l1 = l1->next;
		}
		string num2 = "";
		while (l2 != NULL)
		{
			num2 += to_string(l2->val);
			l2 = l2->next;
		}
		cout << "num1 = " << num1 << endl << "num2 = " << num2 << endl;

		string num = "";
		int carry = 0;
		for (int i = 0; i < min(num1.size(), num2.size()); i++)
		{
			int t = (num1[i] - '0') + (num2[i] - '0');
			if (carry)
			{
				t += carry;
				carry = 0;
			}
			if (t >= 10)
			{
				num += to_string(t % 10);
				carry = t / 10;
			}
			else
			{
				num += to_string(t);
			}
		}
		string remain = num1.size() > num2.size() ? num1 : num2;
		cout << "remain = " << remain << endl;
		for (int i = min(num1.size(), num2.size()); i < remain.size(); i++)
		{
			int t = remain[i] - '0';
			if (carry)
			{
				t += carry;
				carry = 0;
			}
			if (t >= 10)
			{
				num += to_string(t % 10);
				carry = t / 10;
			}
			else
			{
				num += to_string(t);
			}
		}
		if (carry) num += "1";
		cout << "result num = " << num << endl;

		ListNode* lr = new ListNode(0);
		if (num == "0") return lr;
		ListNode* res = lr;
		for (int i = 0; i < num.size(); i++)
		{
			ListNode* t = new ListNode(num[i] - '0');
			lr->next = t;
			lr = lr->next;
		}

		return res->next;
	}
};


int main()
{
	cout << "hello world" << endl;
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(9);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	l2->next->next->next = new ListNode(9);

	ListNode* res = Solution().addTwoNumbers(l1, l2);
	while (res != NULL)
	{
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;


	system("pause");
	return 0;
}

