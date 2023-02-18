#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        if (!s.empty())
        {
            s.erase(0, s.find_first_not_of(" "));
            s.erase(s.find_last_not_of(" ") + 1);
        }

        if (s.length() <= 1)
        {
            return s;
        }

        vector<string> res;
        string t;

        for (char ch : s)
        {
            if (ch == ' ')
            {
                if (t.size() == 0)
                {
                    continue;
                }
                else
                {
                    res.push_back(t + ' ');
                    t.clear();
                }
            }
            else
            {
                t.append(1, ch);
            }
        }

        res.push_back(t + ' ');

        reverse(res.begin(), res.end());

        t.clear();

        for (string st : res)
        {
            t.append(st);
        }

        if (t[t.size() - 1] == ' ')
        {
            t.erase(t.size() - 1);
        }
        if (t[0] == ' ')
        {
            t.erase(0, 1);
        }

        return t;
    }
};