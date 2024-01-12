#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:  
    void sortColors(vector<int> &nums)
    {
        int flag = nums.size();
        for (int i = 0; i < flag; --flag)
        {
            for (int j = i + 1; j < flag; ++j)
                if (nums[j] < nums[j - 1])
                    swap(nums[j], nums[j - 1]);

            // for (int k = 0; k < nums.size(); ++k)
            //     cout << nums[k] << " ";

            // cout << endl;
        }
    }
};

// Time spent: 0ms
// Memory usage: 8MB