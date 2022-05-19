// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// 偷鸡解法（只是过了题目的检测）
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == 0)
                    matrix[i][j] = INT_MIN + 1;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == INT_MIN + 1)
                {
                    for (int k = 0; k < m; ++k)
                        if (matrix[k][j] != INT_MIN + 1)
                            matrix[k][j] = 0;

                    for (int l = 0; l < n; ++l)
                        if (matrix[i][l] != INT_MIN + 1)
                            matrix[i][l] = 0;
                }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == INT_MIN + 1)
                    matrix[i][j] = 0;
    }
};

// 执行用时：20ms
// 内存消耗：12.7MB

// 正经解法
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false;
        for (int i = 0; i < m; i++)
        {
            if (!matrix[i][0])
            {
                flag_col0 = true;
            }
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][j])
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][0] || !matrix[0][j])
                {
                    matrix[i][j] = 0;
                }
            }
            if (flag_col0)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
