#include <iostream>
#include <vector>
#include <stack>

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
    //  该函数的定义始终为：判断B是否为A的子结构
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (A == nullptr || B == nullptr)
        {
            return false;
        }
        // B为A的子结构有3种情况，满足任意一种即可：
        // 1.B的子结构起点为A的根节点，此时结果为recur(A, B)
        // 2.B的子结构隐藏在A的左子树中，而不是直接为A的根节点，此时结果为isSubStructure(A.left, B)
        // 3.B的子结构起点隐藏在A的右子树中，此时结果为isSubStructure(A.right, B)
        return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

private:
    // 判断B是否为A的子结构，其中B自己二狗的起点为A的根节点
    bool recur(TreeNode *A, TreeNode *B)
    {
        // 若B走完了，说明查找完毕，B为A的子结构
        if (B == nullptr)
        {
            return true;
        }
        // 若B不为空且A为空或者A与B的值不相等，直接可以判断B不是A的子结构
        if (A == nullptr || A->val != B->val)
        {
            return false;
        }

        // 当A与B当前节点值相等，若要判断B为A的子结构
        // 还需要判断B的左子树是否为A左子树的子结构 && B的右子树是否为A右子树的子结构
        // 若两者都满足就说明B是A的子结构，并且该子结构以A根节点为起点
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
};