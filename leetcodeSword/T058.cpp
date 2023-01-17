#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
