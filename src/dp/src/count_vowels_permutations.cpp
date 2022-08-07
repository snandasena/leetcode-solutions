//
// Created by sajith on 8/7/22.
//

#include "base.h"

class Solution
{
    using LLI = long long int;
    const LLI MOD = 1e9 + 7;
public:
    int countVowelPermutation(int n)
    {
        vector<LLI> curr(5, 1);
        vector<LLI> prev(5, 1);

        for (int i = 1; i < n; ++i)
        {
            curr[0] = (prev[1] + prev[2] + prev[4]) % MOD;
            curr[1] = (prev[0] + prev[2]) % MOD;
            curr[2] = (prev[1] + prev[3]) % MOD;
            curr[3] = prev[2] % MOD;
            curr[4] = (prev[2] + prev[3]) % MOD;
            prev = curr;
        }
        LLI ans =0;
        for(const auto &i: curr)
        {
            ans = (ans +i)%MOD;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout<<sol.countVowelPermutation(20000)<<endl;
    return 0;
}