#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        string res;

        for (char c : s)
        {
            if (c != ' ')
            {
                res.append(1, c);
            }
            else
            {
                res.append("%20");
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
