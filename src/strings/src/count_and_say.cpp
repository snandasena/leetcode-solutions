//
// Created by sajith on 10/18/22.
//

#include "base.h"

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        else if (n == 2)
        {
            return "11";
        }
        else
        {
            string str = countAndSay(n - 1);
            int i = 0;
            string res{};
            while (i < str.size())
            {
                int cnt = 0;
                char digit = str[i];

                while (i < str.size() && str[i] == digit)
                {
                    ++cnt;
                    ++i;
                }

                res.push_back(cnt + '0');
                res.push_back(digit);
            }
            return res;
        }
    }
};