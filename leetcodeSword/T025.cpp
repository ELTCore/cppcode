#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
        {
            cout << "debug: l1 is nullptr" << endl;
            return l2;
        }
        else if (!l2)
        {
            cout << "debug: l2 is nullptr" << endl;
            return l1;
        }

        ListNode *head = new ListNode(-1);
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *r = head;

        while (p && q)
        {
            cout << "debug: neither p or q is nullptr" << endl;

            r->next = new ListNode(1);
            r = r->next;

            if (p->val <= q->val)
            {
                cout << "debug: p->val is " << p->val << " <= q->val is" << q->val << endl;
                r->val = p->val;
                cout << "debug: r->val = " << r->val << endl;
                p = p->next;
            }
            else
            {
                cout << "debug: p->val is " << p->val << " > q->val is" << q->val << endl;
                r->val = q->val;
                cout << "debug: r->val = " << r->val << endl;
                q = q->next;
            }
        }

        if (p)
        {
            cout << "debug: p still has next" << endl;

            while (p)
            {
                r->next = new ListNode(p->val);
                r = r->next;
                p = p->next;
            }
        }
        else
        {
            cout << "debug: q still has next" << endl;

            while (q)
            {
                r->next = new ListNode(q->val);
                r = r->next;
                q = q->next;
            }
        }

        return head->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *test;

    // error
    test->next = new ListNode(233);

    cout << test->val << endl;

    system("pause");

    return 0;
}
