/*
857. 雇佣 K 名工人的最低成本
困难
相关标签
相关企业
有 n 名工人。 给定两个数组 quality 和 wage ，其中，quality[i] 表示第 i 名工人的工作质量，其最低期望工资为 wage[i] 。

现在我们想雇佣 k 名工人组成一个工资组。在雇佣 一组 k 名工人时，我们必须按照下述规则向他们支付工资：

对工资组中的每名工人，应当按其工作质量与同组其他工人的工作质量的比例来支付工资。
工资组中的每名工人至少应当得到他们的最低期望工资。
给定整数 k ，返回 组成满足上述条件的付费群体所需的最小金额 。在实际答案的 10-5 以内的答案将被接受。。



示例 1：

输入： quality = [10,20,5], wage = [70,50,30], k = 2
输出： 105.00000
解释： 我们向 0 号工人支付 70，向 2 号工人支付 35。
示例 2：

输入： quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
输出： 30.66667
解释： 我们向 0 号工人支付 4，向 2 号和 3 号分别支付 13.33333。


提示：

n == quality.length == wage.length
1 <= k <= n <= 104
1 <= quality[i], wage[i] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size(), sum_q = 0;
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        // "std::ranges" need c++20
        ranges::sort(id, [&](int i, int j)
                     { return wage[i] * quality[j] < wage[j] * quality[i]; }); // 按照 r 值排序
        priority_queue<int> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(quality[id[i]]);
            sum_q += quality[id[i]];
        }
        double ans = sum_q * ((double)wage[id[k - 1]] / quality[id[k - 1]]); // 选 r 值最小的 k 名工人
        for (int i = k; i < n; i++)
        { // 后面的工人 r 值更大
            int q = quality[id[i]];
            if (q < pq.top())
            { // 但是 sum_q 可以变小，从而可能得到更优的答案
                sum_q -= pq.top() - q;
                pq.pop();
                pq.push(q);
                ans = min(ans, sum_q * ((double)wage[id[i]] / q));
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
