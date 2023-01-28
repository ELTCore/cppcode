#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        unordered_set<int> numberFrequency;

        for (int num : nums)
        {
            auto it = numberFrequency.find(num);
            if (it == numberFrequency.end())
                numberFrequency.insert(num);
            else
                return num;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
