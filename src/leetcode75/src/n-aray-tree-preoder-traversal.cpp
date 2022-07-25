//
// Created by sajith on 7/25/22.
//

#include "base.h"

class Solution
{
    vector<int> ans;

    void helper(Node *node)
    {
        if (node == nullptr) return;
        ans.push_back(node->val);

        for (const auto &item: node->children)
        {
            helper(item);
        }
    }

public:
    vector<int> preorder(Node *root)
    {
        helper(root);
        return ans;
    }
};
