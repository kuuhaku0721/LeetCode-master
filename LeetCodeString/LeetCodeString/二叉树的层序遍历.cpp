#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        dfs(vec, root, 0);
        return vec;
    }

    void dfs(vector<vector<int>>& vec, TreeNode* root, int level)
    {
        if (root == nullptr)
            return;

        if (level < vec.size())
        {
            vec[level].push_back(root->val);
        }
        else
        {
            vector<int> curfloor;
            curfloor.push_back(root->val);
            vec.push_back(curfloor);
        }

        dfs(vec, root->left, level + 1);
        dfs(vec, root->right, level + 1);
    }
};



int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

