//
// Created by sajith on 9/4/22.
//


#include "base.h"

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> mp;
        queue<tuple<TreeNode *, int, int>> que;
        que.push({root, 0, 0});

        while (!que.empty())
        {
            auto [node, i, j] = que.front();
            que.pop();
            mp[i][j].insert(node->val);

            if (node->left != nullptr)
            {
                que.push({node->left, i - 1, j + 1});
            }

            if (node->right != nullptr)
            {
                que.push({node->right, i + 1, j + 1});
            }
        }
        vector<vector<int>> ans;
        for (const auto &[ind, m]: mp)
        {
            vector<int> col;
            for (const auto &[key, st]: m)
            {
                col.insert(col.end(), st.begin(), st.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode{3};
    root->left = new TreeNode{9};
    root->right = new TreeNode{20};
    root->right->left = new TreeNode{15};
    root->right->right = new TreeNode{7};

    sol.verticalTraversal(root);
    return 0;
}