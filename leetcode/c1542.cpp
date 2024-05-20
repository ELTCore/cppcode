/*
1542. 找出最长的超赞子字符串
困难
相关标签
相关企业
提示
给你一个字符串 s 。请返回 s 中最长的 超赞子字符串 的长度。

「超赞子字符串」需满足满足下述两个条件：

该字符串是 s 的一个非空子字符串
进行任意次数的字符交换后，该字符串可以变成一个回文字符串


示例 1：

输入：s = "3242415"
输出：5
解释："24241" 是最长的超赞子字符串，交换其中的字符后，可以得到回文 "24142"
示例 2：

输入：s = "12345678"
输出：1
示例 3：

输入：s = "213123"
输出：6
解释："213123" 是最长的超赞子字符串，交换其中的字符后，可以得到回文 "231132"
示例 4：

输入：s = "00"
输出：2


提示：

1 <= s.length <= 10^5
s 仅由数字组成
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    // 前缀和 + 状态压缩  子串中最多有一个数字为奇数，其余数字皆为偶数
    int longestAwesome(string s)
    {
        int n = s.size();
        int ans = 1;
        vector<int> mp(1024, -2); // 存放异或和及对应下标
        mp[0] = -1;

        for (int i = 0, mask = 0; i < n; i++)
        {                              // 枚举以s[i]结尾满足条件的字符串
            mask ^= 1 << (s[i] - '0'); // 以s[i]结尾且每个字符均为偶数个

            if (mp[mask] != -2)
            {
                ans = max(ans, i - mp[mask]);
            }

            for (int j = 0; j < 10; j++)
            { // 寻找以s[i]结尾且每个字符均为奇数个
                int premask = mask ^ (1 << j);
                if (mp[premask] != -2)
                    ans = max(ans, i - mp[premask]);
            }

            if (mp[mask] == -2)
            {
                mp[mask] = i;
            }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s = "9498331"; // res = 3

    Solution solu;
    int res = solu.longestAwesome(s);

    cout << "\nres = " << res << endl;

    system("pause");

    return 0;
}
