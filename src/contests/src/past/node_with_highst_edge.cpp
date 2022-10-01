//
// Created by sajith on 8/14/22.
//

#include "../base.h"


class Solution
{
    using LL = long long;
public:
    int edgeScore(vector<int> &edges)
    {
        LL mx = 0;
        map<int, LL> mp;
        for (auto i = 0; i < edges.size(); ++i)
        {
            mp[edges[i]] += i;
            mx = max(mx, mp[edges[i]]);
        }

        for(const auto &[f,s] : mp)
        {
            if(mx == s)
            {
                return f;
            }
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> v{1, 0, 0, 0, 0, 7, 7, 5};
    solution.edgeScore(v);
    return 0;
}