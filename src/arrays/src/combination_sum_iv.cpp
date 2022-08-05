//
// Created by sajith on 8/5/22.
//

#include "base.h"

class Solution
{
    vector<int> dp;
    int helper(const vector<int> &nums, int target)
    {
        if (dp[target] > -1)
        {
            return dp[target];
        }
        int res = 0;
        for (const auto &item: nums)
        {
            if (item <= target)
            {
                res += helper(nums, target - item);
            }
        }
        dp[target] = res;
        return dp[target];
    }
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        dp.resize(target + 1, -1);
        dp[0] = 1;
        return helper(nums, target);
    }
};

int main()
{

    Solution sol;
    vector<int> v{1, 2, 3};
    int t = 4;
    cout << sol.combinationSum4(v, t) << endl;
    return 0;
}