/*
520. 检测大写字母
简单
相关标签
相关企业
我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如 "USA" 。
单词中所有字母都不是大写，比如 "leetcode" 。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。



示例 1：

输入：word = "USA"
输出：true
示例 2：

输入：word = "FlaG"
输出：false


提示：

1 <= word.length <= 100
word 由小写和大写英文字母组成
*/

#include <iostream>

using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if (word.empty())
        {
            return false;
        }
        else if (word.size() == 1)
        {
            return true;
        }

        bool isAllUpperCh = true;
        bool isAllyLowerCh = true;
        bool isOnlyFirstChUpper = true;

        const char &ch = word[0];

        if ('a' <= ch && ch <= 'z')
        {
            isAllUpperCh = false;
            isOnlyFirstChUpper = false;
        }
        else if ('A' <= ch && ch <= 'Z')
        {
            isAllyLowerCh = false;
        }
        else
        {
            return false;
        }

        for (int i = 1; i < word.size(); ++i)
        {
            const char &ch = word[i];
            if ('a' <= ch && ch <= 'z')
            {
                isAllUpperCh = false;
            }
            else if ('A' <= ch && ch <= 'Z')
            {
                isAllyLowerCh = false;
                isOnlyFirstChUpper = false;
            }
            else
            {
                return false;
            }
        }

        return isAllUpperCh || isAllyLowerCh || isOnlyFirstChUpper;
    }
};

int main(int argc, char const *argv[])
{
    // string word = "USA";
    string word = "FlaG";

    Solution solu;

    bool res = solu.detectCapitalUse(word);

    cout << "\nres = " << res << endl;

    system("pause");

    return 0;
}
