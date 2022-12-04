
//
// Created by sajith on 12/4/22.
//

#include "base.h"

class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        vector<long int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i] += dp[i - 1] + nums[i];
        }

        int mn = INT_MAX;
        int j = 0;
        int mn_indx = 0;
        for (int i = nums.size() - 1; i >= 0; --i,++j)
        {
            auto av = (dp[j] / (j + 1)) - (i == 0 ? 0 : ((dp.back() - dp[j]) / i));
//            cout << j << "\t" << abs(av) << endl;
            if (mn > abs(av))
            {
                mn = abs(av);
                mn_indx = j;
            }
        }
        return mn_indx;
    }
};

int main()
{
    Solution sol;
    vector<int> v{2, 5, 3, 9, 5, 3};
    cout << sol.minimumAverageDifference(v) << endl;
}