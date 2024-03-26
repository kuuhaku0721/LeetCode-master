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
	bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return Symmetric(root->left, root->right);
	}

    bool Symmetric(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;

        if (left->val != right->val)
            return false;

        return Symmetric(left->left, right->right) && Symmetric(left->right, right->left);
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

