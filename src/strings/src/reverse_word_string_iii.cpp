//
// Created by sajith on 9/22/22.
//


#include "base.h"

class Solution
{
public:
    string reverseWords2(string s)
    {
        stringstream ss{s};
        string token;
        string ans;
        while (ss >> token)
        {
            reverse(token.begin(), token.end());
            ans += token + " ";
        }
        ans.pop_back();
        return ans;
    }
    string reverseWords(string s)
    {
        int j = 0;
        for (auto i = 0; i <= s.size(); ++i)
        {
            if (s[i] == ' ' || s[i] == '\0')
            {
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            }
        }
        return s;
    }
};