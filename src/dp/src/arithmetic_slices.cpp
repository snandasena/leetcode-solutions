//
// Created by sajith on 7/19/22.
//


#include "base.h"

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int ans = 0;
        vector<int> dp(nums.size(), 0);
        for (auto i = 2; i < nums.size(); ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                dp[i] = dp[i - 1] + 1;
                ans += dp[i];
            }
        }
        return ans;
    }
};