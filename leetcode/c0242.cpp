// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int ch[26] = {0};
        for (char c : s)
            ch[c - 'a']++;

        for (char c : t)
        {
            ch[c - 'a']--;
            if (ch[c - 'a'] < 0)
                return false;
        }

        for (int i : ch)
            if (i != 0)
                return false;

        return true;
    }
};

// Time spent: 4ms
// Memory usage: 7.1MB