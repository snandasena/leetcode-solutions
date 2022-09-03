
//
// Created by sajith on 9/3/22.
//

#include "base.h"

class Solution
{
    vector<int> ans;

    void backtrack(const string &s, int curr, const int n, const int k)
    {
        if (curr > 9 || curr < 0 || (curr == 0 && s.empty()))
        {
            return;
        }

        if (s.size() == n)
        {
            ans.push_back(stoi(s));
            return;
        }

        for (int i = 0; i <= 9; ++i)
        {
            if (abs(curr - i) == k)
            {
                backtrack(s + to_string(i), i, n, k);
            }
        }
    }
public:
    vector<int> numsSameConsecDiff2(int n, int k)
    {
        for (int i = 1; i <= 9; ++i)
        {
            backtrack(to_string(i), i, n, k);
        }

        return ans;
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 2; i <= n; ++i)
        {
            vector<int> s;
            for (const auto &ele: v)
            {
                auto rem = ele % 10;
                if (rem + k <= 9)
                {
                    s.push_back(ele * 10 + rem + k);
                }

                if (k != 0 && rem - k >= 0)
                {
                    s.push_back(ele * 10 + rem - k);
                }
            }
            v = s;
        }
        return v;
    }
};


int main()
{
    Solution sol;
    int n = 3;
    int k = 7;

    auto ans = sol.numsSameConsecDiff(n, k);
    for_each(ans.begin(), ans.end(), [](int ele) -> void
    {
        cout << ele << '\t';
    });
    return 0;
}