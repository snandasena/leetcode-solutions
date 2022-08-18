//
// Created by sajith on 8/18/22.
//

#include "base.h"

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int t = 0;
        t = accumulate(nums.begin(), nums.end(), t);
        if (t % 2 != 0)
        {
            return false;
        }
        t /= 2;

        vector<bool> dp(t + 1);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = t; j >= nums[i]; --j)
            {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[t];
    }
};