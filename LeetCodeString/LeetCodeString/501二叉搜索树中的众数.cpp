#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
* 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。

如果树中有不止一个众数，可以按 任意顺序 返回。

假定 BST 满足如下定义：

结点左子树中所含节点的值 小于等于 当前节点的值
结点右子树中所含节点的值 大于等于 当前节点的值
左子树和右子树都是二叉搜索树
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
* 就这，内存居然还是最小的，意外啊...
*/
class Solution {
public:
    map<int, int> m_map;
	vector<int> findMode(TreeNode* root) {
        vector<int> vec;
        if (root == NULL) return vec;
        countInMap(root);
        // 找map中value最大的加入到vector中
        int max = INT_MIN;
        for (auto it = m_map.begin(); it != m_map.end(); it++)
        {
            if (it->second >= max)
                max = it->second;
        }
        for (auto it = m_map.begin(); it != m_map.end(); it++)
        {
            if (it->second == max)
                vec.push_back(it->first);
        }
        return vec;
	}

    void countInMap(TreeNode* root)
    {
        if (root == NULL)
            return;

        m_map[root->val]++;
        countInMap(root->left);
        countInMap(root->right);
    }
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

