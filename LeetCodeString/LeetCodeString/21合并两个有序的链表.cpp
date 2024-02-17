#include <iostream>
#include <string>
using namespace std;

/*
* 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
* 懒了 cv
*/
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;

        ListNode* ResList = (list1->val >= list2->val) ? list2 : list1;     //结果链表
        ListNode* LastL1 = nullptr;     //上一个list1

        for (ListNode* i = list1; i != nullptr;)//i为当前list1
        {
            if (list2 == nullptr) break;     //list2已经全部插入了，跳出

            if (list2->val <= i->val)       //如果List2小于等于List1就插入
            {
                ListNode* L2Temp = list2;   //备份"要插入的数据"
                list2 = list2->next;        //list2更新向后
                L2Temp->next = i;           //"要插入的数据"指向当前的List1
                if (LastL1 != nullptr) LastL1->next = L2Temp;        //List1的上一个数据指向"要插入的数据"
                LastL1 = L2Temp;            //当前List的上一个数据更新为"插入的数据"
            }
            else if (i->next == nullptr)     //List1遍历完了但是List2还没完，剩下的在List1后面接上
            {
                i->next = list2;
                break;
            }
            else
            {
                LastL1 = i;     //更新List1的上一个数据为List1
                i = i->next;      //更新List1为下一个数据
            }
        }

        return ResList;
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

