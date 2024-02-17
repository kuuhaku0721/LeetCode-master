#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
* 给定一个二叉树：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。

初始状态下，所有 next 指针都被设置为 NULL 。

跟116相比的区别在于：116是完美二叉树，这一题是普通二叉树，即左右节点可能有空的
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


// 首先还是自己熟悉的写法，虽然不是最好的，但是简单
// 这题还比上一题时间要短，说明有的人的写法在碰到非完美的时候卡壳了
// 虽然我笨，但是好用
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
            vec[level].emplace_back(root);
        }
        else
        {
            vector<Node*> temp;
            temp.emplace_back(root);
            vec.emplace_back(temp);
        }

        dfs(root->left, level + 1, vec);
        dfs(root->right, level + 1, vec);
    }
};


// 再来上一题答案的解法，用队列
// 时间上不如上一个解法，但是空间要比上一个好得多
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        queue<Node*> que;
        que.push(root);
        while (!que.empty())
        {
            // 先记录这一层的大小，当下一轮循环到这里的时候可以以此为判断依据
            int size = que.size();

            for (int i = 0; i < size; i++)
            {
                Node* node = que.front();
                que.pop();

                // 排除每一层的最后一个
                if (i < size - 1)
                    node->next = que.front();

                // 进来左子树
                if (node->left != NULL)
                    que.push(node->left);
                // 进来右子树
                if (node->right != NULL)
                    que.push(node->right);
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

