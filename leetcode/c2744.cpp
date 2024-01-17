/*2744. 最大字符串配对数目
简单

提示
给你一个下标从 0 开始的数组 words ，数组中包含 互不相同 的字符串。

如果字符串 words[i] 与字符串 words[j] 满足以下条件，我们称它们可以匹配：

字符串 words[i] 等于 words[j] 的反转字符串。
0 <= i < j < words.length
请你返回数组 words 中的 最大 匹配数目。

注意，每个字符串最多匹配一次。

示例 1：

输入：words = ["cd","ac","dc","ca","zz"]
输出：2
解释：在此示例中，我们可以通过以下方式匹配 2 对字符串：
- 我们将第 0 个字符串与第 2 个字符串匹配，因为 word[0] 的反转字符串是 "dc" 并且等于 words[2]。
- 我们将第 1 个字符串与第 3 个字符串匹配，因为 word[1] 的反转字符串是 "ca" 并且等于 words[3]。
可以证明最多匹配数目是 2 。
示例 2：

输入：words = ["ab","ba","cc"]
输出：1
解释：在此示例中，我们可以通过以下方式匹配 1 对字符串：
- 我们将第 0 个字符串与第 1 个字符串匹配，因为 words[1] 的反转字符串 "ab" 与 words[0] 相等。
可以证明最多匹配数目是 1 。
示例 3：

输入：words = ["aa","ab"]
输出：0
解释：这个例子中，无法匹配任何字符串。


提示：

1 <= words.length <= 50
words[i].length == 2
words 包含的字符串互不相同。
words[i] 只包含小写英文字母。

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        int res = 0;
        unordered_map<string, int> hash;

        for (const string &str : words)
        {
            int &num = hash[str];
            ++num;
        }

        for (auto it : hash)
        {
            const string &str = it.first;
            int &num = it.second;

            if (num <= 0)
            {
                continue;
            }

            string reStr = str;
            reverse(reStr.begin(), reStr.end());

            auto reIt = hash.find(reStr);
            if (reIt != hash.end() && reIt->first != it.first && reIt->second > 0)
            {
                ++res;
                --(reIt->second);
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> words = {"cd", "ac", "dc", "ca", "zz"};

    Solution solution;

    int res = solution.maximumNumberOfStringPairs(words);

    cout << "res = " << res << endl;

    system("pause");

    return 0;
}
