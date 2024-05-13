/*
994. 腐烂的橘子
中等
相关标签
相关企业
在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。

返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

示例 1：

2 1 1      2 2 1     2 2 2     2 2 2     2 2 2
1 1 0  --> 2 1 0 --> 2 2 0 --> 2 2 0 --> 2 2 0
0 1 1      0 1 1     0 1 1     0 2 1     0 2 2

输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：

输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
示例 3：

输入：grid = [[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。


提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] 仅为 0、1 或 2
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

class Solution
{
private:
    // 记录橘子全部腐烂所需时间
    int badTime[10][10];
    int cnt = 0; // 记录新鲜橘子数
    // 方向向量上下组合形成向右、向左，向下，向上
    int dir_x[4] = {0, 0, 1, -1};
    int dir_y[4] = {1, -1, 0, 0};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        memset(badTime, -1, sizeof(badTime));
        // 广度优先搜索必用队列，存入烂橘子
        queue<pair<int, int>> badOranges;

        // 烂橘子存入队列+设置腐烂时间+记录新鲜橘子数
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 2)
                {
                    badOranges.emplace(i, j);
                    // 烂橘子的分钟数为0
                    badTime[i][j] = 0;
                }
                else if (grid[i][j] == 1)
                {
                    ++cnt; // 新鲜橘子计数
                }
            }
        }

        int ans = 0;
        // 开始BFS
        while (!badOranges.empty())
        {
            auto [row, col] = badOranges.front();
            badOranges.pop();
            // 通过方向向量开始感染
            for (int i = 0; i < 4; ++i)
            {
                // 相邻橘子坐标
                int dx = row + dir_x[i];
                int dy = col + dir_y[i];
                // 越界访问，已经访问过，空单元格统统跳过
                if (dx < 0 || dx >= m || dy < 0 || dy >= n || badTime[dx][dy] != -1 || grid[dx][dy] == 0)
                {
                    continue;
                }
                // 因为不相关的都跳过了，那么剩下的就是相邻橘子了
                badTime[dx][dy] = badTime[row][col] + 1;
                badOranges.emplace(dx, dy);
                if (grid[dx][dy] == 1)
                {
                    --cnt;
                    ans = badTime[dx][dy];
                    if (cnt == 0)
                        break;
                }
            }
        }
        return cnt == 0 ? ans : -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{1, 2, 1}, {1, 1, 0}, {0, 1, 1}};

    Solution solu;

    int res = solu.orangesRotting(grid);

    cout << "\nres = " << res << endl;

    system("pause");

    return 0;
}
