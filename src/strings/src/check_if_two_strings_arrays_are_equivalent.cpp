//
// Created by sajith on 10/25/22.
//


#include "base.h"

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string s1;
        string s2;

        for (const auto &ele: word1)
        {
            s1 += ele;
        }
        for (const auto &ele: word2)
        {
            s2 += ele;
        }

        return s2 == s1;
    }
};