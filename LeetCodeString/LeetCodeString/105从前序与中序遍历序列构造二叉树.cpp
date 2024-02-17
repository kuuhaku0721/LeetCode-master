#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，
* 请构造二叉树并返回其根节点。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
// 做法和106的一样，多写多练，总能搞会的
// 106和105两道题都中规中矩的，虽然不是最佳，但起码学会个新解法，不错了，不错了
class Solution {
public:
    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.size() == 0) return NULL;

        // 先构造根节点
        TreeNode* root = new TreeNode;
        root->val = preorder[0];

        // 返回叶子节点
        if (preorder.size() == 1) return root;

        // 找到根节点在中序数组中的位置
        auto in_index = find(inorder.begin(), inorder.end(), root->val);

        // 分割中序遍历的左右子树
        vector<int> leftInOrder(inorder.begin(), in_index);
        vector<int> rightInOrder(in_index + 1, inorder.end());
        // 分割前序遍历的左右子树
        preorder.erase(preorder.begin());
        vector<int> leftPreOrder(preorder.begin(), preorder.begin() + leftInOrder.size());
        vector<int> rightPreOrder(preorder.begin() + leftInOrder.size(), preorder.end());
        
        // 递归构造
        root->left = buildHelper(leftPreOrder, leftInOrder);
        root->right = buildHelper(rightPreOrder, rightInOrder);

        return root;
    }

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        return buildHelper(preorder, inorder);
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

