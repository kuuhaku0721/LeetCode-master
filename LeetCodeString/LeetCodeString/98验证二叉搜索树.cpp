#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
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
* 验证二叉搜索树，最简单的，中序遍历一定从小到大，判断是不是这个顺序就好
* 加个标志位
* 加if判断，如果满足条件，放行，否则，标志位制反
* 哒咩啊哒....
* 上面的写法只能判断大小，没法判断树结构，即无法判断是否左侧都小于根，右侧都大于根，可能出现小于根的出现在右侧子树的左子树
* 那，转存呗，效率低，消耗大，但是好用
* 也不行啊....
* 只保证了数对了，但树结构不对也不行啊，比如只有左子树和只有右子树的情况
* 
* 
* is_sorted  判断一个数组是不是排序的（默认升序）
* 
* 解决办法，把节点存下来, 然后每次判断上一个节点的值是否小于自己
* 
* 没救了，抄答案了
*/

class Solution {
public:
	bool isValidBST(TreeNode* root) {
        vector<TreeNode*> vec;
        TreeNode* head = new TreeNode(LONG_MIN);
        vec.emplace_back(head);
        bool flag = true;
        InOrderTraverse(root, vec, flag);
        return flag;
	}

    void InOrderTraverse(TreeNode* root, vector<TreeNode*>& vec, bool& flag)
    {
        if (root == NULL)
            return;

        if (flag)
        {
            InOrderTraverse(root->left, vec, flag);
            vec.emplace_back(root);
            if (root->val < vec[vec.size() - 1]->val)
            {
                flag = false;
                return;
            }
            InOrderTraverse(root->right, vec, flag);
        }
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

