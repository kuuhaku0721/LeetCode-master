#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
* 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
* 求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/

/*
* 解法是单调栈（我没做出来，我cv的，cv的java，改成cpp）
* 枚举，也就是遍历整个数组，把数组的元素往栈里面压，只不过压栈的时候需要保持栈元素的单调性
* 同时，压栈的元素是数组的下标，这样比较方便拿到宽度
* 然后在维持单调性的时候进行比较，比栈顶元素大，压栈，比栈顶元素小，栈内元素一直出栈，直到栈顶比压栈元素小为止
* 然后计算出栈元素（元素是下标）的宽度，每出一个都要计算，并不是出完才算，每出一个计算的时候保存一个最大值就可以了
* 一个小细节是:为了防止最开始(最左边)的边界值没法计算，需要提前往栈里面压入一个-1
* 注意区分：什么时候用的是下标，什么时候用的是真正的heights里面的值
*/

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < heights.size(); i++)
        {
            while (stk.top() != -1 && heights[i] <= heights[stk.top()])
            {
                int height = heights[stk.top()];
                stk.pop();
                int width = i - stk.top() - 1;
                res = max(res, height * width);
            }
            stk.push(i);
        }
        // 最后处理一下残留值
        while (stk.top() != -1)
        {
            int height = heights[stk.top()];
            stk.pop();
            int width = heights.size() - stk.top() - 1;
            res = max(res, height * width);
        }

        return res;
	}
};



int main()
{
	cout << "hello world" << endl;
    vector<int> heights{ 2,1,5,6,2,3 };
    int res = Solution().largestRectangleArea(heights);
    cout << res << endl;

	system("pause");
	return 0;
}

