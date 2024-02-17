#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
* 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//深度优先遍历，维护两个数组，一个这层结点数，一个存这层总和


//有点问题，还不太会
 
class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<int> counts;  //这一层节点数量
        vector<double> sums; //这一层的总和
        dfs(root, 0, counts, sums);
        for (int i = 0; i < sums.size(); i++)
        {
            res.push_back(sums[i] / counts[i]);
        }
        return res;
	}
    
    void dfs(TreeNode* root, int level, vector<int>& counts, vector<double>& sums)
    {
        if (root == NULL)
            return;

        if (level < sums.size()) 
        { 
            sums[level] += root->val;
            counts[level] += 1;
        }
        else 
        { //每次进来这个else分支是因为当前节点是这一层的第一个节点
            sums.push_back(1.0 * root->val);
            counts.push_back(1);
        }
        dfs(root->left, level + 1, counts, sums);
        dfs(root->right, level + 1, counts, sums);
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

