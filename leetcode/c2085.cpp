/*
2085. 统计出现过一次的公共字符串
给你两个字符串数组 words1 和 words2 ，请你返回在两个字符串数组中 都恰好出现一次 的字符串的数目。

示例 1：

输入：words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
输出：2
解释：
- "leetcode" 在两个数组中都恰好出现一次，计入答案。
- "amazing" 在两个数组中都恰好出现一次，计入答案。
- "is" 在两个数组中都出现过，但在 words1 中出现了 2 次，不计入答案。
- "as" 在 words1 中出现了一次，但是在 words2 中没有出现过，不计入答案。
所以，有 2 个字符串在两个数组中都恰好出现了一次。
示例 2：

输入：words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
输出：0
解释：没有字符串在两个数组中都恰好出现一次。
示例 3：

输入：words1 = ["a","ab"], words2 = ["a","a","a","ab"]
输出：1
解释：唯一在两个数组中都出现一次的字符串是 "ab" 。


提示：

1 <= words1.length, words2.length <= 1000
1 <= words1[i].length, words2[j].length <= 30
words1[i] 和 words2[j] 都只包含小写英文字母。
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        int result = 0;
        if (words1.empty() || words2.empty())
        {
            return result;
        }

        unordered_map<string, int> hash1;
        unordered_map<string, int> hash2;

        for (auto &str : words1)
        {
            int &num = hash1[str];
            ++num;
        }

        for (auto &str : words2)
        {
            int &num = hash2[str];
            ++num;
        }

        for (auto it1 = hash1.begin(); it1 != hash1.end(); ++it1)
        {
            if (it1->second > 1)
            {
                continue;
            }

            auto it2 = hash2.find(it1->first);
            if (it2 == hash2.end() || it2->second > 1)
            {
                continue;
            }
            // if (hash2.find(it->first) == hash2.end())
            // {
            //     continue;
            // }
            ++result;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> words1 = {"a", "ab"};
    vector<string> words2 = {"a", "a", "a", "ab"};

    Solution solu;

    int res = solu.countWords(words1, words2);

    cout << "res = " << res << endl;

    system("pause");

    return 0;
}
