//
// Created by sajith on 11/15/22.
//

#include "base.h"

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode *> que;
        que.push(root);

        int ans = 0;
        while (!que.empty())
        {
            auto sz = que.size();
            while (sz-- > 0)
            {
                auto *curr = que.front();
                que.pop();
                if (curr != nullptr)
                {
                    ++ans;
                    if (curr->left != nullptr)
                    {
                        que.push(curr->left);
                    }

                    if (curr->right != nullptr)
                    {
                        que.push(curr->right);
                    }
                }
            }
        }
        return ans;
    }
};