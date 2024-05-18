//
// Created by sajit on 18/05/2024.
//

#include "base.h"
class Solution {
    int dfs(TreeNode *root, int &ans)
    {
        if(root == nullptr)
            return 0;

        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        ans += abs(left) + abs(right);

        return root->val -1 + left + right;
    }

public:

    int distributeCoins(TreeNode* root)
    {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};