#include <iostream>

using namespace std;

class Solution
{
public:
    int numWays(int n)
    {
        int MOD = 1000000007;

        if (n <= 0)
        {
            return 1;
        }
        else if (n <= 2)
        {
            return n;
        }

        int p = 0, q = 0, r = 1;

        for (int i = 1; i <= n; ++i)
        {
            p = q;
            q = r;
            r = (p + q) % MOD;
        }

        return r;
    }
};

// overtime
/*
class Solution
{
public:
    int numWays(int n)
    {
        if (n == 0)
        {
            return 1;
        }

        count = 0;
        numWays_prvt(n);
        int res = count;
        count = 0;

        return res;
    }

private:
    int count = 0;

    void numWays_prvt(int n)
    {
        if (n <= 0)
        {
            return;
        }
        else if (n == 1)
        {
            count++;
            return;
        }
        else if (n == 2)
        {
            count += 2;
            return;
        }
        else
        {
            numWays_prvt(n - 1);
            numWays_prvt(n - 2);
        }
        return;
    }
};
 */
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
