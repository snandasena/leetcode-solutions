//
// Created by sajith on 12/1/22.
//

#include "base.h"

class Solution
{
    unordered_set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
public:
    bool halvesAreAlike(string s)
    {
        int N = s.size();
        N /= 2;

        int a = 0;
        int b = 0;

        for (int i = 0; i < N; ++i)
        {
            if (st.count(s[i]) > 0)
            {
                ++a;
            }

            if (st.count(s[i + N]) > 0)
            {
                ++b;
            }
        }
        return a == b;
    }
};