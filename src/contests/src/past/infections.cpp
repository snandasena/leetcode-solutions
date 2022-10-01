//
// Created by sajith on 8/21/22.
//


#include "../base.h"

class Solution
{
    int infection = 0;
    bool found = false;
    int ans = 0;
    void max_depth(TreeNode *root, int curr, int start)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->val == start)
        {
            found = true;
        }
        if (found)
        {

        }
        else
        {

        }

        max_depth(root->left, curr + 1, start);
        max_depth(root->right, curr + 1, start);
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        if (root != nullptr && root->left)
            int mx = max_depth(root, 1, start);
        return mx + infection;
    }
};