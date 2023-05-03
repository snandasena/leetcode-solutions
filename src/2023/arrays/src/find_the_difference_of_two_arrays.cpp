//
// Created by sajit on 03/05/2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> st2(nums2.begin(), nums2.end());
        unordered_set<int> st1(nums1.begin(), nums1.end());

        vector<int> v1;
        for (const auto &item: st1)
        {
            if (st2.find(item) == st2.end())
            {
                v1.push_back(item);
            }
        }
        vector<int> v2;

        for (const auto &item: st2)
        {
            if (st1.find(item) == st2.end())
            {
                v2.push_back(item);
            }
        }
        return {v1, v2};
    }
};