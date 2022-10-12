//
// Created by sajith on 10/12/22.
//

#include "base.h"


class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<>());

        int ans = 0;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (nums[i] < nums[i + 1] + nums[i + 2])
            {
                ans = nums[i] + nums[i + 1] + nums[i + 2];
                break;
            }
        }
        return ans;
    }
};