#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
*/


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


/*
* 哟西 哟西，经过多次联系，层序遍历的写法已经是了熟于心了
* 一次通关，没有多余拖泥带水
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }

    void dfs(Node* root, int level, vector<vector<int>>& vec)
    {
        if (root == NULL)
            return;

        if (level < vec.size())
        {
            vec[level].push_back(root->val);
        }
        else
        {
            vector<int> currFloor;
            currFloor.emplace_back(root->val);
            vec.emplace_back(currFloor);
        }

        for (int i = 0; i < root->children.size(); i++)
        {
            dfs(root->children[i], level + 1, vec);
        }
    }
};




int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

