#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，
* 请你构造并返回这颗 二叉树 。
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

// 以后序遍历为主，中序遍历当作判断数量的标志
class Solution1 {
private:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;

        // 后序遍历数组最后一个元素，就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // 叶子节点
        if (postorder.size() == 1) return root;

        // 找到中序遍历的切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // 切割中序数组
        // 左闭右开区间：[0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        // [delimiterIndex + 1, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        // postorder 舍弃末尾元素
        postorder.resize(postorder.size() - 1);

        // 切割后序数组
        // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
        // [0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
};

class Solution {
public:
    TreeNode* buildHelper(vector<int>& inorder, vector<int>& postorder)
    {
        if (postorder.size() == 0) return NULL;

        // 先构造根节点
        TreeNode* root = new TreeNode();
        root->val = postorder[postorder.size() - 1];

        // 如果是叶子节点的话直接返回
        if (postorder.size() == 1) return root;

        // 找到当前根节点在中序遍历数组中的位置
        auto in_index = find(inorder.begin(), inorder.end(), root->val);

        // 以根节点位置为标记，分割中序遍历出来两个数组
        vector<int> leftInOrder(inorder.begin(), in_index);
        vector<int> rightInOrder(in_index + 1, inorder.end());
        // 然后分割后序遍历
        postorder.resize(postorder.size() - 1);
        vector<int> leftPostOrder(postorder.begin(), postorder.begin() + leftInOrder.size());
        vector<int> rightPostOrder(postorder.begin() + leftInOrder.size(), postorder.end());

        root->left = buildHelper(leftInOrder, leftPostOrder);
        root->right = buildHelper(rightInOrder, rightPostOrder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;
        return buildHelper(inorder, postorder);
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

