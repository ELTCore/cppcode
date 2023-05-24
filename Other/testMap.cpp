#include <iostream>
#include <map>

using namespace std;


// map<key, value>
// 默认情况下 map 按照 key 从小到大排序

int main(int argc, char const *argv[])
{
    multimap<int, int> t;

    t.emplace(3, 1);
    t.emplace(2, 4);
    t.emplace(1, 5);

    for (auto it : t)
    {
        cout << "it->first = " << it.first << "\tit->second = " << it.second << endl;
    }

    cin.get();

    return 0;
}
