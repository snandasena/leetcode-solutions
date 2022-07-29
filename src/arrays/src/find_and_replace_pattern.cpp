//
// Created by sajith on 7/29/22.
//

#include "base.h"


class Solution
{
    bool encode(const string &str, const string &word)
    {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;
        for (int i = 0; i < str.size(); ++i)
        {
            if (mp.count(str[i]) == 0)
            {
                mp[str[i]] = i;
            }

            if (mp2.count(word[i]) == 0)
            {
                mp2[word[i]] = i;
            }

            if (mp[str[i]] != mp2[word[i]]) return false;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans;
        for (const auto &item: words)
        {
            if (encode(pattern, item))
            {
                ans.push_back(item);
            }
        }
        return ans;
    }
};

int main()
{

    Solution solution;

    return 0;
}