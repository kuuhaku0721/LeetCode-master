#include <iostream>
#include <string>
using namespace std;

/*
* 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。
更正式地说，即 root.val = min(root.left.val, root.right.val) 总成立。
给出这样的一个二叉树，你需要输出所有节点中的 第二小的值 。
如果第二小的值不存在的话，输出 -1 。
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
* 是个简单题，所以解法多不胜数，所以难点，挑战，在于怎么能节省空间减少时间
* 不用模板，能减少不少空间
* 一次遍历结束，能提高不少时间
* 涉及到左右子树，所以需要递归
* 
* 嘶...好像，题目有特殊条件，忘记看了，但是，不影响做题，嗯，不影响，大概
* 
* 答案...好像是...深度优先遍历来着...
* 无所吊谓，写出来就是胜利，况且时间100%，win
*/
 
class Solution {
public:
	int findSecondMinimumValue(TreeNode* root) {
        unsigned int res = -1;
        unsigned int minnum = 3000000000;
        findMinNum(root, res, minnum);
        if (res == 3000000000)
            return -1;
        else
            return res;
	}

    void findMinNum(TreeNode* root, unsigned int& res, unsigned int& minnum)
    {
        if (root == NULL)
            return;
        if (root->val < minnum)
        {
            res = minnum;
            minnum = root->val;
        }
        else
        {
            if (root->val < res && root->val != minnum)
                res = root->val;
        }
        findMinNum(root->left, res, minnum);
        findMinNum(root->right, res, minnum);
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

