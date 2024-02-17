#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
* 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
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
* 也就是说，已知中序遍历结果，构造二叉树
* 无在乎左边多还是右边多，只要高度差不大于1就行，所以根节点可以是size/2
* 左边又是中序遍历，左子树的根节点还是size/2
* 右边同理
* 因此，多半是递归
*/


class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
        if (nums.size() == 1)
        {
            TreeNode* root = new TreeNode(nums[0]);
            return root;
        }
        TreeNode* root = new TreeNode(nums[nums.size() / 2]);
        vector<int> leftnum;                        //如果需要优化就把这俩vector优化掉
        for (int i = 0; i < nums.size() / 2; i++)
        {
            leftnum.push_back(nums[i]);
        }
        vector<int> rightnum;
        for (int i = ((nums.size() / 2) + 1); i < nums.size(); i++)
        {
            rightnum.push_back(nums[i]);
        }
        root->left = sortedArrayToBST(leftnum);
        root->right = sortedArrayToBST(rightnum);
        return root;
	}
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

