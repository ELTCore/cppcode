#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> occ;

        int j = 0;
        int res = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            while (j < s.size() && occ.find(s[j]) == occ.end())
            {
                occ.insert(s[j]);
                res = max(res, j - i + 1);
                j++;
            }

            occ.erase(s[i]);
        }

        return res;
    }
};