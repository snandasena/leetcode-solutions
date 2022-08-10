//
// Created by sajith on 8/10/22.
//


#include "base.h"

class Solution
{

    TreeNode *helper(int start, int end, const vector<int> &nums)
    {
        if (start > end) return nullptr;
        auto mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode{nums[mid]};
        node->left = helper(start, mid - 1, nums);
        node->right = helper(mid + 1, end, nums);
        return node;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(0, nums.size() - 1, nums);
    }
};

int main()
{
    Solution sol;
    vector<int> v{-10, -3, 0, 5, 9};
    sol.sortedArrayToBST(v);
    return 0;
}