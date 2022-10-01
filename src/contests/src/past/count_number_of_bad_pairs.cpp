//
// Created by sajith on 8/11/22.
//

#include "../base.h"

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        long long ans = 0;
        unordered_map<long, int> mp;
        int cnt;
        for (auto itr = nums.begin(); itr != nums.end(); ++itr)
        {
            auto i = distance(nums.begin(), itr);
            auto p = *itr - i;
            cnt = 0;
            if (mp.find(p) != mp.end())
            {
                cnt = mp[p];
            }
            ans += (i - cnt);
            ++mp[p];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v{4, 1, 3, 3};
    sol.countBadPairs(v);
    return 0;
}