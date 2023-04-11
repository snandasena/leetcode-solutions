//
// Created by sajit on 11/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> stk;
        for (auto ch: s)
        {
            if (ch != '*')
                stk.push(ch);
            else if (!stk.empty())
                stk.pop();
        }

        string ans{};
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};