//
// Created by sajith on 8/14/22.
//

#include "base.h"

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        auto *left = invertTree(root->left);
        auto *right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};