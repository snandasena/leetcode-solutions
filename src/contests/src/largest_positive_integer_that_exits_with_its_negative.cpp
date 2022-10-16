//
// Created by sajith on 10/16/22.
//

#include "base.h"

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<>());
        vector<int> v(1001, -1);

        for (const auto &ele: nums)
        {
            if (ele > 0)
            {
                v[ele] = 1;
            }
            else
            {
                if (v[abs(ele)] == 1)
                {
                    v[abs(ele)] = 0;
                }
            }
        }

        for (int i = 1000; i >= 0; --i)
        {
            if (v[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};
