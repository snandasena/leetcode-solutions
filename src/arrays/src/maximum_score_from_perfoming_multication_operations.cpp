//
// Created by sajith on 9/16/22.
//

#include "base.h"

class Solution
{
public:
    int maximumScore(vector<int> &nums, vector<int> &mul)
    {
        int N = nums.size();
        int M = mul.size();
        vector<int> dp(M + 1);

        for (int op = M - 1; op >= 0; --op)
        {
            vector<int> row(dp.begin(), dp.end());
            for (int left = op; left >= 0; --left)
            {
                dp[left] = max(mul[op] * nums[left] + row[left + 1], mul[op] * nums[N - 1 - (op - left)] + row[left]);
            }
        }
        return dp[0];
    }
};

int main()
{

    return 0;
}