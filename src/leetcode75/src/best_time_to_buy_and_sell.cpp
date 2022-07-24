//
// Created by sajith on 7/24/22.
//


#include "base.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mx = 0;
        int curr = prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            curr = min(curr, prices[i]);
            mx = max(mx, prices[i] - curr);
        }
        return mx;
    }
};