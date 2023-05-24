#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool checkSufficientLeaf(TreeNode *node, int sum, int limit)
    {
        if (!node)
        {
            return false;
        }
        if (node->left == nullptr && node->right == nullptr)
        {
            return node->val + sum >= limit;
        }
        bool haveSufficientLeft = checkSufficientLeaf(node->left, sum + node->val, limit);
        bool haveSufficientRight = checkSufficientLeaf(node->right, sum + node->val, limit);
        if (!haveSufficientLeft)
        {
            node->left = nullptr;
        }
        if (!haveSufficientRight)
        {
            node->right = nullptr;
        }
        return haveSufficientLeft || haveSufficientRight;
    }

    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        bool haveSufficient = checkSufficientLeaf(root, 0, limit);
        return haveSufficient ? root : nullptr;
    }
};

// class Solution
// {
// public:
//     TreeNode *sufficientSubset(TreeNode *root, int limit)
//     {

//         dfs(root, root->val, limit);
//         deleteNULLNode(root);

//         return root;
//     }

//     void dfs(TreeNode *node, int value, const int &limit)
//     {
//         if (node == nullptr)
//         {
//             return;
//         }
//         if (node->left)
//         {
//             dfs(node->left, value + node->val, limit);
//         }
//         if (node->right)
//         {
//             dfs(node->right, value + node->val, limit);
//         }

//         if (value + node->val < limit)
//         {
//             cout << node->val << endl;
//             node->val == NULL;
//         }
//     }

//     void deleteNULLNode(TreeNode *node)
//     {
//         if (node == nullptr)
//         {
//             return;
//         }

//         if (node->left && 0 == node->left->val)
//         {
//             node->left = nullptr;
//         }

//         if (node->right && 0 == node->right->val)
//         {
//             node->right = nullptr;
//         }

//         if (node->left)
//         {
//             deleteNULLNode(node->left);
//         }
//         if (node->right)
//         {
//             deleteNULLNode(node->right);
//         }
//     }
// };