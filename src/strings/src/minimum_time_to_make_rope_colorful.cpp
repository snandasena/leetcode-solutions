
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        auto N = colors.size();
        int ans = 0;
        int i = 0;
        int j;
        int curr;
        int mx;
        while (i < N)
        {
            j = i + 1;
            curr = neededTime[i];
            mx = curr;
            while (j < N && colors[i] == colors[j])
            {
                mx = max(mx, neededTime[j]);
                curr += neededTime[j];
                ++j;
            }
            ans += (curr - mx);
            i = j;

        }
        return ans;
    }
};
