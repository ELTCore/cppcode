#include <iostream>

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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *p = head->next;
        ListNode *q = head->next;
        ListNode *res = head;
        res->next = NULL;

        while (p != NULL)
        {
            q = q->next;
            p->next = res;
            res = p;
            p = q;
        }

        return res;
    }
};