/*
238. 除自身以外数组的乘积
提示
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请不要使用除法，且在 O(n) 时间复杂度内完成此题。

示例 1:

输入: nums = [1,2,3,4]
输出: [24,12,8,6]
示例 2:

输入: nums = [-1,1,0,-3,3]
输出: [0,0,9,0,0]


提示：

2 <= nums.length <= 105
-30 <= nums[i] <= 30
保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内

进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组 不被视为 额外空间。）
*/
#include <iostream>
#include <vector>

using namespace std;

// overtime
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> result(nums.size());
        int crtProduct = 1; // currentProduct

        for (int i = 0; i < nums.size(); ++i)
        {
            crtProduct = 1;
            for (int j = 0; j < nums.size(); ++j)
            {
                if (j == i)
                {
                    continue;
                }
                if (nums[j] == 0)
                {
                    crtProduct = 0;
                    break;
                }
                crtProduct *= nums[j];
            }

            result[i] = crtProduct;
        }

        return result;
    }
};

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int length = nums.size();
        vector<int> answer(length);

        // answer[i] 表示索引 i 左侧所有元素的乘积
        // 因为索引为 ‘0’ 的元素左侧没有元素，所以answer[0] = 1

        answer[0] = 1;
        for (int i = 1; i < length; i++)
        {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R 为右侧所有元素的乘积
        // 刚开始右边没有元素，所以R = 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--)
        {
            // 对于索引 i，左边的乘积为 answer[i]，右边乘积为R
            answer[i] = answer[i] * R;
            // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到R上
            R *= nums[i];
        }
        return answer;
    }
};