//
// Created by sajith on 9/4/22.
//
#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        vector<vector<int>> v(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                v[i].push_back(nums[i] & nums[j]);
            }
        }

        for (int i = 0; i < v.size(); ++i)
        {
            int j = 0;
            while (!v[i].empty())
            {
                if(v[i][j] ==0)
                {

                }
            }
        }

        return 0;
    }
};

int main()
{
    Solution solution;

    vector<int> v{1, 3, 8, 48, 10};
//    solution.longestNiceSubarray(v);

    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = i + 1; j < v.size(); ++j)
        {
            cout << (v[i] & v[j]) << '\t';
        }
        cout<<'\n';
    }
    return 0;
}