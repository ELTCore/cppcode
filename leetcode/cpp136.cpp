#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_set<int> hashSet;

        for (auto n : nums)
        {
            auto it = hashSet.find(n);
            if (it == hashSet.end())
                hashSet.emplace(n);
            else
                hashSet.erase(it);
        }

        return *hashSet.begin();
    }
};

// Time spent: 32ms
// Memory usage: 19.3MB

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        for (auto e : nums)
            ret ^= e;
        return ret;
    }
};