#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
* 叶子节点 是指没有子节点的节点。
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
* 找所有路径，其实就是找所有的叶子节点，只不过在找的时候要把路径保存下来
* 成功了一半，只有一条路径的话是对的，但是因为path字符串还保留了上一次的结果，所以从第二条路径开始就不对了
* 嘶...就是简单多用一个string保存一下上一步结果，就...过了
* 笑死...
* 
* 十几分钟就能干掉一题，你还挺厉害的嘛，虽然是简单题
*/
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        if (root == NULL) return vec;
        string path = "";
        findLeaf(root, path, vec);
        return vec;
	}

    void findLeaf(TreeNode* root, string& path, vector<string>& vec)
    {
        if (root == NULL)
            return;
        if (root->left != NULL || root->right != NULL)
        {
            path += to_string(root->val);
            path += "->";
            string rightpath = path;
            findLeaf(root->left, path, vec);
            findLeaf(root->right, rightpath, vec);
        }
        else
        {
            path += to_string(root->val);
            vec.push_back(path);
            return;
        }
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

