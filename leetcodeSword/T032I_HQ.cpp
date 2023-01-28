#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> levelOrder(TreeNode *root)
    {
        vector<int> res;

        if (root == NULL)
        {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);

        while (q.empty() == false)
        {
            res.push_back(q.front()->val);
            if (q.front()->left != NULL)
            {
                q.push(q.front()->left);
            }

            if (q.front()->right != NULL)
            {
                q.push(q.front()->right);
            }

            q.pop();
        }

        return res;
    }
};