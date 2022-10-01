//
// Created by sajith on 9/25/22.
//

#include "../base.h"


class Solution
{
public:
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        auto N = nums.size();
        vector<bool> increasing(N, false);
        vector<bool> decreasing(N, false);
        int cnt = 1;
        increasing[0] = true;
        for (int i = 1; i < N; ++i)
        {
            if (cnt >= k)
            {
                decreasing[i] = true;
            }
            if (nums[i] <= nums[i - 1])
            {
                ++cnt;
            }
            else
            {
                cnt = 1;
            }
        }

        cnt = 1;
        increasing[N - 1] = true;
        for (int i = N - 2; i >= 0; --i)
        {
            if (cnt >= k)
            {
                increasing[i] = true;
            }
            if (nums[i] <= nums[i + 1])
            {
                ++cnt;
            }
            else
            {
                cnt = 1;
            }
        }

        vector<int> ans;
        for (int i = k; i < N - k; ++i)
        {
            if (decreasing[i] && increasing[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{

    Solution solution;
    vector<int> v{2, 1, 1, 1, 3, 4, 1};
//    solution.goodIndices(v, 2);
    for (auto &ele: solution.goodIndices(v, 2))
    {
        cout << ele << '\t';
    }


}