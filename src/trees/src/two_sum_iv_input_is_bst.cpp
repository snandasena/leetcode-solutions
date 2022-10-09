//
// Created by sajith on 10/9/22.
//
#include "base.h"

class Solution
{
    unordered_set<int> st;

    bool dfs(TreeNode *node, int k)
    {
        if (node == nullptr)
        {
            return false;
        }

        auto curr = node->val;
        if (st.find(k - curr) != st.end())
        {
            return true;
        }
        st.insert(curr);

        return dfs(node->left, k) || dfs(node->right, k);
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        return dfs(root, k);
    }
};