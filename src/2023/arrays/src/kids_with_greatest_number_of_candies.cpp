//
// Created by sajit on 17/04/2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> ans(candies.size(), true);
        for (unsigned i = 0; i < candies.size(); ++i)
        {
            int curr = candies[i]+extraCandies;
            for (unsigned j = i+1; j < candies.size(); ++j)
            {
                if(candies[j] )
            }
        }
        return ans;
    }
};