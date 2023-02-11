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
    ListNode *deleteNode(ListNode *head, int val)
    {
        if (!head)
        {
            return head;
        }
        else if (head.val == val)
        {
            return head->next;
        }

        ListNode *p = head;

        while (p->next)
        {

            if (p->next->val == val)
            {
                p->next = p->next->next;
                return head;
            }

            p = p->next;
        }

        return head;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(4);

    cout << head->val;

    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    head = Solution().deleteNode(head, 5);

    while (head)
    {
        cout << head->val << "\t";
        head = head->next;
    }

    cout << endl;

    system("pause");

    return 0;
}
