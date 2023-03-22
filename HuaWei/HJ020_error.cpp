/*

    W.I.P

 */

#include <iostream>

using namespace std;

void getNext(int *next, const string &s)
{
    next[0] = -1;
    int j = -1;
    for (int i = 1; i < s.size(); i++)
    {
        while (j >= 0 && s[i] != s[j + 1])
        {
            j = next[j];
        }
        if (s[i] == s[j + 1])
        {
            j++;
        }
        next[i] = j;
    }
}
bool repeatedSubstringPattern(string s)
{
    if (s.size() == 0)
    {
        return false;
    }
    int next[s.size()];
    getNext(next, s);
    int len = s.size();
    if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0)
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    string s;

    while (cin >> s)
    {
        cout << "s : " << s << endl;

        bool upCh = 0, lowCh = 0, number = 0, other = 0;

        if (s.size() <= 8)
        {
            cout << "NG:too short" << endl;
            continue;
        }

        if (repeatedSubstringPattern(s))
        {
            cout << "NG:has repeatedSubstring" << endl;
            continue;
        }

        for (auto ch : s)
        {
            if (upCh == 0 && ch >= 'A' && ch <= 'Z')
            {
                cout << "debug: has upCh" << endl;
                upCh = 1;
            }
            else if (lowCh == 0 && ch >= 'a' && ch <= 'z')
            {
                cout << "debug: has lowCh" << endl;
                lowCh = 1;
            }
            else if (number == 0 && ch >= '0' && ch <= '9')
            {
                cout << "debug: has number" << endl;
                number = 1;
            }
            else
            {
                cout << "debug: has other" << endl;
                other = 1;
            }

            if (upCh + lowCh + number + other >= 3)
            {
                break;
            }
        }

        if (upCh + lowCh + number + other < 3)
        {
            cout << "NG: has not enough variety char" << endl;
            continue;
        }

        cout << "OK" << endl;
    }

    return 0;
}
