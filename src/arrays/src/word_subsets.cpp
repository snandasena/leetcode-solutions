//
// Created by sajith on 7/30/22.
//


#include "base.h"


class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> mp(26, 0);
        for (const auto &item: words2)
        {
            vector<int> curr(26, 0);
            for (const auto &ch: item)
            {
                ++curr[ch - 'a'];
            }

            for (int i = 0; i < 26; ++i)
            {
                mp[i] = max(mp[i], curr[i]);
            }
        }
        vector<string> ans;
        for (const auto &item: words1)
        {
            vector<int> curr(26, 0);
            for (const auto &ch: item)
            {
                ++curr[ch - 'a'];
            }
            bool flag = true;
            for (int i = 0; i < 26; ++i)
            {
                if (mp[i] > 0 && curr[i] < mp[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
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
    vector<string> v{"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> v1{"e", "o"};

    solution.wordSubsets(v, v1);
    return 0;
}