#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;

        result.push_back(vector<int>(1));
        result[0][0] = 1;

        for (int i = 1; i < numRows; ++i)
        {
            vector<int> tempRow(i + 1);

            tempRow[0] = 1;
            tempRow[i] = 1;

            for (int j = 1; j <= i / 2; j++)
            {
                tempRow[j] = result[i - 1][j - 1] + result[i - 1][j];
                tempRow[i - j] = result[i - 1][j - 1] + result[i - 1][j];
            }

            result.push_back(tempRow);
        }

        return result;
    }
};

// 执行用时：0ms
// 内存消耗：6.4ms


int main(int argc, char const *argv[])
{
    vector<vector<int>> result = Solution().generate(1);

    cout << result[0][0] << endl;

    system("pause");

    return 0;
}
