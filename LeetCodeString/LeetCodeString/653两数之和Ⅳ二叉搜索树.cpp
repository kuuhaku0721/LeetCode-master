#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个二叉搜索树 root 和一个目标结果 k，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 true
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
* 首先，这题我做过....大概
* 因为是二叉搜索树，所以，好像是可以找规律，两数之和等于它的一定出现在某个位置，但是我想不起来是什么规律
* so
* 用最简单的最好想的办法来做，遍历树，保留树上所有节点，然后接着冒泡遍历查结果
* 又占内存又慢，但是简单好操作..
* 俗话说得好：逃跑可耻，但有用~
* 
* 更正：可以不这么两次循环的计算啊，反正要的两数和，用双指针，一个头一个尾，已知vector是递增的，那算头和尾的和
*      如果头尾和小了，头指针后移，如果头尾和大了，尾指针左移，这样一次遍历就能得到结果了
*/
 
class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        midOrderTraverse(root, vec);
        for (int i = 0; i < vec.size() - 1; i++)
        {
            for (int j = i + 1; j < vec.size(); j++)
            {
                if (vec[i] + vec[j] == k)
                    return true;
            }
        }
        return false;
	}

    void midOrderTraverse(TreeNode* root, vector<int>& vec)
    {
        if (root == NULL)
            return;
        vec.push_back(root->val);
        midOrderTraverse(root->left, vec);
        midOrderTraverse(root->right, vec);
    }
};



int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

