#include <iostream>
#include <string>
using namespace std;

/*
* 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，
最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
* 答案抄的代码随想录
* 大致思路：以后序遍历为底子，递归加回溯
* 左子树和右子树分别递归到最底层，然后开始判断
* 如果是空，直接返回，也就是递归到低
* 然后往上一层，判断的逻辑是，如果包含p或q，就把它的父结点传递上去
* 一直往上传递，传递到左右子树传递的值相交，那就是最终结果
* 总而言之，大多数的解法都是递归加回溯，先递归到最后，然后一层层向上回溯
* 当然还有最暴力的破解办法
* 前序遍历两次，保存结果，然后分别比较父结点就行了
*/
 
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p == root || q == root || root == NULL) return root;
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

