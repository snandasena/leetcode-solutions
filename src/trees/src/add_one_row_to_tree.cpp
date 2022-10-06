
//
// Created by sajith on 10/5/22.
//

#include "base.h"

class Solution
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            auto node = new TreeNode{val};
            node->left = root;
            return node;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            auto size = que.size();
            for (int i = 0; i < size; ++i)
            {
                auto node = que.front();
                que.pop();

                if (depth == 1)
                {
                    auto temp = node->left;
                    node->left = new TreeNode{val};
                    node->left->left = temp;


                    auto temp2 = node->right;
                    node->right = new TreeNode{val};
                    node->right->right = temp2;
                }
                else
                {
                    if (node->left != nullptr)
                    {
                        que.push(node->left);
                    }

                    if (node->right != nullptr)
                    {
                        que.push(node->right);
                    }
                }
            }
            if (depth == 1)
            {
                return root;
            }
            --depth;

        }
        return root;
    }
};

int main()
{

    Solution sol;

    TreeNode *root = new TreeNode{4};
    root->left = new TreeNode{2};

    root->right = new TreeNode{6};
    root->right->left = new TreeNode{5};

    root->left->left = new TreeNode{3};
    root->left->right = new TreeNode{1};

    sol.addOneRow(root, 1, 2);

    return 0;
}