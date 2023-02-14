#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*

    p1 -> p2 -> p3 -> p4 -> t1 -> t2 *-> q1 -> q2 -> q3 -> t1 -> t2

    q1 -> q2 -> q3 -> t1 -> t2 *-> p1 -> p2 -> p3 -> p4 -> t1 -> t2

*/

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        ListNode *pA = headA, *pB = headB;

        while (pA != pB)
        {
            pA = ((pA == nullptr) ? headB : pA->next);
            pB = ((pB == nullptr) ? headA : pB->next);
        }
        return pA;
    }
};
