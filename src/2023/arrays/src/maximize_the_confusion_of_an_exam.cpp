//
// Created by sajit on 07/07/2023.
//
#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int ans = 0;
        unordered_map<char, int> mp;

        for (int i = 0; i < answerKey.size(); ++i)
        {
            ++mp[answerKey[i]];
            int mn = min(mp['T'], mp['F']);

            if (mn <= k)
                ++ans;
            else
                --mp[answerKey[i - ans]];
        }
        return ans;
    }
};