//
// Created by sajith on 8/21/22.
//


#include "base.h"

vector<string> possibleChanges(vector<string> usernames)
{
    vector<string> ans;

    for (const auto &item: usernames)
    {
        if (is_sorted(item.begin(), item.end()))
        {
            ans.push_back("NO");
        }
        else
        {
            ans.push_back("YES");
        }
    }

    return ans;
}