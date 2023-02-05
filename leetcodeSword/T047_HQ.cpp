#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int column = grid[0].size();

        for (int i = 1; i < column; ++i)
        {
            grid[0][i] += grid[0][i - 1];
        }

        for (int i = 1; i < row; ++i)
        {
            grid[i][0] += grid[i - 1][0];
        }

        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < column; ++j)
            {
                grid[i][j] += max(grid[i][j - 1], grid[i - 1][j]);
            }
        }

        return grid[row - 1][column - 1];
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> test = {{0, 0}, {0, 1}};

    cout << "test[1][1] = " << test[1][1] << endl;

    system("pause");

    return 0;
}
