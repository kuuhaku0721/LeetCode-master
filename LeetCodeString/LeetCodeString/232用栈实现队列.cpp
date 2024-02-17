#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
* 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
实现 MyQueue 类：
void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
说明：
你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
*/


/*
* 两个stack来回倒
* 时间100% 空间99%
* 嗯~ o(*￣▽￣*)o
* 确实很爽
*/

class MyQueue {
public:
    stack<int> bufStack;
    stack<int> m_stack;
    MyQueue() {

    }

    void changePop()
    {
        while (!bufStack.empty())
        {
            int t = bufStack.top();
            m_stack.push(t);
            bufStack.pop();
        }
    }
    void changePush()
    {
        while (!m_stack.empty())
        {
            int t = m_stack.top();
            bufStack.push(t);
            m_stack.pop();
        }
    }

    void push(int x) {
        changePush();
        bufStack.push(x);
    }

    int pop() {
        changePop();
        int top = m_stack.top();
        m_stack.pop();
        return top;
    }

    int peek() {
        changePop();
        return m_stack.top();
    }

    bool empty() {
        return m_stack.empty() && bufStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

