#include <iostream>
#include <string>
using namespace std;

/*
* 给你两棵二叉树： root1 和 root2 。
* 想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。
* 你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；
* 否则，不为 null 的节点将直接作为新二叉树的节点。
* 返回合并后的二叉树。
* 注意: 合并过程必须从两个树的根节点开始。
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
* 合并的意思是：对应位置，如果当前位置有，则数值累加，没有，则插入新结点
* 以root1为准，把root叠加到1上去
*/

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) return NULL;
        if (root1 != NULL && root2 != NULL)
        {
            root1->val += root2->val;
        }
        else if (root1 == NULL && root2 != NULL)
        {
            root1 = root2;
        }
        mergeTrees(root1->left, root2->left);
        mergeTrees(root1->right, root2->right);
        return root1;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

