#include <iostream>
#include <string>
using namespace std;

/*
* 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
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
* 还用上一道题那样的递归遍历
* 只不过上一题是比较是否相等，这一题是交换
* 先试试行不行
* 好像是行..但是有空值..
* 不对不对，它不是左的左等于右的右这样变，它就是自己的左右孩子交换，只不过根节点的孩子也交换了所以后面全都换了
* 如果现在这种写法，本来已经交换过去的，经过后面的递归之后又给换回去了，所以结果不对
* 所以，其实只需要递归每个节点，注意是每个，然后交换它自己的左右孩子就行了
* 
* 深刻理解一下递归的思路：先一口气跑到底，然后从底向上一步步运算回来，最终回到起点，执行完毕
*/
 
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) 
            return NULL;
        TreeNode* lef = invertTree(root->left); //左子树单独递归
        TreeNode* righ = invertTree(root->right); //右子树单独递归
        //交换
        root->left = righ;
        root->right = lef;
        return root;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

