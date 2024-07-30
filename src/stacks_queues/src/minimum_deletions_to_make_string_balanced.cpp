//
// Created by sajit on 30/07/2024.
//

#include "base.h"

class Solution
{
public:
    int minimumDeletions(string s)
    {
        auto N = s.size();
        stack<char> st;
        int deletion_count = 0;

        for (auto i = 0u; i < N; ++i)
        {
            if (!st.empty() && st.top() == 'b' && s[i] == 'a')
            {
                st.pop();
                ++deletion_count;
            }
            else
            {
                st.push(s[i]);
            }
        }
        return deletion_count;
    }
};