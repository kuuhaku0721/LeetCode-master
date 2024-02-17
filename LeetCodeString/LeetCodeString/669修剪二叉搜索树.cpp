#include <iostream>
#include <string>
using namespace std;

/*
* 给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，
使得所有节点的值在[low, high]中。修剪树 不应该 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 
可以证明，存在 唯一的答案 。
所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。
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
* 上一题的办法可以接着用，在上一题，也就是450里面，是=val值的时候删除
* 这里是在范围内保留，否则删除，只不过是要删除的多了一点而已
* 大概，希望如此(因为题目多了一句原有的父子关系保留)
* 
* 与450相比，只是把left和right提前到了最上面，其他的没有变化
* 还行，上一题也理解了
*/

class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL) return root;
        // 这里要把left和right提前，因为这题要删除的不止一个，如果一上来就删除根节点，整个函数就直接返回了
        // 所以要把左右判断的提前，自底向上去执行
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        if (root->val < low || root->val > high)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            if (root->left != NULL && root->right == NULL)
            {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
                return root;
            }
            if (root->left == NULL && root->right != NULL)
            {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            if (root->left != NULL && root->right != NULL)
            {
                // 如果左右都不是空的话，尝试一下把右子树当根，左子树拼接到右子树的最下角
                TreeNode* cur = root->right;
                while (cur->left != NULL)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* temp = root;
                root = root->right;
                delete temp;
                return root;
            }
        }
        return root;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

