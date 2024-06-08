//
// Created by sajit on 08/06/2024.
//

#include "base.h"

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int sum = 0;

        for (const auto &item: nums)
        {
            sum += item;
            if (sum % k == 0)
            {
                return true;
            }
            else
            {
                sum %= k;
            }
        }

        return false;
    }
};