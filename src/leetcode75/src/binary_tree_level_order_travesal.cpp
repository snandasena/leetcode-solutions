//
// Created by sajith on 7/25/22.
//

#include "base.h"

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            auto sz = que.size();
            vector<int> curr;
            for (int i = 0; i < sz; ++i)
            {
                auto node = que.front();
                que.pop();

                if (node != nullptr)
                {
                    curr.push_back(node->val);
                    if (node->left != nullptr)
                    {
                        que.push(node->left);
                    }

                    if (node->right)
                    {
                        que.push(node->right);
                    }
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};