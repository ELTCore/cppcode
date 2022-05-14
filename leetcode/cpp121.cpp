// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int currentProfit = 0, result = 0;
        int currentPrice = prices[0];

        if (prices.size() <= 1)
            return result;

        for (int i = 1; i < prices.size(); i++)
        {
            if (currentPrice <= prices[i])
            {
                currentProfit = prices[i] - currentPrice;

                if (result < currentProfit)
                    result = currentProfit;
            }

            if (currentPrice > prices[i])
            {
                currentPrice = prices[i];
                currentProfit = 0;

                if (result < currentProfit)
                    result = currentProfit;

                continue;
            }
        }

        return result;
    }
};

// 执行用时：108ms
// 内存消耗：91MB