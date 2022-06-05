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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head;

        struct ListNode *newHead = head;
        struct ListNode *flag = head;
        auto t_val = head->val;

        while (newHead->next != nullptr)
            newHead = newHead->next;

        while (flag != newHead)
        {
            struct ListNode *ad = new ListNode(flag->val, newHead->next);
            newHead->next = ad;
            flag = flag->next;
        }
        return newHead;
    }
};

// Time spent:8ms
// Memory Usage:8.3MB