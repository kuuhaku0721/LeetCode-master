#include <iostream>
#include <cmath>
using namespace std;

/*
* 给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
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
* 方法：只要根节点不为空，递归判断根节点的左右子树的最大深度
* 然后求绝对值，如果绝对值一直小于等于1 那就返回true
* 如果有一个大于1 那就返回false
* 
* 牛B，一次过
*/
 
class Solution {
public:
	bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int dep1 = maxDepth(root->left);
        int dep2 = maxDepth(root->right);

        return abs(dep1 - dep2) <= 1 ? isBalanced(root->left) && isBalanced(root->right) : false;
	}

    int maxDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        else
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};




int main()
{
    cout << "hello world" << endl;



	system("pause");
	return 0;
}