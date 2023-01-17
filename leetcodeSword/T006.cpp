#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        ListNode *p = head;
        vector<int> result;
        stack<int> temp;

        while(p != NULL)
        {
            temp.push(p->val);
            p = p->next; 
        }

        while (temp.empty() == false)
        {
            result.push_back(temp.top());
            temp.pop();
        }

        return result;
    }
};