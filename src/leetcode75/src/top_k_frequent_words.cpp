//
// Created by sajith on 8/3/22.
//

#include "base.h"

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        for (const auto &item: words)
        {
            ++mp[item];
        }

        vector<pair<string, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](const pair<string, int> &p1, const pair<string, int> &p2) -> bool
        {
            if (p1.second != p2.second) return p1.second > p2.second;
            return p1.first <= p2.first;
        });
        vector<string> ans;

        for (int i = 0; i < k; ++i)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> words{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    sol.topKFrequent(words, 4);

    return 0;
}