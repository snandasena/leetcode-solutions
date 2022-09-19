//
// Created by sajith on 9/19/22.
//


#include "base.h"

class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        queue<TreeNode *> que;
        que.push(root);
        int i = 0;
        while (!que.empty())
        {
            auto sz = que.size();
            vector<TreeNode *> v;
            vector<int> v2;
            while (sz-- > 0)
            {
                auto curr = que.front();
                if (curr != nullptr)
                {
                    v.push_back(curr);
                    v2.push_back(curr->val);

                    if (curr->left != nullptr)
                    {

                        que.push(curr->left);
                    }
                    if (curr->right != nullptr)
                    {
                        que.push(curr->right);
                    }
                }
                que.pop();
            }
            if (i % 2 == 1)
            {
                reverse(v2.begin(), v2.end());

                for (int i = 0; i < v2.size(); ++i)
                {
                    v[i]->val = v2[i];
                }
            }
            ++i;
        }

        return root;
    }
};