/*
3. 无重复字符的最长子串
中等
相关标签
相关企业
给定一个字符串 s ，请你找出其中不含有重复字符的 最长
子串
 的长度。



示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
        {
            return 0;
        }

        int res_maxLength = 1;

        int left = 0;
        int curLength = 0;
        vector<int> hashChIndex(128, -1);

        for (int i = 0; i < s.size(); ++i)
        {
            const char &ch = s[i];

            int ch_left = hashChIndex[ch];
            if (ch_left >= left)
            {
                res_maxLength = max(curLength, res_maxLength);
                left = ch_left + 1;
                curLength = i - left;
            }
            ++curLength;

            hashChIndex[ch] = i;
        }
        res_maxLength = max(curLength, res_maxLength);

        return res_maxLength;
    }
};

int main(int argc, char const *argv[])
{
    // string s = "abcabcbb";
    // string s = "bbbbb";
    string s = "pwwkew";
    // string s = "au";
    // string s = "abba";

    Solution solu;

    int res = solu.lengthOfLongestSubstring(s);

    cout << "\nres = " << res << endl;

    system("pause");

    return 0;
}
