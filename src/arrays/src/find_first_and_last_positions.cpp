//
// Created by sajith on 7/25/22.
//

#include "base.h"


class Solution
{
    int findFirstPos(vector<int> &nums, int target)
    {
        int l = 0;
        int r = static_cast<int >(nums.size()) - 1;
        int ans = -1;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                r = mid - 1;
            }
            else if (target < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }

    int findLastPos(vector<int> &nums, int target)
    {
        int l = 0;
        int r = static_cast<int >(nums.size()) - 1;
        int ans = -1;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (target == nums[mid])
            {
                ans = mid;
                l = mid + 1;
            }
            else if (target < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty()) return {-1, -1};

        return {findFirstPos(nums, target), findLastPos(nums, target)};
    }
};

int main()
{
    Solution solution;
    vector<int> v{5, 7, 7, 8, 8, 10};
    solution.searchRange(v, 8);

    return 0;
}