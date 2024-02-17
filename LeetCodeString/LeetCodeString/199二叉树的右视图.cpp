#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
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
* 咱先不管正解是啥，先把题做了
* 既然要右视图，那就层序，保存，取每一层最后一个
* 
* 嘶。。。。。既然是深度优先了，那从右边开始不也可以？
* 我是sb
*/

/*
* class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<vector<int>> vec;
        dfs(root, 0, vec);
        for (vector<int> v : vec)
        {
            result.push_back(v[v.size() - 1]);
        }
        return result;
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
            vector<int> temp;
            temp.push_back(root->val);
            vec.push_back(temp);
        }

        dfs(root->left, level + 1, vec);
        dfs(root->right, level + 1, vec);
    }
};
*/

/*欸嘿，这才对嘛，这才是正经的，时间100%  */

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
	}

    void dfs(TreeNode* root, int level, vector<int>& vec)
    {
        if (root == NULL)
            return;
        
        if(level >= vec.size())
        {
            vec.push_back(root->val);
        }

        dfs(root->right, level + 1, vec);
        dfs(root->left, level + 1, vec);
    }
};




int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

