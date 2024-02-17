#include <iostream>
#include <string>
using namespace std;

/*
* 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
/*
* 二叉树可以，那二叉搜索树肯定也可以接着用上一次的方法，只要是个二叉树应该都行
* 但是它既然是个搜索树，自然有它的特殊性在
* 先用上一个的办法试一试
* 很好，上一题的方法能用，说明只要是个树都行
* 接下来解决搜索树的问题
* 二叉搜索树的特性，左子树一定比根小，右子树一定比根大
* 可以利用这个特性去比对
* 可以可以，这题我做出来了ahhhhhhh
* 运行成功，peace~
* 时间66% 空间99%
*/

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || p == root || q == root) return root;
		if ((p->val >= root->val && q->val < root->val) || (p->val <= root->val && q->val > root->val))
		{ // 分布在root的两边，那root就一定是公共祖先
			return root;
		}
		else if (p->val <= root->val && q->val <= root->val)
		{
			return lowestCommonAncestor(root->left, p, q);
		}
		else if (p->val >= root->val && q->val >= root->val)
		{
			return lowestCommonAncestor(root->right, p, q);
		}
		else
		{
			return NULL;
		}
		
	}

	TreeNode* lowestCommonAncestor_by236(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || p == root || q == root) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left != NULL && right != NULL)
			return root;
		else if (left != NULL && right == NULL)
			return left;
		else if (left == NULL && right != NULL)
			return right;
		else
			return NULL;
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

