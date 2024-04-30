#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
* 中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
* 例如 arr = [2,3,4] 的中位数是 3 。
* 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
* 实现 MedianFinder 类:
* MedianFinder() 初始化 MedianFinder 对象。
* void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
* double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。
*/

class MedianFinder1 {
public:
    priority_queue<int> m_bigheap;
    MedianFinder1() {

    }

    void addNum(int num) {
        m_bigheap.push(num);
    }

    double findMedian() {
        int size = m_bigheap.size() / 2;
        auto back_up = m_bigheap;
        if (m_bigheap.size() % 2 == 0)
        {
            --size;
            while (size > 0)
            {
                back_up.pop();
                --size;
            }
            int tmp = back_up.top();
            back_up.pop();
            return (tmp + back_up.top()) / 2.0;
        }
        else
        {
            while (size > 0)
            {
                back_up.pop();
                --size;
            }
            return back_up.top() * 1.0;
        }

    }
};

// 官解的方法，用堆的想法对了，但是只维护一个堆返回的弹出会超时，所以官解用了两个堆，一个倒序一个正序，然后两个堆的top就是数据中间那个数
// 插入元素的时候注意维护堆的数量平衡，也就是左右size差距不要大于1
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> queMin;
    priority_queue<int, vector<int>, greater<int>> queMax;

    MedianFinder() {}

    void addNum(int num) {
        if (queMin.empty() || num <= queMin.top()) {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size()) {
                queMax.push(queMin.top());
                queMin.pop();
            }
        }
        else {
            queMax.push(num);
            if (queMax.size() > queMin.size()) {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian() {
        if (queMin.size() > queMax.size()) {
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

