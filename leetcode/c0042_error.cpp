/*
42. 接雨水
困难
相关标签
相关企业
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例 1：
  |
  |
3 |                                      @@@@@@
  |                                      @@@@@@
  |                                      @@@@@@
2 |                @@@@@@1111111111111111@@@@@@@@@@@11111@@@@@@
  |                @@@@@@1111111111111111@@@@@@@@@@@11111@@@@@@
  |                @@@@@@1111111111111111@@@@@@@@@@@11111@@@@@@
1 |     @@@@@@11111@@@@@@@@@@@11111@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  |     @@@@@@11111@@@@@@@@@@@11111@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  |_____@@@@@@11111@@@@@@@@@@@11111@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@_____

输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（1部分表示雨水）。
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9


提示：

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
        {
            return 0;
        }

        int res_vec = 0;
        int left_index = 0;
        int left_height = 0;

        // 确定初次计算的起点
        for (int i = 0; i < height.size(); ++i)
        {
            if (height[i] == 0)
            {
                if (i == height.size() - 1)
                {
                    return 0;
                }
                continue;
            }
            left_index = i;
            left_height = height[i];
            break;
        }

        while (left_index < height.size() - 1)
        {
            int right_index = left_index + 1;
            int temp_vec = 0;
            for (; right_index < height.size(); ++right_index)
            {
                if (height[right_index] < left_height)
                {
                    continue;
                }
                temp_vec += get_max_vec(height, left_index, right_index);
                left_index = right_index;
                left_height = height[right_index];
                break;
            }

            if (0 == temp_vec) // 右侧柱子全部比自己低，接不到水
            {
                if (left_height > height[left_index + 1])
                {
                    left_height = height[left_index + 1];
                }
                else
                {
                    ++left_index;
                }
            }
            else
            {
                res_vec += temp_vec;
                left_index = right_index;
            }
        }

        return res_vec;
    }

private:
    int get_max_vec(const vector<int> &height, const int &left_index, const int &right_index)
    {
        cout << "\nget_max_vec: left:" << left_index << "\tright:" << right_index << endl;

        int res_vec = 0;
        int max_height = min(height[left_index], height[right_index]);

        for (int i = left_index + 1; i < right_index; ++i)
        {
            res_vec += max_height - height[i];
        }

        return res_vec;
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> height = {4, 2, 0, 3, 2, 5};

    Solution solu;

    int res = solu.trap(height);

    cout << "\nres = " << res << endl;

    system("pause");

    return 0;
}
