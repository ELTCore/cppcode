// 请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
//  
// 注意：
// 一个有效的数独（部分已被填充）不一定是可解的。
// 只需要根据以上规则，验证已经填入的数字是否有效即可。
// 空白格用 '.' 表示。

// ascii  ',' == 46
// ascii  '0' == 48

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool row_check = true;
        bool column_check = true;
        bool soduku_check = true;

        // Check row
        for (int i = 0; i < 9; ++i)
        {
            vector<int> num(10, 0);

            for (int j = 0; j < 9; ++j)
            {
                int t = board[i][j];

                if (t == 46)
                    continue;

                if (num[t - 49] == 0)
                    num[t - 49]++;
                else
                {
                    row_check = false;
                    cout << "row_check false" << endl;
                }
            }
        }

        // Check column
        for (int i = 0; i < 9; ++i)
        {
            vector<int> num(10, 0);

            for (int j = 0; j < 9; ++j)
            {
                int t = board[j][i];

                if (t == 46)
                    continue;

                if (num[t - 49] == 0)
                    num[t - 49]++;
                else
                {
                    column_check = false;
                    cout << "column_check false" << endl;
                }
            }
        }

        // Check 3*3
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                vector<int> num(10, 0);
                vector<char> t(9);

                t[0] = board[i * 3][j * 3];
                t[1] = board[i * 3][j * 3 + 1];
                t[2] = board[i * 3][j * 3 + 2];
                t[3] = board[i * 3 + 1][j * 3];
                t[4] = board[i * 3 + 1][j * 3 + 1];
                t[5] = board[i * 3 + 1][j * 3 + 2];
                t[6] = board[i * 3 + 2][j * 3];
                t[7] = board[i * 3 + 2][j * 3 + 1];
                t[8] = board[i * 3 + 2][j * 3 + 2];

                for (int k = 0; k < 9; ++k)
                {
                    if (t[k] == 46)
                    {
                        cout << "skip" << endl;
                        continue;
                    }

                    if (num[t[k] - 49] == 0)
                    {
                        num[t[k] - 49]++;
                        cout << "num[" << t[k] - 49 << "] = " << num[t[k] - 49] << endl;
                    }
                    else
                    {
                        soduku_check = false;
                        cout << "soduku_check false" << endl;
                    }
                }
            }
        }

        return (row_check && column_check && soduku_check);
    }
};

// 执行用时：52ms
// 内存消耗：18.8MB