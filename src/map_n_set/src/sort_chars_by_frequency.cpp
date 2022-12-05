//
// Created by sajith on 12/3/22.
//

#include "base.h"

class Solution
{
public:
    string frequencySort(string s)
    {
        vector<pair<char, int>> mp(256);

        for (const auto &ch: s)
        {
            mp[int(ch)].first = ch;
            ++mp[int(ch)].second;
        }

        sort(mp.begin(), mp.end(), [](const pair<char, int> &p1, const pair<char, int> &p2)
        {
            return p1.second > p2.second;
        });

        string ans;
        for (const auto &[f, s]: mp)
        {
            for (int i = 0; i < s; ++i)
            {
                ans += f;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.frequencySort("Aabb");
}