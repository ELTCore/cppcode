#include <iostream>

using namespace std;

constexpr int64_t mod = 1000000007;
constexpr int N = 22 + 1, M = N * 9;
int64_t dp[N + 1][M + 1];

auto rb = [](long long x)
{ return (x % mod + mod) % mod; };

auto _ = []
{
    fill_n(dp[0], M + 1, 1);
    for (int i = 1; i <= N; ++i)
    {
        int64_t presum{};
        for (int j = 0; j <= M; ++j)
        {
            presum += j >= 10 ? rb(dp[i - 1][j] - dp[i - 1][j - 10]) : dp[i - 1][j];
            dp[i][j] = presum = rb(presum);
        }
    }
    return 0;
}();

class Solution
{
public:
    int count(string num1, string num2, int min_sum, int max_sum)
    {
        num1.back()--;
        min_sum--;
        max_sum = min(max_sum, M);
        min_sum = min(min_sum, M);
        for (int i = num1.size() - 1; i >= 0 && num1[i] == '0' - 1; --num1[--i])
            num1[i] = '9';

        int n = num2.size();
        auto solve = [&](string num, int max_sum)
        {
            int n = num.size(), sum = max_sum;
            int64_t ans = 0;
            for (int i = 0; i < n && sum >= 0; ++i)
            {
                int x = num[i] - '0';
                for (int j = 0; j < x && j <= sum; ++j)
                    ans += dp[n - i - 1][sum - j];
                sum -= x;
            }
            return rb(ans + (sum >= 0));
        };
        return rb(solve(num2, max_sum) - solve(num2, min_sum) - solve(num1, max_sum) + solve(num1, min_sum));
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
