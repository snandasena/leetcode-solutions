
//
// Created by sajith on 9/5/22.
//

#pragma once

#include "base.h"


class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<Node *> que;
        que.push(root);
        vector<vector<int>> ans;

        while (!que.empty())
        {
            auto size = que.size();
            vector<int> v;
            for (int i = 0; i < size; ++i)
            {
                auto curr = que.front();
                v.push_back(curr->val);
                que.pop();
                for (const auto node: curr->children)
                {
                    que.push(node);
                }
            }
            ans.push_back(v);
        }

        return ans;
    }
};