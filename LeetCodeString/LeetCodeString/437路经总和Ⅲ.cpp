#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
* 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
* 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
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
* 还是遍历，但是每次都从自己的节点开始算总和
* 这样的话，就会留下两个值了..一个从自己出发的，一个到自己的
* 直接全部存下来然后算总和也是个办法，但很明显不是这么做的
* 可以遍历的时候加上从它开始的总和，然后返回给上级，好像也不对
* 
* 很好，放弃，看答案
* 答案有个前缀和，学学这个
*/
class Solution {
public:
    unordered_map<long long, int> prefix;
    int dfs(TreeNode* root, long long curr, int targetSum)
    {
        if (root == nullptr)
            return 0;
        int ret = 0;
        curr += root->val;
        if (prefix.count(curr - targetSum))
            ret = prefix[curr - targetSum];

        prefix[curr]++;
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        prefix[curr]--;

        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

