#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
* 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。
*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*
* 反正你也是层序来的，那就还按照层序的步骤来做
* 先dfs全部遍历，保存，然后遍历每一个数组
* 设置数组里每一个节点的右指针，最后一个不设置
* 问题是：上述做法需要先保存，再设置，能不能不保存，一次遍历结束？
* 
* 完事，虽然结果不上不下，但是起码成功了，该解决上面的问题了
* 很好，解决不了
* 答案的写法很值得学习（是这个不难，我能理解，可以模仿的意思）
*/


// 答案的写法
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }

        // 初始化队列同时将第一层节点加入队列中，即根节点
        queue<Node*> Q;
        Q.push(root);

        // 外层的 while 循环迭代的是层数
        while (!Q.empty()) {

            // 记录当前队列大小
            int size = Q.size();

            // 遍历这一层的所有节点
            for (int i = 0; i < size; i++) {

                // 从队首取出元素
                Node* node = Q.front();
                Q.pop();

                // 连接
                if (i < size - 1) {
                    node->next = Q.front();
                }

                // 拓展下一层节点
                if (node->left != nullptr) {
                    Q.push(node->left);
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                }
            }
        }

        // 返回根节点
        return root;
    }
};


class Solution1 {
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> vec;
        dfs(root, 0, vec);
        
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].size() - 1; j++)
            {
                vec[i][j]->next = vec[i][j + 1];
            }
        }

        return root;
    }

    void dfs(Node* root, int level, vector<vector<Node*>>& vec)
    {
        if (root == NULL)
            return;

        if (level < vec.size())
        {
            vec[level].push_back(root);
        }
        else
        {
            vector<Node*> temp;
            temp.push_back(root);
            vec.push_back(temp);
        }

        dfs(root->left, level + 1, vec);
        dfs(root->right, level + 1, vec);
    }
};



int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

