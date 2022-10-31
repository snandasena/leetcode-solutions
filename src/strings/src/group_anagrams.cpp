//
// Created by sajith on 10/28/22.
//

#include "base.h"

class Solution
{

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        vector<int> v(26, 0);
        for (auto &str: strs)
        {
            auto temp = str;
            sort(str.begin(), str.end());
            mp[str].push_back(temp);
        }

        vector<vector<string>> ans;
        for (auto &[s, curr]: mp)
        {
            ans.push_back(curr);
        }
        return ans;

    }
};