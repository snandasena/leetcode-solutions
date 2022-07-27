//
// Created by sajith on 7/27/22.
//


#include "base.h"

class Solution
{
    vector<int> v;
    void helper(TreeNode *node)
    {
        if (node == nullptr) return;
        helper(node->left);
        v.push_back(node->val);
        helper(node->right);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        helper(root);
        for (int i = 1; i < v.size(); ++i)
        {
            if (v[i] >= v[i - 1]) return false;
        }
        return true;
    }
};

