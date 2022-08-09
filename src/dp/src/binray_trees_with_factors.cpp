
//
// Created by sajith on 8/9/22.
//


#include "base.h"

class Solution
{
    using LI = long int;
    const int MOD = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        auto N = static_cast<int>(arr.size());
        sort(arr.begin(), arr.end());

        vector<LI> dp(N, 1);
        unordered_map<int, int> mp;
        for (auto i = 0; i < N; ++i)
        {
            mp[arr[i]] = i;
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (arr[i] % arr[j] == 0)
                {
                    auto right = arr[i] / arr[j];
                    if (mp.find(right) != mp.end())
                    {
                        dp[i] = (dp[i] + dp[j] * dp[mp[right]]) % MOD;
                    }
                }
            }
        }

        LI ans = 0;
        for (const auto &ele: dp)
        {
            ans += ele;
            ans %= MOD;
        }
        return static_cast<int>(ans);
    }
};