#include <iostream>
#include <string>
using namespace std;

/*
* 给定一个二叉树 root ，返回其最大深度
二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
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
* 很单纯的，求二叉树深度，的递归算法
*/
class Solution {
public:
	int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        else
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        //一行代码搞定的事情干嘛非得多几行呢
        /*{
            int l = maxDepth(root->left);
            int r = maxDepth(root->right);
            if (l > r)
                return l + 1;
            else
                return r + 1;
        }*/
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

