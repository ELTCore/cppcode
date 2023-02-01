#include <iostream>

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
    bool isSymmetric(TreeNode *root)
    {
        return check(root, root);
    }

    bool check(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        
        //p指针和q指针一开始都指向这棵树的根，随后p右移时，q左移，p左移时，q右移。每次检查当前p和q节点的值是否相等，如果相等再判断左右子树是否对称。
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
};