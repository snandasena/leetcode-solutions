//
// Created by sajith on 10/23/22.
//


#include "base.h"

// 1, 2, 3, 4, 5, 6, 7, 8
// 1, 2, 3, 4, 5, 6, 4, 8
// 1, 2, 3, 4, 4, 5, 6, 8

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> v(nums.size() + 1, 0);

        for (const auto &ele: nums)
        {
            ++v[ele];
        }

        int t;
        int d;
        for (int i = 1; i <= nums.size(); ++i)
        {
            if (v[i] == 0)
            {
                t = i;
            }
            else if (v[i] > 1)
            {
                d = i;
            }
        }
        return {d, t};
    }
};

int main()
{

    Solution sol;
    vector<int> v{1, 2, 3, 4, 5, 6, 4, 8};
    auto res = sol.findErrorNums(v);

    return 0;
}