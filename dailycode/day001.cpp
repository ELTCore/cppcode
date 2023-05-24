#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
#include <cmath>
#include <queue>

using namespace std;

class Solution
{
public:
    int storeWater(vector<int> &bucket, vector<int> &vat)
    {
        int n = bucket.size();
        priority_queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (bucket[i] == 0 && vat[i])
            {
                ++cnt;
                ++bucket[i];
            }
            if (vat[i] > 0)
            {
                q.emplace((vat[i] + bucket[i] - 1) / bucket[i], i);
            }
        }
        if (q.empty())
        {
            return 0;
        }
        int res = INT_MAX;
        while (cnt < res)
        {
            int v = q.top().first;
            int i = q.top().second;
            res = min(res, cnt + v);
            if (v == 1)
            {
                break;
            }
            q.pop();
            int t = (vat[i] + v - 2) / (v - 1);
            cnt += t - bucket[i];
            bucket[i] = t;
            q.emplace((vat[i] + bucket[i] - 1) / bucket[i], i);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    // set<int> setInputTimes;

    // setInputTimes.insert(1);
    // setInputTimes.insert(2);
    // setInputTimes.insert(3);

    // auto it = setInputTimes.end();
    // auto p = it--;

    // cout << "p = " << *p << endl;

    vector<int> v1 = {9, 0, 1};
    vector<int> v2 = {0, 2, 2};

    cout << Solution().storeWater(v1, v2) << endl;

    cin.get();

    return 0;
}
// class Solution
// {
// public:
//     int storeWater(vector<int> &bucket, vector<int> &vat)
//     {
//         if (bucket.size() == 0 || vat.size() == 0)
//         {
//             return 0;
//         }

//         int minTimes = INT32_MAX;
//         int upgradeTimes = 0;
//         int current = 0;
//         multimap<int, int> hashInputTimes;

//         for (int i = 0; i < bucket.size(); ++i)
//         {
//             if (vat[i] == 0)
//             {
//                 continue;
//             }
//             if (bucket[i] == 0)
//             {
//                 ++upgradeTimes;
//                 bucket[i] += 1;
//             }
//             hashInputTimes.emplace(ceil(double(vat[i]) / double(bucket[i])), i);
//         }

//         if (hashInputTimes.size() == 0)
//         {
//             return 0;
//         }

//         if ((--hashInputTimes.end())->first == hashInputTimes.begin()->first)
//         {
//             return hashInputTimes.begin()->first + upgradeTimes;
//         }

//         while (current < minTimes)
//         {
//             cout << "hashInputTimes.begin()->second = "
//                  << hashInputTimes.begin()->first << endl;

//             cout << "hashInputTimes.end()->second = "
//                  << (--hashInputTimes.end())->first << endl;

//             auto it = --hashInputTimes.end();
//             int i = it->second;
//             hashInputTimes.erase(it);
//             hashInputTimes.emplace(ceil(double(vat[i]) / double(bucket[i] + 1)), i);

//             ++upgradeTimes;
//             it = --hashInputTimes.end();
//             int most = it->first;

//             cout << "most = " << most << endl;

//             current = most + upgradeTimes;

//             cout << "current = " << current << endl;

//             if (current < minTimes)
//             {
//                 minTimes = current;
//                 cout << "minTimes = " << minTimes << endl;
//             }
//         }

//         return minTimes;
//     }
// };
