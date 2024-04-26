/*
283. 移动零
简单
相关标签
相关企业
提示
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。



示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:

输入: nums = [0]
输出: [0]


提示:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1


进阶：你能尽量减少完成的操作次数吗？
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        if (nums.empty())
        {
            return;
        }

        int first_zero_index = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                continue;
            }

            nums[first_zero_index] = nums[i];
            ++first_zero_index;
        }

        for (; first_zero_index < nums.size(); ++first_zero_index)
        {
            nums[first_zero_index] = 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {4, 2, 4, 0, 0, 3, 0, 5, 0, 1, 0};

    Solution solu;

    solu.moveZeroes(nums);

    cout << "\nres = ";
    for (int &i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    system("pause");

    return 0;
}
