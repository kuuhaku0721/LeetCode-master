#include <iostream>
#include <string>
using namespace std;

/*
* 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，
并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
一般来说，删除节点可分为两个步骤：
首先找到需要删除的节点；
如果找到了，删除它。
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
* 难点是，当找到要删除的节点后，把它删掉如何保持还是二叉搜索树的结构，调整树结构很复杂
* 当然，也有简单的办法，遍历，删除，重新构造
* 但很显然，不能这么做
*/

// 下面是随想录的答案
class Solution1 {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root; // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
        if (root->val == key) {
            // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
            if (root->left == nullptr && root->right == nullptr) {
                ///! 内存释放
                delete root;
                return nullptr;
            }
            // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
            else if (root->left == nullptr) {
                auto retNode = root->right;
                ///! 内存释放
                delete root;
                return retNode;
            }
            // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
            else if (root->right == nullptr) {
                auto retNode = root->left;
                ///! 内存释放
                delete root;
                return retNode;
            }
            // 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
            // 并返回删除节点右孩子为新的根节点。
            else {
                TreeNode* cur = root->right; // 找右子树最左面的节点
                while (cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
                TreeNode* tmp = root;   // 把root节点保存一下，下面来删除
                root = root->right;     // 返回旧root的右孩子作为新root
                delete tmp;             // 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};

/*
* 我自己是实现想不出来这玩意该怎么去实现
* 但是看一看答案，思路能被打开
* 思路打开了第一遍就能理解
* 之后再遇到就有大致的思路了
*/
 
class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        if (root->val == key)
        {   // 当递归找到了要删除节点的时候，需要分情况讨论，毕竟左旋右旋，代码实现起来是很难的
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            if (root->left != NULL && root->right == NULL)
            {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            if (root->left == NULL && root->right != NULL)
            {
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            if (root->left != NULL && root->right != NULL)
            {
                // 左右都不为空的时候，把左子树整个全都放到右子树的左下角，也就是最小的位置
                // 然后要删除节点的有孩子就是新的根
                TreeNode* minus = root->right;
                while (minus->left != NULL)
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

