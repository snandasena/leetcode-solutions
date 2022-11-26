//
// Created by sajith on 11/26/22.
//

#inlcude"base.h"


class Solution
{
    int bs(vector <vector<int>> &v, int a, int i)
    {
        int lo = 0, hi = v.size() - 1;
        int ans = v.size();
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (v[mid][0] < a)
                lo = mid + 1;
            else
            {
                ans = mid;
                hi = mid - 1;
            }
        }
        return ans;
    }
    int solve(vector <vector<int>> &v, vector<int> &dp, int i)
    {
        // cout<<i<<endl;
        if (i == v.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int next = bs(v, v[i][1], i);
        // cout<<nex<<endl;
        return dp[i] =
                       max(v[i][2] + solve(v, dp, next), solve(v, dp, i + 1));
    }
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        vector <vector<int>> v;
        int n = profit.size();
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++)
            v.push_back({startTime[i], endTime[i], profit[i]});
        sort(v.begin(), v.end());
        return solve(v, dp, 0);
    }
};