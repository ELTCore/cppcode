/*
438. 找到字符串中所有字母异位词
中等
相关标签
相关企业
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。



示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。


提示:

1 <= s.length, p.length <= 3 * 104
s 和 p 仅包含小写字母
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.empty() || p.empty() || p.size() > s.size())
        {
            return vector<int>();
        }

        vector<int> res;
        vector<int> hashP(26, 0);
        vector<int> hashCur(26, 0);

        for (const char &ch : p)
        {
            ++hashP[ch - 'a'];
        }

        for (int i = 0; i < p.size(); ++i)
        {
            ++hashCur[s[i] - 'a'];
        }

        if (hashCur == hashP)
        {
            res.emplace_back(0);
        }

        for (int i = p.size(); i < s.size(); ++i)
        {
            const char &del_ch = s[i - p.size()];
            --hashCur[del_ch - 'a'];

            const char &add_ch = s[i];
            ++hashCur[add_ch - 'a'];

            if (hashCur == hashP)
            {
                res.emplace_back(i - p.size() + 1);
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    string s = "aaaaaaaaaa";
    string p = "aaaaaaaaaaaaa";

    Solution solu;
    vector<int> res;
    res = solu.findAnagrams(s, p);

    cout << "res = ";
    for (const int &n : res)
    {
        cout << n << " ";
    }
    cout << endl;

    system("pause");

    return 0;
}
