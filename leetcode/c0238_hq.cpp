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