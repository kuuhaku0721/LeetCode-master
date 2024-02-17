#include <iostream>
#include <string>
using namespace std;

/*
* 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//注意二叉搜索树的特性 中序遍历一定是从小到大排列
//找第k小就是找中序遍历的第k个
//一样中序遍历过去 记录一下值就行
 
class Solution {
public:
    int m_k = 0;
    int cnt = 0;
    bool isStop = false;

	int kthSmallest(TreeNode* root, int k) {
        int res{};
        m_k = k;
        InOrderTraverse(root, res);
        return res;
	}

    void InOrderTraverse(TreeNode* root, int& res)
    {
        if (!isStop)
        {
            if (root == NULL)
                return;
            InOrderTraverse(root->left, res);
            if (!isStop)  //双层保险
            {
                res = root->val;
                cnt++;
                if (cnt == m_k)
                {
                    isStop = true;
                }
            }
            InOrderTraverse(root->right, res);
        }
    }
};

int main()
{
	cout << "hello world" << endl;
    TreeNode* root = new TreeNode(3);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(4);
    root->left = node1; root->right = node4;
    node1->right = node2;
    int res = Solution().kthSmallest(root, 1);
    cout << res << endl;

	system("pause");
	return 0;
}

