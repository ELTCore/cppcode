#include <iostream>
#include <vector>

using namespace std;

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

#define MAX_LEN 100000
class MyHashSet
{
private:
    vector<int> set[MAX_LEN];

    /* 返回相应的表索引 */
    int getIndex(int key)
    {
        return key % MAX_LEN;
    }

    /* 搜索特定存储哈希表中的值。如果值不存在，则返回-1 */
    int getPos(int key, int index)
    {
        for (int i = 0; i < set[index].size(); ++i)
        {
            if (set[index][i] == key)
            {
                return i;
            }
        }
        return -1;
    }

public:
    MyHashSet()
    {
    }
    /* 向哈希集合中插入值key */
    void add(int key)
    {
        int index = getIndex(key);
        int pos = getPos(key, index);
        /* 如果不存在则添加新的数据进去 存在不做任何操作 */

        if (pos < 0)
        {
            set[index].push_back(key);
        }
    }

    /* 将给定值key从哈希集合中删除 */
    void remove(int key)
    {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if (pos >= 0)
        {
            set[index].erase(set[index].begin() + pos);
        }
    }

    /** 返回哈希集合中是否存在这个值 key */
    bool contians(int key)
    {
        int index = getIndex(key);
        int pos = getPos(key, index);
        return pos >= 0;
    }
};

class MyHashMap
{
private:
    vector<pair<int, int>> map[MAX_LEN];

    /** 定义散列函数返回存储数据的下标 */
    int getIndex(int key)
    {
        return key % MAX_LEN;
    }

    /* 查找数据在哈希表中的位置 */
    int getPos(int key, int index)
    {
        for (int i = 0; i < map[index].size(); ++i)
        {
            if (map[index][i].first == key)
            {
                return i;
            }
        }
        return -1;
    }

public:
    MyHashMap()
    {
    }
    /* 插入一个键值对key，value。如果key存在于映射中，则更新其对应的值value */
    void put(int key, int value)
    {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if (pos < 0)
        {
            map[index].push_back(make_pair(key, value));
        }
        else
        {
            map[index][pos].second = value;
        }
    }
    /* 返回特定的key所映射的value;如果映射中不包含key的映射，返回-1 */
    int get(int key)
    {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if (pos < 0)
        {
            return -1;
        }
        else
        {
            return map[index][pos].second;
        }
    }

    /** 如果映射中存在key的映射，则移除key和它所对应的value */
    void remove(int key)
    {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if (pos >= 0)
        {
            map[index].erase(map[index].begin() + pos);
        }
    }
};