#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int leftF = 0;
        int rightF = nums.size() - 1;
        bool leftTurn = 1;

        while (leftF < rightF)
        {
            if (leftTurn)
            {
                if (nums[leftF] % 2 == 0)
                {
                    leftTurn = 0;
                }
                else
                {
                    leftF++;
                }
            }
            else
            {
                if (nums[rightF] % 2 == 1)
                {
                    int t = nums[leftF];
                    nums[leftF] = nums[rightF];
                    nums[rightF] = t;

                    leftTurn = 1;
                }
                else
                {
                    rightF--;
                }
            }
        }

        return nums;
    }
};