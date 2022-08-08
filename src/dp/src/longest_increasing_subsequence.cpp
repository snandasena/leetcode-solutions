
//
// Created by sajith on 8/8/22.
//

#include "base.h"

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int ans = 1;
        vector<int> dp;
        dp.push_back(nums.front());

        auto it = nums.begin();
        while (++it != nums.end())
        {
            if (*it > dp.back())
            {
                dp.push_back(*it);
                ++ans;
            }
            else
            {
                auto indx = lower_bound(dp.begin(), dp.end(), *it) - dp.begin();
                dp[indx] = *it;
            }
        }
        return ans;
    }
};