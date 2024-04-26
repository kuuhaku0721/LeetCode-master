#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

/*
* 实现支持下列接口的「快照数组」- SnapshotArray：
SnapshotArray(int length) - 初始化一个与指定长度相等的 类数组 的数据结构。初始时，每个元素都等于 0。
void set(index, val) - 会将指定索引 index 处的元素设置为 val。
int snap() - 获取该数组的快照，并返回快照的编号 snap_id（快照号是调用 snap() 的总次数减去 1）。
int get(index, snap_id) - 根据指定的 snap_id 选择快照，并返回该快照指定索引 index 的值。
*/

/*
* 实现本身不难，怕的是五万次的调用，要不超时要不溢出，但不管怎么说，先写出来再优化
* 很好，五万次调用果然内存溢出
* 换到堆上？
*/
class SnapshotArray2 {
public:
    SnapshotArray2(int length) {
        m_prevec.resize(length, 0);
        m_currvec.resize(length, 0);

        m_id = 0;
    }

    void set(int index, int val) {
        m_currvec[index] = val;
    }

    int snap() {
        if (m_snaps.empty())
        {
            for (int i = 0; i < m_currvec.size(); i++)
            {
                list<int> tmp_list;
                tmp_list.push_back(m_currvec[i]);
                m_snaps.push_back(tmp_list);
                m_prevec[i] = m_currvec[i];
            }
        }
        else
        {
            for (int i = 0; i < m_prevec.size(); i++)
            {
                if (m_currvec[i] != m_prevec[i])
                    m_snaps[i].push_back(m_currvec[i]);
                m_prevec[i] = m_currvec[i];
            }
            m_id++;
        }
        return m_id;
    }

    int get(int index, int snap_id) {
        if (m_snaps[index].size() < snap_id + 1)
        {
            return *m_snaps[index].rbegin();
        }
        else
        {
            auto it = m_snaps[index].begin();
            while (snap_id > 0)
            {
                it++;
                snap_id--;
            }
            return *it;
        }
    }

private:
    vector<int> m_prevec;
    vector<int> m_currvec;
    vector<list<int>> m_snaps;
    int m_id;
};

/*
* 评论区大佬的写法，我比较认同这个
*/
class SnapshotArray {
public:
    SnapshotArray(int length) {
        this->length = length;
        root.assign(50010, 0);
        build(root[0], 1, length);
        rootidx = 1;
        root[rootidx] = root[rootidx - 1];
    }

    void set(int index, int val) {
        insert(root[rootidx], root[rootidx], 1, length, index + 1, val);
    }

    int snap() {
        /*std::cout << rootidx << ": ";
        for(int i = 1; i <= length; i++) {
            std::cout << query(root[rootidx], 1, length, i) << ' ';
        }
        std::cout << '\n';*/
        rootidx++;
        root[rootidx] = root[rootidx - 1];
        return rootidx - 2;
    }

    int get(int index, int snap_id) {
        return query(root[snap_id + 1], 1, length, index + 1);
    }

private:
    struct node {
        int l, r, val;
    }tr[50000 << 5];
    int idx = 0, rootidx = 0, length = 0;
    std::vector<int> root;

    void build(int& u, int l, int r) {
        u = ++idx;
        if (l == r) {
            tr[u].val = 0;
            return;
        }

        int mid = l + r >> 1;
        build(tr[u].l, l, mid), build(tr[u].r, mid + 1, r);
    }

    void insert(int pre, int& now, int l, int r, int index, int val) {
        now = ++idx;
        tr[now] = tr[pre];
        if (l == r) {
            tr[now].val = val;
            return;
        }

        int mid = l + r >> 1;
        if (index <= mid) insert(tr[pre].l, tr[now].l, l, mid, index, val);
        else insert(tr[pre].r, tr[now].r, mid + 1, r, index, val);
    }

    int query(int now, int l, int r, int index) {
        if (l == r) return tr[now].val;

        int mid = l + r >> 1;
        if (index <= mid) return query(tr[now].l, l, mid, index);
        else return query(tr[now].r, mid + 1, r, index);
    }

};

// 官解  但是看不懂
class SnapshotArray1 {
public:
    SnapshotArray1(int length) : snap_cnt(0), data(length) {}

    void set(int index, int val) {
        data[index].emplace_back(snap_cnt, val);
    }

    int snap() {
        return snap_cnt++;
    }

    int get(int index, int snap_id) {
        auto x = upper_bound(data[index].begin(), data[index].end(), make_pair( snap_id + 1, -1 ));
        return x == data[index].begin() ? 0 : prev(x)->second;
    }

private:
    int snap_cnt;
    vector<vector<pair<int, int>>> data;
};



/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main()
{
	cout << "hello world" << endl;
    // ["SnapshotArray","snap","snap","set","snap","get","set","get","snap","get"]
    //    [[1],         [],    [],   [0,4],  [],   [0,1],[0,12],[0,1],  [],  [0,3]]
    SnapshotArray sarr(4);
    cout << sarr.snap() << endl;
    cout << sarr.snap() << endl;
    cout << sarr.get(3, 1) << endl;
    sarr.set(2, 4);
    cout << sarr.snap() << endl;
    sarr.set(1, 4);

	system("pause");
	return 0;
}

