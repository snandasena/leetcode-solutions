//
// Created by sajith on 10/2/22.
//


#include "base.h"

class Solution
{
public:
    int commonFactors(int a, int b)
    {
        int ans = 0;

        for (int i = 1; i < 1000; ++i)
        {
            if (a % i == 0 && b % i == 0)
            {
                ++ans;
            }

        }
        return ans;
    }
};

int
