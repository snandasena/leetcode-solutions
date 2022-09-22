//
// Created by sajith on 9/21/22.
//

#include "base.h"

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int even_total = 0;
        for (const auto &ele: nums)
        {
            if (ele % 2 == 0)
            {
                even_total += ele;
            }
        }
        vector<int> ans;
        for (const auto &v: queries)
        {
            if (nums[v[1]] % 2 == 0)
            {
                auto temp = nums[v[1]];
                nums[v[1]] += v[0];

                if (nums[v[1]] % 2 == 0)
                {
                    even_total -= temp;
                    even_total += nums[v[1]];
                }
                else
                {
                    even_total -= temp;
                }
            }
            else
            {
                nums[v[1]] += v[0];
                if (nums[v[1]] % 2 == 0)
                {
                    even_total += nums[v[1]];
                }
            }
            ans.push_back(even_total);
        }
        return ans;
    }
};