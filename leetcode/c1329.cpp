/*
1329. 将矩阵按对角线排序
中等
相关标签
相关企业
提示
矩阵对角线 是一条从矩阵最上面行或者最左侧列中的某个元素开始的对角线，沿右下方向一直到矩阵末尾的元素。例如，矩阵 mat 有 6 行 3 列，从 mat[2][0] 开始的 矩阵对角线 将会经过 mat[2][0]、mat[3][1] 和 mat[4][2] 。

给你一个 m * n 的整数矩阵 mat ，请你将同一条 矩阵对角线 上的元素按升序排序后，返回排好序的矩阵。


示例 1：

 3  3  1  1          1  1  1  1
 2  2  1  2   --->   1  2  2  2
 1  1  1  2          1  2  3  3

输入：mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
输出：[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
示例 2：

输入：mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
输出：[[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]


提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> diag(m + n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                diag[i - j + m].push_back(mat[i][j]);
            }
        }
        for (auto &d : diag)
        {
            sort(d.rbegin(), d.rend());
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                mat[i][j] = diag[i - j + m].back();
                diag[i - j + m].pop_back();
            }
        }
        return mat;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> mat = {
        {11, 25, 66, 1, 69, 7} //    { 5,17, 4, 1,52, 7}
        ,
        {23, 55, 17, 45, 15, 52} //  {11,11,25,45, 8,69}
        ,
        {75, 31, 36, 44, 58, 8} //   {14,23,25,44,58,15}
        ,
        {22, 27, 33, 25, 68, 4} //   {22,27,31,36,50,66}
        ,
        {84, 28, 14, 11, 5, 50}}; // {84,28,75,33,55,68}

    Solution solu;

    vector<vector<int>> res = solu.diagonalSort(mat);

    cout << endl;

    for (auto &v : res)
    {
        for (int &i : v)
        {
            cout << i << "  ";
        }
        cout << endl;
    }

    cout << endl;

    system("pause");

    return 0;
}
