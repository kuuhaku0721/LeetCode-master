#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一棵二叉树的根节点，返回该树的 直径 。
* 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
* 两节点之间路径的 长度 由它们之间边数表示。
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
* 猜测，应该就是左根右的中序遍历，然后取最左边和最右边之差
* 很好，猜错了
* 这tm简单题？
* 
* 题目说的，可能不经过根节点，所以就不能盯着层序中序遍历了，得一边遍历一边保存最大值
* 然后，看评论看来的，两个节点直接的距离可以用共同祖先得来
* 以某个节点为根节点，然后它的左子树的深度加上右子树的深度就是它所在的这条路径的最大长度
* 所以只需要深度搜索，然后算以每个节点为根节点的时候它的左右子树的深度和，然后最后留个最大值
*/

class Solution {
public:
    int res;
	int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        res = 0;
        dfs(root);
        return res - 1;
	}

    int dfs(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        int left_len = dfs(root->left);
        int right_len = dfs(root->right);
        res = max(res, left_len + right_len + 1);
        return max(left_len, right_len) + 1;
    }
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

