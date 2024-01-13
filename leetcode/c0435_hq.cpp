#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
        {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const auto &u, const auto &v)
             { return u[0] < v[0]; });

        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;

        for (int i = 1; i < n; ++i)
        {
            if (intervals[1][0] >= right)
            {
                ++ans;
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
};