//
// Created by sajith on 9/1/22.
//


#include "base.h"

class Solution
{
    int ans = 0;
    void dfs(TreeNode *node, int root_val)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->val >= root_val)
        {
            ++ans;
            root_val = node->val;
        }

        dfs(node->left, root_val);
        dfs(node->right, root_val);
    }
public:
    int goodNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        dfs(root->left, root->val);
        dfs(root->right, root->val);
        return ans + 1;
    }
};