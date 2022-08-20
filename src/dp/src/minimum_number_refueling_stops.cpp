//
// Created by sajith on 8/20/22.
//


#include "base.h"

class Solution
{
public:
    int minRefuelStops2(int target, int startFuel, vector<vector<int>> &stations)
    {
        auto N = static_cast<int> (stations.size());
        vector<long> dp(N + 1);
        dp[0] = startFuel;

        for (int i = 0; i < N; ++i)
        {
            for (int t = i; t >= 0; --t)
            {
                if (dp[t] >= stations[i][0])
                {
                    dp[t + 1] = max(dp[t + 1], dp[t] + static_cast<long>(stations[i][1]));
                }
            }
        }

        for (int i = 0; i <= N; ++i)
        {
            if (dp[i] >= target)
            {
                return i;
            }
        }
        return -1;
    }

    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        priority_queue<int> pq;
        auto N = static_cast<int>(stations.size());

        int refill = 0;
        int i = 0;
        int distance = startFuel;

        while (distance < target)
        {
            while (i < N && distance >= stations[i][0])
            {
                pq.push(stations[i][1]);
                ++i;
            }

            if (pq.empty())
            {
                return -1;
            }

            distance += pq.top();
            pq.pop();
            ++refill;
        }

        return refill;
    }

};