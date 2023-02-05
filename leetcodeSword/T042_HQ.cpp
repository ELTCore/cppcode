#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currentMax = 0, globalMax = nums[0];

        for (int i = 0; i < nums.size(); ++i)
        {

            if (currentMax + nums[i] < nums[i])
            {
                currentMax = nums[i];
            }
            else
            {
                currentMax = currentMax + nums[i];
            }

            if (globalMax < currentMax)
            {
                globalMax = currentMax;
            }
        }

        return globalMax;
    }
};