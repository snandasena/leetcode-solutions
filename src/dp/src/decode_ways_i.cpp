//
// Created by sajith on 10/1/22.
//


#include "base.h"

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
        {
            return 0;
        }
        auto N = s.size();
        vector<int> dp(N);

        dp[0] = 1;
        for (int i = 1; i < N; ++i)
        {
            auto a = s[i] - '0';
            auto b = 10 * (s[i - 1] - '0') + a;

            if (a >= 1)
            {
                dp[i] += dp[i - 1];
            }

            if (b <= 26 && b >= 10)
            {
                if (i >= 2)
                {
                    dp[i] += dp[i - 2];
                }
                else
                {
                    dp[i] += 1;
                }
            }
        }

        return dp[N - 1];
    }
};

int main()
{
    Solution sol;
    cout << sol.numDecodings("27");
    return 0;
}