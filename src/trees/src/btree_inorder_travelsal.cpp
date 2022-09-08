//
// Created by sajith on 9/8/22.
//

#include "base.h"

class Solution
{
    void dfs(TreeNode *node, vector<int> &ans)
    {
        if (node == nullptr)
        {
            return;
        }

        dfs(node->left, ans);
        ans.push_back(node->val);
        dfs(node->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
        }
        dfs(root, ans);
        return ans;
    }
};