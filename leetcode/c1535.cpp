/*
1535. 找出数组游戏的赢家
中等
相关标签
相关企业
提示
给你一个由 不同 整数组成的整数数组 arr 和一个整数 k 。

每回合游戏都在数组的前两个元素（即 arr[0] 和 arr[1] ）之间进行。比较 arr[0] 与 arr[1] 的大小，较大的整数将会取得这一回合的胜利并保留在位置 0 ，较小的整数移至数组的末尾。当一个整数赢得 k 个连续回合时，游戏结束，该整数就是比赛的 赢家 。

返回赢得比赛的整数。

题目数据 保证 游戏存在赢家。

示例 1：

输入：arr = [2,1,3,5,4,6,7], k = 2
输出：5
解释：一起看一下本场游戏每回合的情况：

|   回合   |      数组       |   获胜整数   |   连胜回合数  |
|   1      | [2,1,3,5,4,6,7] |    2        |     1       |
|   2      | [2,3,5,4,6,7,1] |    3        |     1       |
|   3      | [3,5,4,6,7,1,2] |    5        |     1       |
|   4      | [5,4,6,7,1,2,3] |    5        |     2       |

因此将进行 4 回合比赛，其中 5 是赢家，因为它连胜 2 回合。


示例 2：

输入：arr = [3,2,1], k = 10
输出：3
解释：3 将会在前 10 个回合中连续获胜。
示例 3：

输入：arr = [1,9,8,2,3,7,6,4,5], k = 7
输出：9
示例 4：

输入：arr = [1,11,22,33,44,55,66,77,88,99], k = 1000000000
输出：99


提示：

2 <= arr.length <= 10^5
1 <= arr[i] <= 10^6
arr 所含的整数 各不相同 。
1 <= k <= 10^9
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int n = arr.size();
        int cnt = 0, idx = 0;
        for (int i = 1; i < n && cnt < k; i++)
        {
            if (arr[idx] > arr[i])
            {
                cnt++;
            }
            else
            {
                cnt = 1;
                idx = i;
            }
        }
        return arr[idx];
    }
    /*
        int getWinner(vector<int> &arr, int k)
        {
            int res = -1;

            if (k >= arr.size())
            {
                int maxNum = INT32_MIN;
                for (int n : arr)
                {
                    maxNum = std::max(maxNum, n);
                }
                return maxNum;
            }

            for (int i = 0; i < arr.size(); ++i)
            {
                int wt = 0; // wt -> winTimes
                if (i != 0)
                {
                    ++wt;
                }

                cout << "\nStart: " << arr[i] << " ";
                for (int j = 1; j <= k && wt < k; ++j, ++wt)
                {
                    int t = (i + j) % arr.size();
                    cout << " " << arr[t];
                    if (arr[i] < arr[t])
                    {
                        break;
                    }
                }

                if (wt >= k)
                {
                    return arr[i];
                }

                cout << "\t winTimes: " << wt << endl;
            }

            return res;
        }
        */
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 9, 8, 2, 3, 7, 6, 4, 5};
    int k = 7;

    // vector<int> arr = {1, 25, 35, 42, 68, 70};
    // int k = 1;

    // vector<int> arr = {963, 541, 112, 470, 285, 93, 24, 953, 536, 363, 575, 522, 390, 9, 873, 940, 921, 198, 75};
    // int k = 6;

    Solution solu;
    int res = solu.getWinner(arr, k);

    cout << "\nres = " << res << endl;

    system("pause");

    return 0;
}
