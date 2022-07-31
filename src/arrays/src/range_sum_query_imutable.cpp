//
// Created by sajith on 7/31/22.
//


#include "base.h"

class NumArray
{
    vector<int> sums;
public:
    NumArray(vector<int> &nums)
    {
        sums.resize(nums.size(), 0);
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            sums[i] = sums[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0) return sums[right];

        return sums[right] - sums[left - 1];
    }
};


int main()
{
    vector<int> v{-2, 0, 3, -5, 2, -1};

    NumArray numArray{v};

    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;

    return 0;
}