//
// Created by sajith on 11/6/22.
//
#include "base.h"

class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k == 1)
        {
            string ans{s};
            string temp;
            for (int i = 0; i < s.size(); ++i)
            {
                temp = s.substr(i) + s.substr(0, i);
                if (temp < ans)
                {
                    ans = temp;
                }
            }
            return ans;
        }

        sort(s.begin(), s.end());
        return s;
    }
};