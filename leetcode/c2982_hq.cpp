/*
2982. 找出出现至少三次的最长特殊子字符串 II
中等
相关标签
相关企业
提示
给你一个仅由小写英文字母组成的字符串 s 。

如果一个字符串仅由单一字符组成，那么它被称为 特殊 字符串。例如，字符串 "abc" 不是特殊字符串，而字符串 "ddd"、"zz" 和 "f" 是特殊字符串。

返回在 s 中出现 至少三次 的 最长特殊子字符串 的长度，如果不存在出现至少三次的特殊子字符串，则返回 -1 。

子字符串 是字符串中的一个连续 非空 字符序列。



示例 1：

输入：s = "aaaa"
输出：2
解释：出现三次的最长特殊子字符串是 "aa" ：子字符串 "aaaa"、"aaaa" 和 "aaaa"。
可以证明最大长度是 2 。
示例 2：

输入：s = "abcdef"
输出：-1
解释：不存在出现至少三次的特殊子字符串。因此返回 -1 。
示例 3：

输入：s = "abcaba"
输出：1
解释：出现三次的最长特殊子字符串是 "a" ：子字符串 "abcaba"、"abcaba" 和 "abcaba"。
可以证明最大长度是 1 。


提示：

3 <= s.length <= 5 * 105
s 仅由小写英文字母组成。
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumLength(string s)
    {
        // 统计每个字母，连续出现的次数
        unordered_map<char, vector<int>> ump;
        int res = -1;

        int cnt = 1;
        s += '0'; // 结束符
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] != s[i - 1])
            {
                ump[s[i - 1]].push_back(cnt);
                cnt = 1;
            }
            else
                cnt += 1;
        }

        for (auto &[_, vt] : ump)
        {
            sort(vt.begin(), vt.end(), greater<int>());

            if (vt.size() >= 3)
                res = max(res, vt[2]);
            if (vt.size() >= 2 && vt[0] > 1)
                res = max(res, min(vt[0] - 1, vt[1]));
            if (vt[0] > 2)
                res = max(res, vt[0] - 2);
        }

        return res;
    }
};
int main(int argc, char const *argv[])
{
    string s = "abcaba";

    Solution solu;

    int res = solu.maximumLength(s);

    cout << "\nres = " << res << endl;

    system("pause");

    return 0;
}
