#include <iostream>
#include <string>
using namespace std;

/*
* 给你二叉树的根结点 root ，请你将它展开为一个单链表：
* 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
* 展开后的单链表应该与二叉树 先序遍历 顺序相同。
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
/*
* 进阶版要求O(1)
* 也就是说可以额外开辟空间
* 先按照额外用空间的方式写吧
* 很好，不行，那就想办法原地换吧
*/

class Solution {
public:
    TreeNode* tail = nullptr;
	void flatten(TreeNode* root) {
        if (root == nullptr)
            return;

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;

        tail = root;

        flatten(root->right);
        tail->right = temp;
        flatten(temp);
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

