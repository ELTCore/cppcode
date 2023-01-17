#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> cacheNode;

    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        if (!cacheNode.count(head))
        {
            Node *headNew = new Node(head->val);
            cacheNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cacheNode[head];
    }
};

/* ERROR
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *res = NULL;
        if (head == NULL)
            return res;

        res = new Node(head->val);

        unordered_map<Node *, int> headNodeMap;
        unordered_map<Node *, int> resNodeMap;

        headNodeMap.insert({head, 1});
        resNodeMap.insert({res, 1});

        int index = 2;

        Node *p = head->next;
        Node *q = res;

        while (p != NULL)
        {
            q->next = new Node(p->val);
            q = q->next;
            resNodeMap.insert({q, index});

            headNodeMap.insert({p, index});
            p = p->next;

            index++;
        }
        q->next = NULL;
        q = res;

        for (auto node : headNodeMap)
        {
            auto itHead = headNodeMap.find(node.first->random);
            auto itRes = resNodeMap.find(itHead->first);
            q->random = itRes->first;
            q = q->next;
        }

        return res;
    }
}; */

int main(int argc, char const *argv[])
{
    unordered_map<char, int> testMap;

    testMap.insert({'a', 4});
    testMap.insert({'b', 3});
    testMap.insert({'c', 2});

    auto it = testMap.find('b');

    cout << it->first << " = " << it->second << endl;
    // cout << testMap.at(2) << endl;

    system("pause");
    return 0;
}
