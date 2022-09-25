//
// Created by sajith on 9/25/22.
//

#include "base.h"

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<pair<int, string>> v;

        for (int i = 0; i < names.size(); ++i)
        {
            v.emplace_back(heights[i], names[i]);
        }

        sort(v.begin(), v.end(), greater<>());

        vector<string> ans;

        for (const auto &item: v)
        {
            ans.push_back(item.second);
        }

        return ans;
    }
};