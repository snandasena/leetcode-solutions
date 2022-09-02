//
// Created by sajith on 9/2/22.
//

#include "base.h"

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        queue<TreeNode *> que;
        que.push(root);
        vector<double> ans;

        while (!que.empty())
        {
            auto size = que.size();
            auto sum = 0.0;
            for (auto i = 1; i <= size; ++i)
            {
                auto curr = que.front();
                que.pop();
                sum += curr->val;

                if (curr->left != nullptr)
                {
                    que.push(curr->left);
                }

                if (curr->right != nullptr)
                {
                    que.push(curr->right);
                }
            }

            if (size != 0)
            {
                ans.push_back(sum / size);
            }
        }
        return ans;
    }
};