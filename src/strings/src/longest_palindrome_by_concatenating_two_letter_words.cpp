//
// Created by sajith on 11/3/22.
//

#include "base.h"

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> mp;
        for (const auto &ele: words)
        {
            ++mp[ele];
        }

        int ans = 0;
        bool central = false;
        for (const auto &[word, cnt]: mp)
        {
            if (word[0] == word[1])
            {
                if (cnt % 2 == 0)
                {
                    ans += cnt;
                }
                else
                {
                    ans += cnt - 1;
                    central = true;
                }
            }
            else if (word[0] < word[1] && mp.count({word[1], word[0]}) > 0)
            {
                ans += 2 * min(cnt, mp[{word[1], word[0]}]);
            }
        }

        if (central)
        {
            ++ans;
        }
        return 2 * ans;
    }
};

int main()
{
    Solution sol;
    vector<string> v{"cc", "ll", "xx"};
    cout << sol.longestPalindrome(v);
}