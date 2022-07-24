//
// Created by sajith on 7/23/22.
//


#include "base.h"

class Solution
{
    using LL = long long;
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        LL ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            LL curr = 0;
            while (i < nums.size() && nums[i] == 0)
            {
                ++curr;
                ++i;
            }

            ans += (curr +1) * curr/2;
        }
        return ans;
    }
};


int main()
{
    Solution solution;
    vector<int> v{0,0,0,2,0,0};

    cout << solution.zeroFilledSubarray(v);
    return 0;
}