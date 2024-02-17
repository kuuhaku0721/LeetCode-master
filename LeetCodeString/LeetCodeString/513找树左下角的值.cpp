#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
假设二叉树中至少有一个节点。
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
* 可以层序遍历，找最后一层第一个
* 但是层序有个问题是，如何判断现在的这一层是最后一层
* 可以用之前有道题，求的每一层的平均值，那道题里面能拿到层数
*/
 
class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> vec;    //存每一层的结果
        dfs(root, 0, vec);
        return vec[vec.size() - 1][0];
	}

    void dfs(TreeNode* root, int level, vector<vector<int>>& vec)
    {
        if (root == NULL)
            return;

        if (level < vec.size())
        {
            vec[level].push_back(root->val);
        }
        else
        {
            vector<int> tmpVec;
            tmpVec.push_back(root->val);
            vec.push_back(tmpVec);
        }
        dfs(root->left, level + 1, vec);
        dfs(root->right, level + 1, vec);
    }
};



int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

