#include <iostream>
#include <limits>
#include <stack>
#include <map>

using namespace std;

class MinStack
{
private:
    map<int, int> minHashTable;
    stack<int> data;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        auto t = minHashTable.find(x);

        if (t == minHashTable.end())
            minHashTable.insert({x, 1});
        else
            t->second++;

        data.push(x);
    }

    void pop()
    {
        auto t = minHashTable.find(data.top());

        t->second--;
        if (t->second == 0)
            minHashTable.erase(t);

        data.pop();
    }

    int top()
    {
        return data.top();
    }

    int min()
    {
        return minHashTable.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main(int argc, char const *argv[])
{
    /* code */
    map<int, char> testTable;
    testTable.insert({2, 'a'});
    testTable.insert({3, 'b'});
    testTable.insert({4, 'c'});

    cout << testTable.find('c')->first << endl;

    system("pause");
    return 0;
}
