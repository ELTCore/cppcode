#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return false;
        }

        int n = nums.size();
        int first = nums[0], second = INT_MAX;

        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            if (num > second)
            {
                return true;
            }
            else if (num > first)
            {
                second = num;
            }
            else
            {
                first = num;
            }
        }
        return false;
    }
};

// Time spent: 48ms
// Memory usage: 60.1MB