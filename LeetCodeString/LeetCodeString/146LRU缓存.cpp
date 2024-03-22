#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
* 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
* 实现 LRUCache 类：
* LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
* int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
* void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
* 如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
* 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/

/*
* 嘶....不好，不太妙
* 它是key value存储，还不是单纯的链表，嘶.....
* 嗯，可以，用pair代指一下key value，然后其他的就还按照list的写
* 最后有句话：必须以O(1)的时间复杂度运行，意思就是，得用哈希表，先等等，做出来再说
* 如果要换哈希，那就会有另一个问题，如何保证顺序
* 混起来用吧，哈希表保证查询的O(1)，双向链表调整顺序
* 可行，但是频繁的链表切换超时了
* 需要有个更快速的办法执行链表的切换更新
* 下面有答案，其实就是自己实现一个双向链表，然后用map里面就可以直接存节点了
*/
class LRUCache1 {
public:
    LRUCache1(int capacity) {
        m_capa = capacity;
    }

    int get(int key) {
        int res = -1;
        if (uset.find(key) != uset.end())
        {
            auto it = m_lst.begin();
            for (; it != m_lst.end(); it++)
            {
                if (it->first == key)
                {
                    res = it->second; // 保存返回值
                    m_lst.emplace_back(make_pair(it->first, it->second));
                    m_lst.erase(it);
                    break;
                }
            }
        }
        return res;
    }

    void put(int key, int value) {
        if (uset.find(key) != uset.end())
        {   // 已经存在，更新value值，并且标志访问过
            auto it = find_if(m_lst.begin(), m_lst.end(), [key](pair<int, int>& pr) {
                return pr.first == key;
                });
            it->second = value;
            m_lst.emplace_back(make_pair(it->first, it->second));
            m_lst.erase(it);
        }
        else
        {   // 不存在，插进去
            uset.insert(key);
            pair<int, int> pr(key, value);
            m_lst.emplace_back(make_pair(key, value));
            if (uset.size() > m_capa)
            {
                auto oldpr = m_lst.front();
                m_lst.pop_front();
                uset.erase(oldpr.first);
            }
        }
    }

private:
    list<pair<int, int>> m_lst;     // 链表存对应的节点
    unordered_set<int> uset;        // 哈希存key
    int m_capa;
};

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
	cout << "hello world" << endl;
    LRUCache lru(5);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl;

	system("pause");
	return 0;
}

