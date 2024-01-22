/*
670. 最大交换
已解答
中等
相关标签
相关企业
给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

示例 1 :

输入: 2736
输出: 7236
解释: 交换数字2和数字7。
示例 2 :

输入: 9973
输出: 9973
解释: 不需要交换。
注意:

给定数字的范围是 [0, 108]
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        int res = 0;

        int t = num;
        vector<int> nums;
        while(t != 0)
        {
            int n = t%10;
            nums.push_back(n);
            t /= 10;
        }

        int maxNum = vecToNum(nums);
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i+1; j < nums.size(); ++j)
            {
                vector<int> temp = nums;
                swap(temp[i], temp[j]);

                int tempNum = vecToNum(temp);
                if(tempNum > maxNum)
                {
                    maxNum = tempNum;
                }
            }
        }

        res = maxNum;

        return res;
    }

    int vecToNum(vector<int> nums)
    {
        int res = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            res += nums[i] * pow(10,i);
        }
        
        return res;
    }
    
};