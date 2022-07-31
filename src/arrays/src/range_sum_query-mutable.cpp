//
// Created by sajith on 7/31/22.
//

#include "base.h"

class NumArray
{
    vector<int> sums;
    vector<int> vals;
public:
    NumArray(vector<int> &nums)
    {
        sums.resize(nums.size());
        sums[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            sums[i] = sums[i - 1] + nums[i];
        }
        vals = nums;
    }

    void update(int index, int val)
    {
        vals[index] = val;
        if (index == 0)
        {
            sums[0] = val;
            index = 1;
        }
        for (int i = index; i < vals.size(); ++i)
        {
            sums[i] = sums[i - 1] + vals[i];
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
    vector<int> v{1, 3, 5};

    NumArray numArray{v};

    numArray.sumRange(0, 2);
    numArray.update(1, 2);
    numArray.sumRange(0, 2);

    return 0;
}