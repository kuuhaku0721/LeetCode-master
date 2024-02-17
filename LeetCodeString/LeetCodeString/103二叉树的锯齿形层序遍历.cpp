#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
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
* 层序遍历...还是先保存，再reverse
* 笑死，就这？ 
* 虽然解法比较差 先保存，再转换
* 但是好用...
*/

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;    //存每一层的结果
        dfs(root, 0, vec);
        for (int i = 0; i < vec.size(); i++)
        {
            if (i % 2 != 0)
            {
                reverse(vec[i].begin(), vec[i].end());
            }
        }
        return vec;
	}

    void dfs(TreeNode* root, int level, vector<vector<int>>& vec)
    {
        if (root == NULL)
            return;

        if (level < vec.size())             //TODO:优化的话，这里有level，可以就level的值判断奇偶，然后直接保存
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

