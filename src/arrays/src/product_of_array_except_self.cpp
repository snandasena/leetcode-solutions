//
// Created by sajit on 15/03/2024.
//

#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int postifx = 1;
        vector<int> out(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i)
        {
            out[i] = postifx;
            postifx *= nums[i];
        }

        postifx = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            out[i] *= postifx;
            postifx *= nums[i];
        }
        return out;
    }
};
