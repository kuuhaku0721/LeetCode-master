#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个二叉树的根节点 root ， 检查它是否轴对称。
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
* 初步判断，应该是递归
* 左孩子的左孩子是否等于右孩子的右孩子
* 中序遍历可以判断
* 但是这么判断会留下一个错误点：如果除了根以外节点值都相等的话，没法正常判断
* 还有个办法，除根以外，左子树：左根右的遍历，右子树：右根左的遍历
* 果然不能保存，还是要一边遍历一边比较，也就是，递归
* 递归用的还是不熟练啊.....
* 用深度优先遍历的方法比较：左子树的左和右子树的右，左子树的右和右子树的左，递归返回值是两个结果相与，只有两边都是true，最终结果才是true
*/
 
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return DFS(root->left, root->right);
	}

    bool DFS(TreeNode* left, TreeNode* right)
    {
        if (left == NULL && right == NULL)
            return true;

        if (left == NULL || right == NULL)
            return false;

        if (left->val != right->val)
            return false;

        return DFS(left->left, right->right) && DFS(left->right, right->left);
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

