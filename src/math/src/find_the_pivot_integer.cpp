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
        if(n == 1)
            return 1;

        vector<int> v;
        v.push_back(0);
        for (int i = 1; i <= n; ++i)
        {
            auto sum = (i) *(i+1)/2;
            v.push_back(sum);
        }

        for (int x = 1; x < n; ++x)
        {
            auto left = v[x];
            auto right = v.back() - v[x];

            if (left == right+x)
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