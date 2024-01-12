// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 子数组 是数组中的一个连续部分。

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// overtime
// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         vector<int> v_nums;
//         int max = INT_MIN;

//         for (int i = 0, sum = 0; i < nums.size(); i++, sum = 0)
//         {
//             v_nums.push_back(nums[i]);
//             sum = countSum(v_nums);
//             if (max < sum)
//                 max = sum;

//             for (int j = 0; j < i; j++)
//             {
//                 sum -= v_nums[j];
//                 if (sum >= max)
//                     max = sum;
//             }
//         }

//         return max;
//     }

//     int countSum(vector<int> v_nums)
//     {
//         int sum = 0;
//         for (int n : v_nums)
//         {
//             sum += n;
//         }
//         return sum;
//     }
// };

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = INT_MIN;
        int numSize = int(nums.size());
        int sum = 0;

        for (int i = 0; i < numSize; i++)
        {
            sum += nums[i];
            result = max(result, sum);

            if (sum < 0)
                sum = 0;
        }

        return result;
    }
};
// 执行用时：
// 80ms
// 内存消耗：
// 66.2MB