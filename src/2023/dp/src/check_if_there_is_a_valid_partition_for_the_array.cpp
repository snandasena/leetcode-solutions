//
// Created by sajit on 13/08/2023.
//


#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        vector<bool> dp(3, false);
        dp[0] = true;
        int dpIndex;
        bool ans;
        for (auto i = 0; i < nums.size(); ++i)
        {
            dpIndex = i + 1;
            ans = false;

            if (i > 0 && nums[i] == nums[i - 1])
                ans |= dp[(dpIndex - 2) % 3];

            if (i > 1 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2])
                ans |= dp[(dpIndex - 3) % 3];

            if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)
                ans |= dp[(dpIndex - 3) % 3];

            dp[dpIndex % 3] = ans;
        }
        return dp[dpIndex %3];
    }
};