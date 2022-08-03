//
// Created by sajith on 8/2/22.
//


#include "base.h"

class Solution
{
    int i = 0;
    string helper(string &str)
    {
        string res;
        while (i < str.size() && str[i] != ']')
        {
            if (isdigit(str[i]))
            {
                int k = 0;
                while (i < str.size() && isdigit(str[i]))
                {
                    k = k * 10 + str[i] - '0';
                    ++i;
                }
                ++i;
                string r = helper(str, i);
                while (k-- > 0)
                {
                    res += r;
                }
                ++i;
            }
            else
            {
                res += str[i];
                ++i;
            }
        }
        return res;
    }
public:
    string decodeString(string s)
    {
        return helper(s);
    }
};