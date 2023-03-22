#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> hashtable;

        for (int i = 0; i < numbers.size(); ++i)
        {
            auto it = hashtable.find(target - numbers[i]);

            if (it != hashtable.end())
                return {it->second + 1, i + 1};

            hashtable[numbers[i]] = i;
        }

        return {};
    }
};