#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
* 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
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
* 比较是否相同？那不就是遍历两次？然后比对一下就好了？
* 空间？不管啦
* 
* 最后一个办法，两棵树同时遍历，每次遍历都判断节点值，不一样直接返回，一样继续遍历
*/
 
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;
        
        bool flag = true;
        InOrderTraverse(p, q, flag);
        return flag;
	}

    void InOrderTraverse(TreeNode* p, TreeNode* q, bool& flag)
    {
        if (!flag)
            return;

        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
        {
            flag = false;
            return;
        }
        else if (p == NULL && q == NULL)
            return;
        else
        {
            if (p->val != q->val)
            {
                flag = false;
                return;
            }
            InOrderTraverse(p->left, q->left, flag);
            InOrderTraverse(p->right, q->right, flag);
        }
    }
};



int main()
{
	cout << "hello world" << endl;

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(1);
    p->right = NULL;

    TreeNode* q = new TreeNode(1);
    q->left = NULL;
    q->right = new TreeNode(1);

    bool res = Solution().isSameTree(p, q);
    cout << to_string(res) << endl;

	system("pause");
	return 0;
}

