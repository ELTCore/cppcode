// 给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_multiset<int> hashtable1, hashtable2;
        vector<int> result;

        for (int i : nums1)
            hashtable1.insert(i);
        for (int i : nums2)
            hashtable2.insert(i);

        for (auto i : hashtable1)
        {
            auto it = hashtable2.find(i);
            if (!(it == hashtable2.end()))
            {
                result.push_back(i);
                hashtable2.erase(it);
            }
        }

        return result;
    }
};

// 执行用时：4ms
// 内存消耗：10.8MB