#include <iostream>
#include <string>
#include <queue>
using namespace std;


/*
* 实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
int next()将指针向右移动，然后返回指针处的数字。
注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。
你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。
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
* 迭代器初始化的时候，调用中序遍历，存个stack
* 每次调用queue，弹出一个出来
* hasNext判断stack是否为空
*/
 
class BSTIterator {
public:
    queue<TreeNode*> m_treeQueue;
    
    BSTIterator(TreeNode* root) {
        //m_treeQueue.push(new TreeNode(-1));
        InOrderTraverse(root);
    }

    void InOrderTraverse(TreeNode* root)
    {
        if (root == NULL)
            return;

        InOrderTraverse(root->left);
        m_treeQueue.push(root);
        InOrderTraverse(root->right);
    }

    int next() {
        int val = m_treeQueue.front()->val;
        m_treeQueue.pop();
        return val;
    }

    bool hasNext() {
        return !m_treeQueue.empty();
    }
};



int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

