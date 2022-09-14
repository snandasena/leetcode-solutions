//
// Created by sajith on 9/14/22.
//

#include "base.h"

class Solution
{
    int ans = 0;
    bool iSPseudoPalindrome(unordered_map<int, int> &path)
    {
        int odd = 0;
        int even = 0;
        for (const auto &[key, val]: path)
        {
            if (val % 2 == 0)
            {
                ++even;
            }
            else
            {
                ++odd;
            }
        }

        if (odd > 1)
        {
            return false;
        }
        return true;
    }

    void dfs(TreeNode *node, unordered_map<int, int> &path)
    {
        if (node == nullptr)
        {
            return;
        }

        ++path[node->val];
        if (node->left == nullptr && node->right == nullptr)
        {
            if (iSPseudoPalindrome(path))
            {
                ++ans;
            }

        }
        dfs(node->left, path);
        dfs(node->right, path);
        --path[node->val];
    }
public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        unordered_map<int, int> path;
        dfs(root, path);
        return ans;
    }
};

int main()
{
    TreeNode *node = new TreeNode{2};
    node->left = new TreeNode{3};
    node->right = new TreeNode{1};
    node->right->right = new TreeNode{1};

    node->left->left = new TreeNode{3};
    node->left->right = new TreeNode{1};

    Solution sol;
    sol.pseudoPalindromicPaths(node);

    return 0;
}