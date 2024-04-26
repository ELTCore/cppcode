/*
560. 和为 K 的子数组
中等
相关标签
相关企业
提示
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

子数组是数组中元素的连续非空序列。



示例 1：

输入：nums = [1,1,1], k = 2
输出：2
示例 2：

输入：nums = [1,2,3], k = 3
输出：2


提示：

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        if (nums.empty())
        {
            return 0;
        }

        int res_count = 0;
        // <sum, way_count>
        unordered_map<int, int> mp;

        return res_count;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3};
    int k = 2;

    Solution solu;

    int res = solu.subarraySum(nums, k);

    cout << "\nres = " << res << endl;

    system("pause");

    return 0;
}
