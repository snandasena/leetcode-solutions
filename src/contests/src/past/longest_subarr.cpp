//
// Created by sajith on 9/25/22.
//


#include "../base.h"

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        auto mx = *max_element(nums.begin(), nums.end());
        int ans = 1;
        int curr = 0;
        for (const auto &item: nums)
        {
            if (item == mx)
            {
                ++curr;
            }
            else
            {
                ans = max(ans, curr);
                curr = 0;
            }
        }
        ans = max(ans, curr);
        return ans;
    }
};


int main()
{
    Solution solution;
    vector<int> v{378034, 378034, 378034};
    cout << solution.longestSubarray(v);
    return 0;
}