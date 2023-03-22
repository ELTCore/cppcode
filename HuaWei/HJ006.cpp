#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int target;
    cin >> target;

    for (int i = 2; i <= sqrt(target); ++i)
    {
        while ((target % i) == 0)
        {
            cout << i << " ";
            target /= i;
        }
    }

    if (target > 2)
    {
        cout << target << endl;
    }

    return 0;
}
