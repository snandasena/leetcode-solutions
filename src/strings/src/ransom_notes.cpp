
//
// Created by sajith on 8/25/22.
//

#include "base.h"

class Solution
{
public:
    bool canConstruct2(string R, string M)
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for (const auto &ch: R)
        {
            ++v1[ch - 'a'];
        }

        for (const auto &ch: M)
        {
            ++v2[ch - 'a'];
        }

        for (int i = 0; i < 26; ++i)
        {
            if (v1[i] != 0 && v2[i] < v1[i])
            {
                return false;
            }
        }

        return true;
    }

    bool canConstruct(string R, string M)
    {
        vector<int> v(26, 0);

        for (const auto &ch: M)
        {
            ++v[ch - 'a'];
        }

        for (const auto &ch: R)
        {
            --v[ch - 'a'];

            if (v[ch - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};