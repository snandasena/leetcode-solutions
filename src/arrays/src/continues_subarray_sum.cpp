
//
// Created by sajith on 10/26/22.
//

#include "base.h"

/**
 *  1 2 4 5 6 7 8
 *  2 3 7 12 18 25 33
 *
 *
 *
 *
 */


class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp{{0, 0}};
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (mp.find(sum % k) == mp.end())
            {
                mp[sum % k] = i + 1;
            }
            else if (mp[sum % k] < i)
            {
                return true;
            }
        }
        return false;
    }
};
