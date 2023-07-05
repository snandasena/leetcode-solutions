//
// Created by sajit on 05/07/2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int zeros = 0;
        int longwindow = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            zeros += (nums[i] == 0);
            while (zeros > 1)
            {
                zeros -= (nums[start] == 0);
                ++start;
            }
            longwindow = max(longwindow, i - start);
        }
        return longwindow;
    }
};