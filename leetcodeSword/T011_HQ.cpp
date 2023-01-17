#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high)
        {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] < numbers[high])
            {
                high = pivot;
            }
            else if (numbers[pivot] > numbers[high])
            {
                low = pivot + 1;
            }
            else
            {
                high -= 1;
            }
        }
        return numbers[low];
    }
};

// class Solution
// {
// public:
//     int minArray(vector<int> &numbers)
//     {
//         if (numbers.size() == 0)
//         {
//             return -1;
//         }

//         int min = numbers.size() - 1;

//         while (min != 0 && numbers[min - 1] <= numbers[min])
//         {
//             min--;
//         }

//         return numbers[min];
//     }
// };