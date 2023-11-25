//
// Created by sajit on 25/11/2023.
//

#include "base.h"

class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);

        int left_sum = 0;
        vector<int> ans(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i)
        {
            int right_sum = total - left_sum - nums[i];
            int left_count = i;
            int right_count = nums.size() - 1 - i;

            int left_total = left_count * nums[i] - left_sum;
            int right_total = right_sum - right_count * nums[i];

            ans[i] = left_total + right_total;
            left_sum += nums[i];
        }

        return ans;
    }
};