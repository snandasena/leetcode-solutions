//
// Created by sajith on 11/11/22.
//
#include "base.h"

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int insert_indx = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] != nums[i])
            {
                nums[insert_indx] = nums[i];
                ++insert_indx;
            }
        }
        return insert_indx;
    }
};