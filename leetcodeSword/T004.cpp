#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[0].size())
        {
            if (matrix[i][j] > target)
                i--;
            else if (matrix[i][j] < target)
                j++;
            else
                return true;
        }
        return false;
    }
};

// class Solution
// {
// public:
//     bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
//     {
//         if (matrix.size() == 0 || matrix[0].size() == 0)
//         {
//             return false;
//         }

//         int r = matrix.size();
//         int c = matrix[0].size();

//         for (int i = 0; i < r; i++)
//         {
//             if (matrix[i].back() < target)
//             {
//                 continue;
//             }
//             for (int j = 0; j < c; j++)
//             {
//                 if (matrix[i][j] == target)
//                 {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
