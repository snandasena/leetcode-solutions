//
// Created by sajit on 13/03/2024.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        if (n == 1)
            return 1;

        auto total = n * (n + 1) / 2;
        for (int x = 1; x < n; ++x)
        {
            auto left = x * (x + 1) / 2;
            auto right = total - left;

            if (left == right + x)
            {
                return x;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    cout << sol.pivotInteger(8);
}