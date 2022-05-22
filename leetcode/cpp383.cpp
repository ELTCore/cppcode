// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

// 如果可以，返回 true ；否则返回 false 。

// magazine 中的每个字符只能在 ransomNote 中使用一次。

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_multiset<char> magz;

        for (char ch : magazine)
            magz.insert(ch);

        for (char ch : ransomNote)
        {
            auto it = magz.find(ch);
            if (it == magz.end())
                return false;
            else
                magz.erase(it);
        }

        return true;
    }
};

// Time spent：84ms
// Memory Usage：38.5MB

// more appropriate way
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }
        vector<int> cnt(26);
        for (auto &c : magazine)
        {
            cnt[c - 'a']++;
        }
        for (auto &c : ransomNote)
        {
            cnt[c - 'a']--;
            if (cnt[c - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};

// Time spent: 8ms
// Memory usage: 8.6MB