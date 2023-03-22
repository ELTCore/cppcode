#include <iostream>

using namespace std;

class Slolution
{
    int jumpFloor(int number)
    {
        // int MOD = 1000000007;

        if (number <= 0)
        {
            return 1;
        }
        else if (number <= 2)
        {
            return number;
        }

        int p = 0, q = 0, r = 1;

        for (int i = 1; i <= number; ++i)
        {
            p = q;
            q = r;
            // r = (p + q) % MOD;
            r = p + q;
        }

        return r;
    }
};