//
// Created by sajith on 9/19/22.
//

#include "base.h"

class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int ans = 0;
        int curr = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i - 1]+1 == s[i])
            {
                ++curr;
            }
            else
            {
                ans = max(ans, curr);
                curr = 1;
            }
        }
        ans = max(ans, curr);
        return ans;
    }
};