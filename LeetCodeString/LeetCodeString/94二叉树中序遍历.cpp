#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
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
 * 二叉树 中序遍历 即 左-根-右 的顺序
 * 方法是递归遍历
 */
 
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        InOrderTraverse(res, root);
        return res;
	}

    void InOrderTraverse(vector<int>& vec, TreeNode* T)
    {
        if (T == NULL)
            return;
        InOrderTraverse(vec, T->left);
        vec.push_back(T->val);
        InOrderTraverse(vec, T->right);
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

