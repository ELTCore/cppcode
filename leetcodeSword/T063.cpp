#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
        {
            return 0;
        }

        int maxProfit = 0;
        int minPrice = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            int profit = prices[i] - prices[minPrice];

            if (profit > maxProfit)
            {
                maxProfit = profit;
            }
            if (prices[i] < prices[minPrice])
            {
                minPrice = i;
            }
        }

        return maxProfit;
    }
};