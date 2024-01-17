/*
2719. 统计整数数目

给你两个数字字符串 num1 和 num2 ，以及两个整数 max_sum 和 min_sum 。如果一个整数 x 满足以下条件，我们称它是一个好整数：

num1 <= x <= num2
min_sum <= digit_sum(x) <= max_sum.
请你返回好整数的数目。答案可能很大，请返回答案对 109 + 7 取余后的结果。

注意，digit_sum(x) 表示 x 各位数字之和。



示例 1：

输入：num1 = "1", num2 = "12", min_num = 1, max_num = 8
输出：11
解释：总共有 11 个整数的数位和在 1 到 8 之间，分别是 1,2,3,4,5,6,7,8,10,11 和 12 。所以我们返回 11 。
示例 2：

输入：num1 = "1", num2 = "5", min_num = 1, max_num = 5
输出：5
解释：数位和在 1 到 5 之间的 5 个整数分别为 1,2,3,4 和 5 。所以我们返回 5 。


提示：

1 <= num1 <= num2 <= 1022
1 <= min_sum <= max_sum <= 400
*/

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Solution
{
public:
    int count(string num1, string num2, int min_sum, int max_sum)
    {
        int res = 0;
        const int t = pow(10, 9) + 7;

        while (compare(num2, num1))
        {
            int sum = sumOfnum(num1);

            if (min_sum <= sum && sum <= max_sum)
            {
                ++res;
            }

            if (res >= t)
            {
                res %= t;
            };

            add1(num1);

            std::cout << "num1 = " << num1 << endl;
        }

        return res;
    }

    void add1(std::string &str)
    {
        for (int i = str.size() - 1; i >= 0; --i)
        {
            if ('0' <= str[i] && str[i] <= '8')
            {
                ++str[i];
                break;
            }
            else if ('9' == str[i])
            {
                str[i] = '0';
                if (0 == i)
                {
                    str.insert(0, 1, '1');
                    break;
                }
            }
            else
            {
                return;
            }
        }
    }

    // @brief if (number)str1 >= (number)str2 return true
    bool compare(const std::string &str1, const std::string &str2)
    {
        if (str1.size() != str2.size())
        {
            return str1.size() > str2.size();
        }

        return str1 >= str2;
    }

    int sumOfnum(const std::string &str)
    {
        int sum = 0;
        for (const char ch : str)
        {
            sum += ch - '0';
        }
        return sum;
    }

    

};


int main(int argc, char const *argv[])
{
    Solution solution;

    std::string str1 = "4179205230";
    std::string str2 = "7748704426";
    int min_sum = 8;
    int max_sum = 46;

    int res = solution.count(str1, str2, min_sum, max_sum);

    std::cout << "res = " << res << std::endl;

    system("pause");

    return 0;
}
