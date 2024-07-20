/*
125. 验证回文串
简单
相关标签
相关企业
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。


示例 1：

输入: s = "A man, a plan, a canal: Panama"
输出：true
解释："amanaplanacanalpanama" 是回文串。
示例 2：

输入：s = "race a car"
输出：false
解释："raceacar" 不是回文串。
示例 3：

输入：s = " "
输出：true
解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
由于空字符串正着反着读都一样，所以是回文串。


提示：

1 <= s.length <= 2 * 105
s 仅由可打印的 ASCII 字符组成
*/
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        bool res = true;

        auto it = s.rbegin();
        for (struct {
            std::string::iterator it;
            std::string::reverse_iterator rit; } sIt = {s.begin(), s.rbegin()}; sIt.it != s.end();)
        {
            if (!isCharOrNum(*sIt.it))
            {
                ++sIt.it;
                continue;
            }

            if (!isCharOrNum(*sIt.rit))
            {
                ++sIt.rit;
                continue;
            }

            if (std::tolower(*sIt.it) == std::tolower(*sIt.rit))
            {
                ++sIt.it;
                ++sIt.rit;
                continue;
            }

            res = false;
            break;
        }

        return res;
    }

    inline bool isCharOrNum(const char &ch)
    {
        return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9');
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;

    string s = "A man, a plan, a canal: Panama";

    bool res = solu.isPalindrome(s);

    cout << "\nres = " << res << endl;

    system("pause");

    return 0;
}
