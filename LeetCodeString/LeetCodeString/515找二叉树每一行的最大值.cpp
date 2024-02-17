#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
* 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
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
* 上一题刚做过，在513 dfs函数一模一样用，只是多一步判断而已
*/
class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
        vector<multiset<int>> vec;    //存每一层的结果
        dfs(root, 0, vec);
        vector<int> res;
        for (multiset<int> v : vec)
        {
            res.push_back(*(--v.end()));
        }
        return res;
	}

    void dfs(TreeNode* root, int level, vector<multiset<int>>& vec)
    {
        if (root == NULL)
            return;

        if (level < vec.size())
        {
            vec[level].insert(root->val);
        }
        else
        {
            multiset<int> tmpVec;
            tmpVec.insert(root->val);
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