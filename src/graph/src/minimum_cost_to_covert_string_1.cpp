//
// Created by sajit on 27/07/2024.
//

#include "base.h"

class Solution
{
    using ll = long long;
public:
    ll minimumCost(string source, string target, vector<char> &original,
                   vector<char> &changed, vector<int> &cost)
    {
        ll totalCost = 0;
        vector<vector<ll>> minCost(26, vector<ll>(26, INT_MAX));

        for (auto i = 0u; i < original.size(); ++i)
        {
            int startChar = original[i] - 'a';
            int endChar = changed[i] - 'a';

            minCost[startChar][endChar] = min(minCost[startChar][endChar], (ll) (cost[i]));
        }

        for (int k = 0; k < 26; ++k)
        {
            for (int i = 0; i < 26; ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }

        for (auto i = 0u; i < source.size(); ++i)
        {
            if (source[i] == target[i])
                continue;

            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';

            if (minCost[sourceChar][targetChar] >= INT_MAX)
                return -1;

            totalCost += minCost[sourceChar][targetChar];
        }

        return totalCost;
    }
};