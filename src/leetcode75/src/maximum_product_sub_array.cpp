
//
// Created by sajith on 8/16/22.
//


#include "base.h"

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 1) return nums.back();

        int ans = nums.front();
        int mx = ans;
        int mn = ans;

        for (auto num = nums.begin() + 1; num != nums.end(); ++num)
        {
            if (*num < 0)
            {
                swap(mx, mn);
            }
            mx = max((*num) * mx, *num);
            mn = min(*num, mn * (*num));

            ans = max(ans, mx);
        }
        return ans;
    }
};