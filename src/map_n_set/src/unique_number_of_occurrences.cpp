//
// Created by sajith on 11/30/22.
//

#include "base.h"

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        for (const auto &ele: arr)
        {
            ++mp[ele];
        }
        unordered_set<int> st;
        for (const auto &[f, s]: mp)
        {
            if (st.find(s) == st.end())
            {
                st.insert(s);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};