//
// Created by sajith on 8/7/22.
//
#include "../base.h"

class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        if (nums.size() == 2)
        {
            if (nums[0] == nums[1]) return true;
            return false;
        }

        stack<int> st;

        for (int i = nums.size() - 1; i >= 2;)
        {
            if(nums[i] == nums[i-2])
            {

            }
        }



    }
};