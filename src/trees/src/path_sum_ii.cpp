//
// Created by sajith on 9/24/22.
//

#include "base.h"

class Solution
{
    vector<vector<int>> ans;

    void dfs(TreeNode *node, int target, int curr, vector<int> &path)
    {
        if (node == nullptr)
        {
            return;
        }
        curr += node->val;
        path.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr && curr == target)
        {
            ans.push_back(path);
        }
        dfs(node->left, target, curr, path);
        dfs(node->right, target, curr, path);

        path.pop_back();
        curr -= node->val;
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        dfs(root, targetSum, 0, path);
        return ans;
    }
};