// 给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// overtime
//  class Solution
//  {
//  public:
//      bool containsDuplicate(vector<int> &nums)
//      {
//          if (nums.size() <= 0)
//              return true;

//         for (int flag = 1; flag < nums.size(); flag++)
//         {
//             for (int i = 0; i < flag; i++)
//             {
//                 if (nums[i] == nums[flag])
//                 {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };

// class Solution
// {
// public:
//     bool containsDuplicate(vector<int> &nums)
//     {
//         unordered_set<int> s(nums.begin(), nums.end());
//         return s.size() != nums.  size();
//     }
// };
// 执行用时：
// 92 ms
// 内存消耗：
// 53.8 MB


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int x: nums) {
            if (s.find(x) != s.end()) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};

// 作者：demigodliu
// 链接：https://leetcode.cn/problems/contains-duplicate/solution/ha-xi-biao-cun-zai-zhong-fu-yuan-su-by-d-bbzm/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。