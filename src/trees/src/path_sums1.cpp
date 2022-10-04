//
// Created by sajith on 10/4/22.
//
#include "base.h"

class Solution
{

    bool dfs(TreeNode *node, int target)
    {
        if (node == nullptr)
        {
            return false;
        }
        auto curr = target - node->val;
        if (node->left == nullptr && node->right == nullptr)
        {
            return curr == 0;
        }

        return dfs(node->left, curr) || dfs(node->right, curr);
    }


public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return dfs(root, targetSum);
    }
};