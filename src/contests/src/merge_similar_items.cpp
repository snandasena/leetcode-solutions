//
// Created by sajith on 8/7/22.
//
#include "base.h"

class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        map<int, int> mp;
        for (const auto &item: items2)
        {
            mp[item[0]] = item[1];
        }

        for (const auto &item: items1)
        {
            mp[item[0]] = item[1] + mp[item[0]];
        }

        vector<vector<int>> ans;
        for (const auto &p: mp)
        {
            ans.push_back({p.first, p.second});
        }
        return ans;
    }
};