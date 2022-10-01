//
// Created by sajith on 8/21/22.
//


#include "../base.h"

class Solution
{
public:
    string largestPalindromic(string num)
    {
        map<int, int> mp;
        for (const auto &item: num)
        {
            ++mp[item - '0'];
        }

        string ans;
        int mx = INT_MIN;
        for (int i = 9; i > 0; --i)
        {
            if (mp[i] > 1)
            {
                auto size = mp[i] / 2;

                for (int j = 0; j < size; ++j)
                {
                    ans += to_string(i);
                }
            }

            if (mp[i] % 2 != 0)
            {
                mx = max(mx, i);
            }
        }

        string zeros;
        string r = ans;
        reverse(r.begin(), r.end());
        if (mx != INT_MIN)
        {
            for (int i = 0; i < mp[0] / 2; ++i)
            {
                zeros += "0";
            }

            if (!ans.empty())
            {
                ans = ans + zeros + to_string(mx) + zeros + r;
            }
            else
            {
                ans = to_string(mx);
            }
        }
        else
        {
            for (int i = 0; i < mp[0]; ++i)
            {
                zeros += "0";
            }

            if (!ans.empty())
            {
                ans = ans + zeros + r;
            }
            else
            {
                ans = "0";
            }

        }
        return ans;

    }
};


int main()
{
    Solution solution;
    string s{"846853515384906866969100"};
    cout << solution.largestPalindromic(s);

    return 0;
}