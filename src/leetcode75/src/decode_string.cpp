//
// Created by sajith on 8/2/22.
//


#include "base.h"

class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> st;
        int num;
        int i = 0;
        auto N = static_cast<int >(s.size());
        while (i < N)
        {
            string curr;
            while (isdigit(s[i]))
            {
                curr += s[i];
                ++i;
            }
            if (!curr.empty())
            {
                st.push(curr);
            }
            curr.clear();

            if()
        }
    }
};