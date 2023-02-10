//
// Created by sajith on 1/4/23.
//

#include "base.h"

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> mp;
        for (const auto &ele: tasks)
        {
            ++mp[ele];
        }

        int ans = 0;
        for (auto &[f, s]: mp)
        {
            if (s % 2 == 0 || s % 3 == 0)
            {
                if (s % 2 == 0)
                {
                    ans += s / 2;
                }
                else
                {
                    ans += s / 3;
                }

                s = 0;
            }
        }

        for (const auto &[f, s]: mp)
        {
            if (s > 0)
            {
                return -1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v{2, 2, 3, 3, 2, 4, 4, 4, 4, 4};
    cout << sol.minimumRounds(v);

}