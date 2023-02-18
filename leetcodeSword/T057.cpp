#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;

        while (i < j)
        {
            int s = nums[i] + nums[j];

            if (s < target)
            {
                i++;
            }
            else if (s > target)
                j--;
            else
            {
                return {nums[i], nums[j]};
            }
        }

        return {0, 0};
    }
};

/* class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashtable;

        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = hashtable.find(nums[i]);

            if (it == hashtable.end())
            {
                hashtable.insert({target - nums[i], nums[i]});
            }
            else
            {
                return {it->first, it->second};
            }
        }

        return {-1, -1};
    }
};
 */
int main(int argc, char const *argv[])
{
    unordered_map<int, int> test;

    test.insert({123, 233});

    if (test.find(233) == test.end())
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "test.find(233)->first = " << test.find(233)->first << endl;
    }

    cout << "test.find(123)->first = " << test.find(123)->second << endl;

    system("pause");

    return 0;
}
