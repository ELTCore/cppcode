/*
1146. 快照数组
中等
相关标签
相关企业
提示
实现支持下列接口的「快照数组」- SnapshotArray：

SnapshotArray(int length) - 初始化一个与指定长度相等的 类数组 的数据结构。初始时，每个元素都等于 0。
void set(index, val) - 会将指定索引 index 处的元素设置为 val。
int snap() - 获取该数组的快照，并返回快照的编号 snap_id（快照号是调用 snap() 的总次数减去 1）。
int get(index, snap_id) - 根据指定的 snap_id 选择快照，并返回该快照指定索引 index 的值。


示例：

输入：["SnapshotArray","set","snap","set","get"]
     [[3],[0,5],[],[0,6],[0,0]]
输出：[null,null,0,null,5]
解释：
SnapshotArray snapshotArr = new SnapshotArray(3); // 初始化一个长度为 3 的快照数组
snapshotArr.set(0,5);  // 令 array[0] = 5
snapshotArr.snap();  // 获取快照，返回 snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // 获取 snap_id = 0 的快照中 array[0] 的值，返回 5


提示：

1 <= length <= 50000
题目最多进行50000 次set，snap，和 get的调用 。
0 <= index < length
0 <= snap_id < 我们调用 snap() 的总次数
0 <= val <= 10^9
*/
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SnapshotArray
{
public:
    SnapshotArray(int length)
    {
        vv.resize(length);
        for (auto &v : vv)
        {
            v.push_back(0); // 默认元素初始化为0
        }
    }

    void set(int index, int val)
    {
        // 设置时看看末尾到没到最新的snap，没到的话就填最新值填平差距
        while (vv[index].size() <= cnt)
        {
            vv[index].push_back(vv[index].back());
        }
        vv[index].back() = val; // 更改最新的快照到val
    }

    int snap()
    {
        return cnt++; // 增加快照计数
    }

    int get(int index, int snap_id)
    {
        auto &v = vv[index];
        // 关键思想：如果index对应的记录表与最新快照次数有差距，
        // 说明在快照更新的这段时间内，index对应的val没更新
        // 那么index保存的back()即为最新的快照
        if (v.size() <= snap_id)
        {
            return v.back();
        }
        else
        {
            // 如果已经到达了最新snap，则直接返回对应值
            return v[snap_id];
        }
    }

private:
    // 使用二维数组的直接思路就是以最小的时间代价去get
    // 因为我们默认两次快照之间不会set绝大部分值，只会set一小部分
    // 所以对于空间的消耗也没有那么极端，从思路上更简单
    vector<vector<int>> vv;
    int cnt = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main(int argc, char const *argv[])
{
    unique_ptr<SnapshotArray> ptr_snapshotArr(new SnapshotArray(3));

    ptr_snapshotArr->set(0, 5);
    ptr_snapshotArr->snap();
    ptr_snapshotArr->set(0, 6);

    int res = ptr_snapshotArr->get(0, 0);

    cout << "\nres = " << res << endl;

    system("pause");

    return 0;
}
