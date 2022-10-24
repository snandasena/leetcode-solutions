
//
// Created by sajith on 10/24/22.
//

#include "base.h"

class Solution
{
    int mx = 0;
    int helper(const vector<string> &arr, const string &str, size_t index)
    {
        vector<int> v(26, 0);
        for (const auto &ch: str)
        {
            if (v[ch - 'a'] > 1)
            {
                return 0;
            }
            ++v[ch - 'a'];
        }

        if (index == arr.size())
        {
            return static_cast<int>( str.size());
        }

        mx = max(mx, helper(arr, str + arr[index], index + 1));
        mx = max(mx, helper(arr, str, index + 1));
        return mx;
    }
public:
    int maxLength(vector<string> &arr)
    {
        return helper(arr, "", 0);
    }
};