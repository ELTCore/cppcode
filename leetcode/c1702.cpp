/*
1702. 修改后的最大二进制字符串
中等
相关标签
相关企业
提示
给你一个二进制字符串 binary ，它仅有 0 或者 1 组成。你可以使用下面的操作任意次对它进行修改：

操作 1 ：如果二进制串包含子字符串 "00" ，你可以用 "10" 将其替换。
比方说， "00010" -> "10010"
操作 2 ：如果二进制串包含子字符串 "10" ，你可以用 "01" 将其替换。
比方说， "00010" -> "00001"
请你返回执行上述操作任意次以后能得到的 最大二进制字符串 。如果二进制字符串 x 对应的十进制数字大于二进制字符串 y 对应的十进制数字，那么我们称二进制字符串 x 大于二进制字符串 y 。



示例 1：

输入：binary = "000110"
输出："111011"
解释：一个可行的转换为：
"000110" -> "000101"
"000101" -> "100101"
"100101" -> "110101"
"110101" -> "110011"
"110011" -> "111011"
示例 2：

输入：binary = "01"
输出："01"
解释："01" 没办法进行任何转换。


提示：

1 <= binary.length <= 105
binary 仅包含 '0' 和 '1' 。
*/

#include <iostream>

using namespace std;

class Solution
{
public:
    string maximumBinaryString(string binary)
    {
        int n = binary.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (binary[i] == '0')
            {
                while (j <= i || (j < n && binary[j] == '1'))
                {
                    j++;
                }
                if (j < n)
                {
                    binary[j] = '1';
                    binary[i] = '1';
                    binary[i + 1] = '0';
                }
            }
        }
        return binary;
    }
};
/*
class Solution
{
public:
    string maximumBinaryString(string binary)
    {
        if (binary.size() < 1)
        {
            return binary;
        }

        int count0 = 0;
        for (const char &ch : binary)
        {
            if (ch == '0')
            {
                ++count0;
            }
        }

        while (true)
        {
            cout << "binary = " << binary << endl;
            bool deal00 = dealString00(binary);
            if (deal00 == true)
            {
                --count0;
                continue;
            }
            if (count0 <= 1)
            {
                break;
            }

            bool deal10 = dealString10(binary);
            if (deal10 == false)
            {
                break;
            }
        }
        return binary;
    }

    bool dealString00(string &str)
    {
        for (int i = 0, j = 1; j < str.size(); ++i, ++j)
        {
            if (str[i] == '0' && str[j] == '0')
            {
                str[i] = '1';
                return true;
            }
        }
        return false;
    }

    bool dealString10(string &str)
    {
        for (int i = str.size() - 2, j = str.size() - 1; i >= 0; --i, --j)
        {
            if (str[i] == '1' && str[j] == '0')
            {
                str[i] = '0';
                str[j] = '1';
                return true;
            }
        }
        return false;
    }
};

*/

int main(int argc, char const *argv[])
{
    string binary = "000110";
    Solution solu;
    string res = solu.maximumBinaryString(binary);

    cout << "res = " << res << endl;

    system("pause");

    return 0;
}
