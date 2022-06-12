#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ERROR
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
        {
            return intervals;
        }

        vector<vector<int>> result;

        char mp[10001] = {0};

        for (auto vec : intervals)
        {
            if (vec[0] == vec[1])
            {
                mp[vec[0]] = 2;
            }
            else
            {
                for (int i = vec[0]; i < vec[1]; ++i)
                {
                    mp[i] = 1;
                }
            }
        }

        vector<int> ad(2, 0);

        for (int i = 0; i < 10001; ++i)
        {
            if (mp[i] == 2 && (i == 0 || (mp[i - 1] == 0 && mp[i + 1] == 0)))
            {
                result.emplace_back(vector<int>(2, i));
            }

            if (mp[i] == 1 && (i == 0 || mp[i - 1] == 0))
            {
                ad[0] = i;
            }
            if (mp[i] == 1 && mp[i + 1] == 0)
            {
                ad[1] = i + 1;
                result.emplace_back(ad);
            }
        }

        return result;
    }
};

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
        {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i)
        {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L)
            {
                merged.push_back({L, R});
            }
            else
            {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
