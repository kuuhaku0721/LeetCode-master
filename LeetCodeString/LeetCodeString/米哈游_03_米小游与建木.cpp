#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

/*
* 没法构建出来树，但是可以模拟
* 反正需要递归，只需要找准递归的入口函数就行了
* 可能需要多次调用find，最终结果估计会超时，但是只要能写出来就行
*/
void BuildTree()
{
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> edges;
	for (int i = 0; i < n - 1; i++)
	{
		int p1, p2;
		cin >> p1 >> p2;
		edges.emplace_back(make_pair(p1, p2));
	}
	// 然后就是递归函数的设计了，已知根节点，可以从根节点出发

	int target = 99;
	find(edges.begin(), edges.end(), [target](pair<int, int>& p) {
		return p.first == target || p.second == target;
		});
}

/*
* 因为不知道指针方向，所以可以用双向的
* 凡是有相连关系的全都保有一个指针
* 也就是每个节点都由三个指针，分别指向三个与其相连的节点
* 判断是不是叶子节点可以用三个指针里面空指针的个数，只有叶子节点是两个空指针
* 判断方向可以选择加一个访问位，从根节点开始只要遍历过的节点都给访问位置位
* 然后通过三个指针放查询这个访问位然后决定下一步往哪边走
* 可能会超时，但是应该是能做
*/

int dfs(int root, int chld)
{
	// 找带chld并且不带root的组合，然后继续循环
	// 如果找不到，就返回1
	// 然后依次返回，返回的时候判断是不是自己的因子，是的话累加，返回，不是的话不累加直接返回
	// 这样会有问题，这样只能判断父子节点之间是不是因子关系，不能隔代判断，所以
}



int main()
{
    

	system("pause");
	return 0;
}

