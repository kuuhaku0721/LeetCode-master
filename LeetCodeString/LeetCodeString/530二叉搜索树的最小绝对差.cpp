#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
* 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
* 差值是一个正数，其数值等于两值之差的绝对值。
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
* 怎么直接从树拿到结果，我不知道，但是，我可以把树上所有结果全都拿出来，然后单独去对结果进行运算
* 答案的思路，其实差不了太多
二叉搜索树有个性质为二叉搜索树中序遍历得到的值序列是递增有序的，因此我们只要得到中序遍历后的值序列即能用上文提及的方法来解决。
朴素的方法是经过一次中序遍历将值保存在一个数组中再进行遍历求解，我们也可以在中序遍历的过程中用 pre\textit{pre}pre 变量保存前驱节点的值，
这样即能边遍历边更新答案，不再需要显式创建数组来保存，
需要注意的是 pre\textit{pre}pre 的初始值需要设置成任意负数标记开头，下文代码中设置为 −1-1−1。
*/

class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        preOrderTraverse(vec, root);
        //现在所有值都在vec里面，然后再从这里面计算就行
        int res = 1000000;
        for (int i = 0; i < vec.size() - 1; i++)
        {
            for (int j = i + 1; j < vec.size(); j++)
            {
                if (abs(vec[i] - vec[j]) < res)
                {
                    res = abs(vec[i] - vec[j]);
                }
            }
        }
        return res;
	}

    void preOrderTraverse(vector<int>& vec, TreeNode* root)
    {
        if (root == NULL)
            return;
        vec.push_back(root->val);
        preOrderTraverse(vec, root->left);
        preOrderTraverse(vec, root->right);
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

