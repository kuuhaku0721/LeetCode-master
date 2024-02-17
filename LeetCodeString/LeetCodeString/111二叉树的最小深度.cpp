#include <iostream>
#include <string>
using namespace std;

/*
* 给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。
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
* 层序遍历，找第一个叶子节点，也就是找第一个左右孩子都是空的
* 既然是层序，那么多半就是dfs，深度优先遍历
* 遍历的时候维护层数变量，找到叶子节点之后直接返回对应层数
* 
* 现在的写法不太对，现在的逻辑是，如果左孩子比有孩子晚到叶子，但是因为先判断的左孩子，结果就不对了
* 现在是只要左右孩子有一个空就返回了，所以直接取min也不行
*/


/*
* 答案的正经深度优先遍历算法
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int min_depth = INT_MAX;
        if (root->left != nullptr) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr) {
            min_depth = min(minDepth(root->right), min_depth);
        }

        return min_depth + 1;
    }
};


class Solution {
public:
	int minDepth(TreeNode* root) {
        if (root == NULL) 
            return 0;
        if (root->left != NULL && root->right == NULL)
            return minDepth(root->left) + 1;
        if (root->left == NULL && root->right != NULL)
            return minDepth(root->right) + 1;

        return min(minDepth(root->left), minDepth(root->right)) + 1;
	}

    int dfs(TreeNode* root, int level, bool& flag)
    {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL) //碰到叶子节点，直接退出，不再继续递归
        {
            flag = false;
            return level + 1;
        }

        if (flag)
        {
            if (root->left != NULL && root->right != NULL)
            {
                int lef = dfs(root->left, level, flag);
                int righ = dfs(root->right, level, flag);
                return min(lef, righ);
            }
            if (root->left != NULL || root->right != NULL)
            {
                if (root->left != NULL)
                {
                    level++;
                    return dfs(root->left, level, flag);
                }
                if (root->right != NULL)
                {
                    level++;
                    return dfs(root->right, level, flag);
                }
            }
        }

        return level + 1;
        
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

