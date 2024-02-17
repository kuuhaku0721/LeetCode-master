#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
* 给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
提醒一下，二叉搜索树满足下列约束条件：
节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
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
* 右 根 左 的顺序遍历
* 遍历到每一个就把它的值加上上一个节点的值
* 然后重新赋值
* 然后递归
*/
 
class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        inOrderTraverse(sum, root);
        return root;
	}

    void inOrderTraverse(int& sum, TreeNode* root)
    {
        if (root == NULL)
            return;

        inOrderTraverse(sum, root->right);
        sum += root->val;
        root->val = sum;
        inOrderTraverse(sum, root->left);
    }
};



int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

