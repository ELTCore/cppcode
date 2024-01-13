#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        struct ListNode *dummyhead = new ListNode(-1, head);
        struct ListNode *temp = dummyhead;

        while (temp->next != NULL)
        {
            if (temp->next->val == val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }

        return dummyhead->next;
    }
};

// Time spent: 20ms
// Memory usage: 14.6MB