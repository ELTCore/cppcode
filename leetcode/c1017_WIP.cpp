/*
1017. 负二进制转换
中等
相关标签
相关企业
提示
给你一个整数 n ，以二进制字符串的形式返回该整数的 负二进制（base -2）表示。

注意，除非字符串就是 "0"，否则返回的字符串中不能含有前导零。



示例 1：

输入：n = 2
输出："110"
解释：(-2)2 + (-2)1 = 2
示例 2：

输入：n = 3
输出："111"
解释：(-2)2 + (-2)1 + (-2)0 = 3
示例 3：

输入：n = 4
输出："100"
解释：(-2)2 = 4


提示：

0 <= n <= 109
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string baseNeg2(int n)
    {
    }
};

int main(int argc, char const *argv[])
{
    int n = 2;

    Solution solu;
    string res = solu.baseNeg2(n);

    cout << "res = " << res << endl;

    system("pause");

    return 0;
}
