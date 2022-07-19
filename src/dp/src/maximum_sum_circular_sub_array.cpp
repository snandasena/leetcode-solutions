//
// Created by sajith on 7/17/22.
//


#include "base.h"

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int total_sum = 0;
        int max_ending_at = 0;
        int min_ending_at = 0;
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;

        for (const auto &x: nums)
        {
            total_sum += x;
            max_ending_at = max(max_ending_at + x, x);
            max_sum = max(max_ending_at, max_sum);
            min_ending_at = min(min_ending_at + x, x);
            min_sum = min(min_ending_at, min_sum);
        }
        if (max_sum > 0)
        {
            return max(max_sum, total_sum - min_sum);
        }
        return max_sum;
    }
};

int main()
{
    Solution solution;
//    vector<int> v{1, -2, 3, -2};
    vector<int> v{1, 0, -1, 5, -3, 5, -1};
    cout << solution.maxSubarraySumCircular(v);

    return 0;
}