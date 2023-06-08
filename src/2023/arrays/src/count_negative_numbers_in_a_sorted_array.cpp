//
// Created by sajit on 08/06/2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        auto ans = 0u;
        for (const vector<int> &item: grid)
        {
            auto it = find_if(item.cbegin(), item.cend(), [](auto i){return i<0;});

            if(it != item.end())
            {
                ans += item.size()-std::distance(item.begin(), it);
            }
        }
        return static_cast<int>(ans);
    }
};