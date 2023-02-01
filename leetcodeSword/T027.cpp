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
    TreeNode *mirrorTree(TreeNode *root)
    {
        if (!root)
        {
            return root;
        }

        if (root->left || root->right)
        {
            TreeNode *t = root->right;

            root->right = root->left;
            root->left = t;
        }

        mirrorTree(root->left);
        mirrorTree(root->right);

        return root;
    }
};