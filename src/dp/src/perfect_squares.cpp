//
// Created by sajith on 11/22/22.
//


#include "base.h"


class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);
        int mn;
        int x;
        int sq;

        for (int i = 1; i <= n; ++i)
        {
            mn = i;
            x = 1;
            sq = 1;

            while (sq <= i)
            {
                mn = min(mn, 1 + dp[i - sq]);
                ++x;
                sq = x * x;
            }
            dp[i] = mn;
        }
        return dp[n];
    }
};