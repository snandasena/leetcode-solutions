//
// Created by sajith on 9/4/22.
//

#pragma once

#include "base.h"

class Solution
{
public:
    int leastInterval2(vector<char> &tasks, int n)
    {
        unordered_map<char, int> mp;
        int mx = 0;
        for (const auto &ch: tasks)
        {
            ++mp[ch];
            mx = max(mx, mp[ch]);
        }

        int cnt = 0;
        for (const auto &[k, v]: mp)
        {
            if (v == mx)
            {
                ++cnt;
            }
        }

        int ans = mx + n * (mx - 1);
        if (cnt > 1)
        {
            ans += cnt - 1;
        }
        auto time = static_cast<int> (tasks.size());
        return max(ans, time);
    }

    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> v(26, 0);
        for (const auto &ch: tasks)
        {
            ++v[ch - 'A'];
        }

        sort(v.begin(), v.end());
        auto mx = v.back()-1;
        auto gaps = mx * n;
        for (int i = 24; i >= 0; --i)
        {
            gaps -= min(mx, v[i]);
        }

        if (gaps < 0)
        {
            return tasks.size();
        }
        return tasks.size() + gaps;
    }
};