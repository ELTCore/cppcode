/*
226. 翻转二叉树
简单
相关标签
相关企业
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。


示例 1：
       4                 4
     /   \             /   \
    2     7     --->  7     2
   / \   / \         / \   / \
  1   3 6   9       9   6 3   1

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
示例 2：
    2              2
   / \    ---->   / \
  1   3          3   1

输入：root = [2,1,3]
输出：[2,3,1]
示例 3：

输入：root = []
输出：[]


提示：

树中节点数目范围在 [0, 100] 内
-100 <= Node.val <= 100
*/

#include <iostream>

using namespace std;

// Definition for a binary tree node.
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
    TreeNode *invertTree(TreeNode *root)
    {
        _invert(root);

        return root;
    }

private:
    void _invert(TreeNode *node)
    {
        if (!node)
        {
            return;
        }

        swap(node->left, node->right);
        _invert(node->left);
        _invert(node->right);
        return;
    }
};