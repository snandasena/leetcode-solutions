//
// Created by sajith on 7/27/22.
//

#include "base.h"

class Solution
{

public:
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;
        TreeNode *prev;
        while (curr != nullptr)
        {
            if (curr->left != nullptr)
            {
                prev = curr->left;
                while (prev->right != nullptr)
                {
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

int main()
{
    Solution solution;

    TreeNode *root = new TreeNode{1};
    root->left = new TreeNode{2};
    root->right = new TreeNode{5};
    root->right->right = new TreeNode{6};

    root->left->left = new TreeNode{3};
    root->left->right = new TreeNode{4};

    solution.flatten(root);

    return 0;
}