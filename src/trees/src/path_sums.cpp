//
// Created by sajith on 10/4/22.
//
#include "base.h"

class Solution
{
    bool ans = false;
    void dfs(TreeNode *node, int target, int curr)
    {
        if (node == nullptr)
        {
            return;
        }
        curr += node->val;
        if (node->left == nullptr && node->right == nullptr)
        {
            if (curr == target)
            {
                ans = true;
            }
        }

        dfs(node->left, target, curr);
        dfs(node->right, target, curr);

        curr -= node->val;
    }


public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        dfs(root, targetSum, 0);
        return ans;
    }
};