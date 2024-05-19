//
// Created by sajit on 19/05/2024.
//

#include "base.h"

using namespace std;

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        int N = nums.size();
        vector<vector<long long >> dp(N + 1, vector<long long>(2, 0));
        dp[N][0] = INT_MIN;
        dp[N][1] = 0;

        for (int index = N - 1; index >= 0; --index)
        {
            for (int iseven = 0; iseven <= 1; ++iseven)
            {
                auto performOperation = dp[index + 1][iseven ^ 1] + (nums[index] ^ k);

                auto dontPerformOperation = dp[index + 1][iseven] + nums[index];

                dp[index][iseven] = max(performOperation, dontPerformOperation);
            }
        }

        return dp[0][1];
    }
};