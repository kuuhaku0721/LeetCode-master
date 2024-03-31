#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

/*
* 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
* 
* 实现 MinStack 类:
* 
* MinStack() 初始化堆栈对象。
* void push(int val) 将元素val推入堆栈。
* void pop() 删除堆栈顶部的元素。
* int top() 获取堆栈顶部的元素。
* int getMin() 获取堆栈中的最小元素。
*/

class MinStack {
public:
    MinStack() {
        stk.resize(30000, INT_MAX);
        size = 0;
    }

    void push(int val) {
        stk[size] = val;
        priority.insert(val);
        size++;
    }

    void pop() {
        int num = stk[size - 1];
        priority.erase(priority.find(num));
        stk[size - 1] = 0;
        size--;
    }

    int top() {
        return stk[size - 1];
    }

    int getMin() {
        return *(priority.begin());
    }

private:
    vector<int> stk;
    multiset<int> priority;
    int size;
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

