#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
* 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
*/
/*
* 你自己说的，两个队列啊，不许反悔啊
* 
* 但是！
* 这个写法，一个队列也能实现
* 现在的思路是，如果需要pop或top，就把一个队列中的数据挪到另一个里面，只剩下一个数，这个剩下的数就是栈顶
* 如果只用一个队列，那就反复出队入队，直到最后一个数到了第一个的位置，然后它就是栈顶
* 其实没有太大区别
*/

class MyStack {
public:
    queue<int> que_tmp;
    queue<int> m_que;
    MyStack() {

    }

    void readyToPush()
    {
        while (!m_que.empty())
        {
            que_tmp.push(m_que.front());
            m_que.pop();
        }
    }
    void readyToPop()
    {
        while (que_tmp.size() > 1)
        {
            m_que.push(que_tmp.front());
            que_tmp.pop();
        }
    }

    void push(int x) {
        readyToPush();
        que_tmp.push(x);
    }

    int pop() {
        readyToPop();
        int t = que_tmp.front();
        que_tmp.pop();
        readyToPush();
        return t;
    }

    int top() {
        readyToPop();
        int t = que_tmp.front();
        m_que.push(t);
        que_tmp.pop();
        readyToPush();
        return t;
    }

    bool empty() {
        return que_tmp.empty() && m_que.empty();
    }
};



int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

