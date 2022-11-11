//
// Created by sajith on 11/10/22.
//

#include "base.h"

class Solution
{
public:
    string removeDuplicates(string s)
    {
        string str;
        for (int i = 0; i < s.size(); i++)
        {
            if (str.size() && str.back() == s[i])
                str.pop_back();
            else
                str.push_back(s[i]);
        }
        return str;
    }
};