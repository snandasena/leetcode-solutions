//
// Created by sajith on 9/6/22.
//


#include "base.h"

class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (root->val == 0 && root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;
        }
        return root;
    }
};