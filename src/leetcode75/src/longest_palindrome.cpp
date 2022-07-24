//
// Created by sajith on 7/24/22.
//

#include "base.h"


class Solution
{
public:
    int longestPalindrome(string s)
    {
        vector<int> v(52, 0);
        for (const auto &item: s)
        {
            ++v[item - 'A'];
        }

        int ans = 0;
        for (const auto &item: v)
        {
            ans += item / 2 * 2;
            if (ans % 2 == 0 && item % 2 == 1)
            {
                ++ans;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.longestPalindrome("abccccdd");

    return 0;
}