/*
104. 二叉树的最大深度
简单
相关标签
相关企业
给定一个二叉树 root ，返回其最大深度。

二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。



示例 1：
      3
     / \
    9   20
        / \
      15   7

输入：root = [3,9,20,null,null,15,7]
输出：3
示例 2：

输入：root = [1,null,2]
输出：2


提示：

树中节点的数量在 [0, 104] 区间内。
-100 <= Node.val <= 100
*/

#include <iostream>

//   Definition for a binary tree node.
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
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        m_maxDeep = 0;

        search(root, 0);

        return m_maxDeep;
    }

private:
    int m_maxDeep = 0;

    void search(TreeNode *node, int deep)
    {
        ++deep;

        if (!node->left && !node->right)
        {
            m_maxDeep = std::max(m_maxDeep, deep);
            return;
        }

        if (node->left)
        {
            search(node->left, deep);
        }

        if (node->right)
        {
            search(node->right, deep);
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
