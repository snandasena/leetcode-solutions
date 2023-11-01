//
// Created by sajit on 01/11/2023.
//

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution
{
    unordered_map<int, int> mp;

    void traversal(TreeNode *root)
    {
        if (!root) return;
        ++mp[root->val];
        traversal(root->left);
        traversal(root->right);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        if (!root) return {};

        traversal(root);

        int mx = 0;
        for (const auto &[k, v]: mp)
            mx = max(mx, v);

        vector<int> ans;
        for (const auto &[k, v]: mp)
            if (mx == v)
                ans.push_back(k);

        return ans;
    }
};


int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->left->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(6);

    Solution solution;
    solution.findMode(root);
}