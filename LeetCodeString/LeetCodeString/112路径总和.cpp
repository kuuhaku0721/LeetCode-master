#include <iostream>
#include <string>
using namespace std;

/*
* 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，
这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
叶子节点 是指没有子节点的节点。
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
* 过程不难
* 80% 90% 凑合
*/
  
class Solution {
public:
    int m_target;
	bool hasPathSum(TreeNode* root, int targetSum) {
        m_target = targetSum;
        int sum = 0;
        return CalculatePathSum(root, sum);
	}

    bool CalculatePathSum(TreeNode* root, int& sum)
    {
        if (root == NULL)
            return false;

        sum += root->val;
        cout << "当次总和为： " << sum << endl;
        if (root->left == NULL && root->right == NULL)
        {
            return sum == m_target;
        }
        else
        {
            bool b1 = CalculatePathSum(root->left, sum);
            bool b2 = CalculatePathSum(root->right, sum);
            return b1 || b2;
        }
    }
};

int main()
{
	cout << "hello world" << endl;


	system("pause");
	return 0;
}

