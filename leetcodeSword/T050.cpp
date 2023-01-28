#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    char firstUniqChar(string s)
    {
        unordered_map<int, int> frequency;
        for (char ch : s)
        {
            ++frequency[ch];
        }
        for (char ch : s)
        {
            if (frequency[ch] == 1)
            {
                return ch;
            }
        }
        return ' ';
    }
};
