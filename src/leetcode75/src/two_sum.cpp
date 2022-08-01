//
// Created by sajith on 8/1/22.
//

#include "base.h"

class Solution
{
public:
    vector<int> twoSum2(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i)
        {
            mp[nums[i]] = i;
        }
        int complement;
        for (int i = 0; i < nums.size(); ++i)
        {
            complement = target - nums[i];
            if (mp.count(complement) > 0 && mp[complement] != i)
            {
                return {i, mp[complement]};
            }
        }
        return {-1, -1};
    }

    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp.find(target - nums[i]) != mp.end())
            {
                ans.push_back(i);
                ans.push_back(mp[target - nums[i]]);
                break;
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};