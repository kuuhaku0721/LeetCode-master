#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

创建一个根节点，其值为 nums 中的最大值。
递归地在最大值 左边 的 子数组前缀上 构建左子树。
递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。
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
* 写法还是用上次105 106的，分割数组
* 只不过这里需要多一步，查找最大值
*/
/*
* 81ms还能击败50%，神了
* 虽然大家基本都是分割数组就是了
* 还有就是，max不行，访问不了，得用max_element
*/
class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        
        auto mid = max_element(nums.begin(), nums.end());
        TreeNode* root = new TreeNode(*mid);

        if (nums.size() == 1)
            return root; // 叶子结点

        // 分割左右子树
        vector<int> leftNums(nums.begin(), mid);
        vector<int> rightNums(mid + 1, nums.end());
        root->left = constructMaximumBinaryTree(leftNums);
        root->right = constructMaximumBinaryTree(rightNums);

        return root;
	}

    void construct(vector<int>& nums) {
        if (nums.size() == 0)
        {
            cout << "本轮结束" << endl;
            return;
        }

        auto mid = max_element(nums.begin(), nums.end());
        cout << "当前根节点：" << (*mid) << endl;

        if (nums.size() == 1)
        {
            cout << "到叶子结点，直接return" << endl;
            return;
        }

        // 分割左右子树
        vector<int> leftNums(nums.begin(), mid);
        vector<int> rightNums(mid + 1, nums.end());
        construct(leftNums);
        construct(rightNums);
    }
};

int main()
{
	cout << "hello world" << endl;
    vector<int> nums{ 3,2,1,6,0,5 };
    Solution().construct(nums);

	system("pause");
	return 0;
}

