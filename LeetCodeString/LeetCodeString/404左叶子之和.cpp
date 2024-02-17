#include <iostream>
#include <string>
using namespace std;

/*
* 给定二叉树的根节点 root ，返回所有左叶子之和。
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
* 左叶子是所有遍历顺序为left的叶子，包括右子树的左叶子也是左叶子
* 是叶子，不是左子树....
* 
* 递归的办法 中规中矩，不上不下 起码解决了问题就行
*/
 
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        preOrderTraverse(root, res, false);
        return res;
	}

    void preOrderTraverse(TreeNode* root, int& sum, bool flag)
    {
        if (root == NULL)
            return;

        if (flag) // 确定在左边
        {
            if (root->left == NULL && root->right == NULL) // 确定是叶子
            {
                sum += root->val; // 累加和
            }
        }

        preOrderTraverse(root->left, sum, true);
        preOrderTraverse(root->right, sum, false);
    }
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

