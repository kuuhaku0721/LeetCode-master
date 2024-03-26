#include <iostream>
#include <string>
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
	TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;

        return Reverse(root);
	}

    TreeNode* Reverse(TreeNode* root)
    {
        // 空的，树外，直接返回
        if (root == nullptr)
            return nullptr;
        // 叶子节点也直接返回，然后交给上一层去处理
        if (root->left == nullptr && root->right == nullptr)
            return root;

        root->left = Reverse(root->left);
        root->right = Reverse(root->right);

        // 开始转换
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;

        return root;
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

