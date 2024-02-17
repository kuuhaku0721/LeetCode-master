#include <iostream>
#include <string>
using namespace std;

/*
* 给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为高度平衡的二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过 1。
*/


/*
* 说实话，这个没看懂，只是找了一个答案对着抄抄改改，所以，如果我后来又回来看到这里了，记得多看看多做做多理解理解
* 看看答案的分治的写法
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
  
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, NULL);
	}

    TreeNode* helper(ListNode* left, ListNode* right)
    {
        if (left == right)
            return NULL;
        ListNode* fast = left;
        ListNode* slow = left;

        while (fast != right && fast->next != right)
        {   //快慢指针，快指针每次移动两格，慢指针每次一格 这样快指针到尾的时候，慢指针刚好在根
            fast = fast->next->next; 
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = helper(left, slow);
        root->right = helper(slow->next, right);
        return root;
    }
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

