#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
*/


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
    vector<int> result;

	vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return result;
	}

    void preOrder(TreeNode* root)
    {
        if (root == NULL)
            return;

        result.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

