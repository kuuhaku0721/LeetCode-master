#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
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
	vector<int> postorderTraversal(TreeNode* root) {
        if (root)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            result.push_back(root->val);
        }
        return result;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

