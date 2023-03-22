#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vector_s(128, 0);
    int res = 0;

    char ch;
    while (cin >> ch)
    {
        if (ch != '\n')
            ++vector_s[ch];
    }

    for (auto it : vector_s)
    {
        if (it != 0)
        {
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}
