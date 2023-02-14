#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        if (!head || !(head->next))
        {
            return head;
        }

        ListNode *p = head;
        ListNode *q = head;

        for (int i = 0; i < k; ++i)
        {
            if (q->next)
            {
                q = q->next;
            }
            else
            {
                return head;
            }
        }

        while (q)
        {
            p = p->next;
            q = q->next;
        }

        return p;
    }
};