#include <iostream>

using namespace std;

// 0 1 1 2 3 5 8 13

class Solution
{
public:
    int fib(int n)
    {
        int MOD = 1000000007;

        if (n < 2)
        {
            return n;
        }

        int p = 0, q = 0, r = 1;

        for (int i = 2; i <= n; ++i)
        {
            p = q;
            q = r;
            r = (p + q) % MOD;
        }

        return r;
    }

private:
    // overtime
    int fib_prvt(int n)
    {
        if (n < 0)
        {
            return -1;
        }

        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }

        return fib_prvt(n - 1) + fib_prvt(n - 2);
    }
};

int main(int argc, char const *argv[])
{

    cout << "0 1 1 2 3 _ 8\nres:" << Solution().fib(5) << endl;

    system("pause");

    return 0;
}
