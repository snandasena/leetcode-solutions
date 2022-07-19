//
// Created by sajith on 7/19/22.
//


#include "base.h"

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0') return 0;

        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < s.length(); ++i)
        {
            auto a = s[i] - '0';
            auto b = s[i - 1] - '0';
            b = b * 10 + a;

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
        return dp.back();
    }
};

int main()
{
    Solution solution;

    cout << solution.numDecodings("226");

    return 0;
}