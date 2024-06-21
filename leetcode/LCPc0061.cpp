/*
LCP 61. 气温变化趋势
简单
相关标签
相关企业
力扣城计划在两地设立「力扣嘉年华」的分会场，气象小组正在分析两地区的气温变化趋势，对于第 i ~ (i+1) 天的气温变化趋势，将根据以下规则判断：

若第 i+1 天的气温 高于 第 i 天，为 上升 趋势
若第 i+1 天的气温 等于 第 i 天，为 平稳 趋势
若第 i+1 天的气温 低于 第 i 天，为 下降 趋势
已知 temperatureA[i] 和 temperatureB[i] 分别表示第 i 天两地区的气温。 组委会希望找到一段天数尽可能多，且两地气温变化趋势相同的时间举办嘉年华活动。请分析并返回两地气温变化趋势相同的最大连续天数。

即最大的 n，使得第 i~i+n 天之间，两地气温变化趋势相同

示例 1：

输入： temperatureA = [21,18,18,18,31] temperatureB = [34,32,16,16,17]

输出：2

解释：如下表所示， 第 2～4 天两地气温变化趋势相同，且持续时间最长，因此返回 4-2=2image.png

示例 2：

输入： temperatureA = [5,10,16,-6,15,11,3] temperatureB = [16,22,23,23,25,3,-16]

输出：3

提示：

2 <= temperatureA.length == temperatureB.length <= 1000
-20 <= temperatureA[i], temperatureB[i] <= 40
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int temperatureTrend(vector<int> &temperatureA, vector<int> &temperatureB)
    {
        auto getTrend = [](int x, int y) -> int
        {
            if (x == y)
            {
                return 0;
            }
            return x < y ? -1 : 1;
        };

        int n = temperatureA.size();
        int ans = 0, cur = 0;
        for (int i = 1; i < n; ++i)
        {
            int ta = getTrend(temperatureA[i - 1], temperatureA[i]);
            int tb = getTrend(temperatureB[i - 1], temperatureB[i]);
            if (ta == tb)
            {
                ++cur;
                ans = max(ans, cur);
            }
            else
            {
                cur = 0;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> temperatureA = {21, 18, 18, 18, 31};
    vector<int> temperatureB = {34, 32, 16, 16, 17};

    Solution solu;

    int res = solu.temperatureTrend(temperatureA, temperatureB);

    cout << "\nres = " << res << endl;

    system("pause");

    return 0;
}
