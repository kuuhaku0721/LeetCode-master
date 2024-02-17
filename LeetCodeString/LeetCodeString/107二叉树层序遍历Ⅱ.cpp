#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
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
* 你看啊，反正你得返回两个vector，那干脆存起来，然后倒转不就好了？
*/
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vec;
        dfs(root, 0, vec);
        reverse(vec.begin(), vec.end());
        return vec;
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
            vector<int> tmp;
            tmp.push_back(root->val);
            vec.push_back(tmp);
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

