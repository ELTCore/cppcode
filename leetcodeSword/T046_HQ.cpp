#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int translateNum(int num)
    {
        if (num < 10)
        {
            return 1;
        }

        string s = to_string(num);

        int len = s.size();
        int dp[len + 1];

        memset(dp, 0, sizeof(dp));

        dp[0] = 1; // 为了配合dp[2] = d[1] + dp[0]而存在，此时的dp[0] = 1
        dp[1] = 1;

        for (int i = 2; i <= len; ++i)
        {
            dp[i] = dp[i - 1]; // 一定可以跳一步

            // 判断能否跳两步
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '5'))
            {
                dp[i] += dp[i - 2];
            }
        }

        return dp[len];
    }
};