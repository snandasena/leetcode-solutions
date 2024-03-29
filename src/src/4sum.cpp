//
// Created by sajith on 8/17/21.
//

#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k)
    {
        vector<vector<int>> res;
        if (start == nums.size() || static_cast<long >(nums[start]) * k > target ||
            target > static_cast<long>(nums.back()) * k)
        {
            return res;
        }

        if (k == 2)
        {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.size(); ++i)
        {
            if (i == start || nums[i - 1] != nums[i])
            {
                for (vector<int> &subset: kSum(nums, target - nums[i], i + 1, k - 1))
                {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }
        return res;
    }

    vector<vector<int>> twoSum(vector<int> &nums, int target, int start)
    {
        vector<vector<int>> res;
        size_t lo = start, hi = nums.size() - 1;

        while (lo < hi)
        {
            int curr = nums[lo] + nums[hi];

            if (curr < target || ((lo > start) && nums[lo] == nums[lo - 1]))
            {
                ++lo;
            } else if (curr > target || ((hi < nums.size() - 1) && nums[hi] == nums[hi + 1]))
            {
                --hi;
            } else
            {
                res.push_back({nums[lo++], nums[hi--]});
            }
        }

        return res;
    }
};