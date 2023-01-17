#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class CQueue
{
    int length = 0;
    bool bl_LastTurnIsAppend = 1;
    stack<int> pushStack;
    stack<int> popStack;

public:
    void appendTail(int value)
    {
        if (bl_LastTurnIsAppend != 1)
        {
            for (int i = 0; i < length; i++)
            {
                pushStack.push(popStack.top());
                popStack.pop();
            }
            bl_LastTurnIsAppend = 1;
        }

        pushStack.push(value);
        length++;
    }

    int deleteHead()
    {
        if (length == 0)
            return -1;

        if (bl_LastTurnIsAppend == 1)
        {
            for (int i = 0; i < length; i++)
            {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
            bl_LastTurnIsAppend = 0;
        }

        int pop = popStack.top();
        popStack.pop();
        length--;

        return pop;
    }

    int getLength()
    {
        return length;
    }

    CQueue()
    {
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main(int argc, char const *argv[])
{
    CQueue *test = new CQueue();

    test->appendTail(233);
    test->appendTail(666);

    cout << test->deleteHead() << endl;

    system("pause");

    return 0;
}
