#include <iostream>
#include <string>
using namespace std;

/*
* 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
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
* 二叉搜索树，很明显，递归遍历，如果小于，找左子树，如果大于，找右子树
* 如果等于，返回
*/

class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL)
            return NULL;
        if (root->val == val)
            return root;
        else if (root->val < val)
            return searchBST(root->right, val);
        else
            return searchBST(root->left, val);
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

