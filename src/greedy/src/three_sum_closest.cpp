//
// Created by sajith on 10/8/22.
//

#include "base.h"

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        int l;
        int r;
        int N = nums.size();
        int sum;
        for (int i = 0; i < N && min_diff != 0; ++i)
        {
            l = i + 1;
            r = N - 1;

            while (l < r)
            {
                sum = nums[i] + nums[l] + nums[r];
                if (abs(target - sum) < abs(min_diff))
                {
                    min_diff = target - sum;
                }
                if (sum < target)
                {
                    ++l;
                }
                else
                {
                    --r;
                }
            }
        }
        return target - min_diff;
    }
};