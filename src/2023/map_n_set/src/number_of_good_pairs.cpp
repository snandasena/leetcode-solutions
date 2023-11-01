//
// Created by sajit on 03/10/2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int &i: nums)
        {
            if (mp.find(i) != mp.end())
            {
                ++mp[i];
            } else
            {
                mp[i] = 1;
            }
        }

        int ans = 0;
        for (auto &[f, s]: mp)
        {
            if (s > 1)
            {
                ans += (s-1) * s;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 2, 3, 1, 1, 3};
    cout << sol.numIdenticalPairs(nums);
}