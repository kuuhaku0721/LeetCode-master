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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if(root->val == key)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            if (root->left != nullptr && root->right == nullptr)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if (root->left == nullptr && root->right != nullptr)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (root->left != nullptr && root->right != nullptr)
            {
                TreeNode* minus = root->right;
                while (minus->left != nullptr)
                    minus = minus->left;
                minus->left = root->left;
                TreeNode* temp = root;
                root = root->right;
                delete temp;
                return root;
            }
        }

        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};



int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

