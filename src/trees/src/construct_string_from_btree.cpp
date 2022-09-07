//
// Created by sajith on 9/7/22.
//


#include "base.h"

class Solution
{
    string ans;
    void preorder(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        ans += to_string(node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            return;
        }

        ans += '(';
        preorder(node->left);
        ans += ')';

        if (node->right != nullptr)
        {
            ans += '(';
            preorder(node->right);
            ans += ')';
        }
    }
    string helper(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "";
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return to_string(root->val);
        }

        if (root->right == nullptr)
        {
            return to_string(root->val) + "(" + helper(root->left) + ")";
        }

        return to_string(root->val) + "(" + helper(root->left) + ")(" + helper(root->right) + ")";
    }
public:

    string tree2str(TreeNode *root)
    {
        preorder(root);
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode{1};
    root->left = new TreeNode{2};
    root->right = new TreeNode{3};
    root->left->left = new TreeNode{4};

    Solution sol;
    cout << sol.tree2str(root) << endl;
    return 0;
}