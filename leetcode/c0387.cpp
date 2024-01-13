// 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        if (s.size() <= 1)
            return 0;

        unordered_map<char, int> hashtable;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            auto it = hashtable.find(ch);

            if (it == hashtable.end())
                hashtable.insert(make_pair(s[i], i));
            else
            {
                it->second = -1;
            }
        }

        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            auto it = hashtable.find(ch);

            if (it->second != -1)
                return it->second;
        }
        return -1;
    }
};

// 执行用时：28ms
// 内存消耗：10.6MB