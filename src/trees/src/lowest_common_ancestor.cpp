//
// Created by sajith on 7/27/22.
//


#include "base.h"

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *curr = root;
        while (curr)
        {
            if (p->val < curr->val && q->val < curr->val)
            {
                curr = curr->left;
            }
            else if (p->val > curr->val && q->val > curr->val)
            {
                curr = curr->right;
            }
            else
            {
                return curr;
            }
        }

        return nullptr;
    }
};