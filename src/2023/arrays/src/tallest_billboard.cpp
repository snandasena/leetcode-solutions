//
// Created by sajit on 24/06/2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int tallestBillboard(vector<int> &rods)
    {
        int sum = accumulate(rods.cbegin(), rods.cend(), 0);
        vector<int> dp(sum + 1, -1);
        dp[0] = 0;

        for (const auto rod: rods)
        {
            const vector<int> current(dp);
            for (int i = 0; i <= sum - rod; ++i)
            {
                if (current[i] < 0) continue;

                dp[i + rod] = max(dp[i + rod], current[i]);
                dp[abs(i - rod)] = max(dp[abs(i - rod)], current[i] + min(i, rod));
            }
        }
        return dp[0];
    }
};