#include <iostream>

using namespace std;

// 0 1 1 2 3 5 8 13

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }

        return fib(n - 1) + fib(n - 2);
    }
};

int main(int argc, char const *argv[])
{

    cout << "0 + 1 + 2 + 3 + 5 = " << Solution().fib(5) << endl;

    system("pause");

    return 0;
}
