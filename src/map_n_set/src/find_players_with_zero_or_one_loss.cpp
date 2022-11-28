//
// Created by sajith on 11/28/22.
//

#include "base.h"

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        map<int, int> mp1;
        map<int, int> mp2;
        unordered_set<int> users;

        for (const auto &v: matches)
        {
            ++mp1[v[0]];
            ++mp2[v[1]];

            users.insert(v[0]);
            users.insert(v[1]);
        }

        vector<vector<int>> ans;
        vector<int> winners;
        vector<int> losers;
        for (const auto &[f, s]: mp1)
        {
            if (mp2.find(f) == mp2.end())
            {
                winners.push_back(f);
            }
        }

        for (const auto &[f, s]: mp2)
        {
            if (s == 1)
            {
                losers.push_back(f);
            }
        }
        ans.push_back(winners);
        ans.push_back(losers);
        return ans;
    }
};