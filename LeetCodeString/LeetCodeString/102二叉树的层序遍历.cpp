#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
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
* 层序遍历，也是递归
* 但是需要有一个level值当作参数传进去，这样每一轮递归的时候就可以根据这个level值判断它现在在哪一层
* 递归还是深度优先，也就是顺着一路往下，每向下一个level+1，同时另一条线路的level值还是当前层的值
*/


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resultVec;
        dfs(root, 0, resultVec);
        return resultVec;
	}

    void dfs(TreeNode* root, int level, vector<vector<int>>& vec)
    {
        if (root == NULL)
            return;

        if (level < vec.size())
        {   // level比结果集合大小要小，说明这一层已经存过第一个值了，可以顺着往后继续存
            vec[level].push_back(root->val);
        }
        else
        {   // level比size要大，说明是第一次递归到这一层
            vector<int> curfloor;
            curfloor.push_back(root->val);
            vec.push_back(curfloor);
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

