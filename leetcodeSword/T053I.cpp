#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> &nums, int target, bool lower)
    {
        int left = 0, right = (int)nums.size() - 1, res = (int)nums.size();

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target))
            {
                right = mid - 1;
                res = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        return res;
    }

    int search(vector<int> &nums, int target)
    {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;

        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target)
        {
            return rightIdx - leftIdx + 1;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
