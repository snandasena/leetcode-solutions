//
// Created by sajith on 9/30/22.
//

#include "base.h"

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> cords;
        for (const auto &ele: buildings)
        {
            cords.emplace_back(ele[0], -ele[2]);
            cords.emplace_back(ele[1], ele[2]);
        }
        sort(cords.begin(), cords.end());

        multiset<int> st;
        st.insert(0);
        vector<vector<int>> ans;
        int curr = 0;
        for (const auto &[x, h]: cords)
        {
            if (h < 0)
            {
                st.insert(-h);
            }
            else
            {
                st.erase(st.find(h));
            }

            auto mx = *st.rbegin();
            if (curr != mx)
            {
                curr = mx;
                ans.push_back({x, mx});
            }
        }
        return ans;
    }
};