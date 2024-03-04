#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
/*
* 给定一个二叉树，我们在树的节点上安装摄像头。
* 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
* 计算监控树的所有节点所需的最小摄像头数量。
*/

/*
* 深度优先遍历，遍历的时候把自己的位置上是否存在摄像头当作参数传递进去
* 每次递归的时候检查参数，如果有，则这一轮自己不用再放，把没装的参数传递进去，继续循环
* 如果没有，则自己这一轮安装上，然后参数传递，继续递归
* 如果碰到叶子节点且参数显示没有，那就装上，参数显示有，那就不装
* 问题：简单的认为，只要奇数高根节点不放，偶数高根节点放 就可以了，但其实不然，还会有特殊情况
* 看完答案后：哦~~~~原来是我想反了，就不应该考虑根节点放不放的问题，应该从叶子节点开始考虑，叶子都不放，这样才是最优的
* 最终还是cv了，可恶啊....
*/

class Solution {
public:
    int cameracnt{};
	int minCameraCover(TreeNode* root) {
        if (root == NULL) return 0;
        // 如果树高小于3，那就1个就够
        if (depth(root) <= 2) return 1;
        // 树高超过3 判断奇偶 决定根节点要不要放
        dfs(root);
        
        return cameracnt;
	}

    int depth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        return 1 + max(left, right);
    }

    // -1:被覆盖 0:当前位置无 1:当前位置有
    int dfs(TreeNode* root)
    {
        if (root == NULL)
            return -1;

        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left == -1 && right == -1)
            return 0;
        else if (left == 0 || right == 0)
        {
            cameracnt++;
            return 1;
        }
        else
            return -1;
    }
};

class Solution1 {
private:
    int result;
    int traversal(TreeNode* cur) {
        if (cur == NULL) return -1;
        int left = traversal(cur->left);    // 左
        int right = traversal(cur->right);  // 右

        if (left == -1 && right == -1) return 0;
        else if (left == 0 || right == 0) {
            result++;
            return 1;
        }
        else return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (traversal(root) == 0) { // root 无覆盖
            result++;
        }
        return result;
    }
};



int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

