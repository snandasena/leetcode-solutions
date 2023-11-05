//
// Created by sajit on 05/11/2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int mx = *max_element(arr.begin(), arr.end());

        int curr = arr[0];
        int winstreak = 0;
        int opponent;
        for (int i = 1; i < arr.size(); ++i)
        {
            opponent = arr[i];
            if (curr > opponent)
                ++winstreak;
            else
            {
                curr = opponent;
                winstreak = 1;
            }

            if (winstreak == k || curr == mx)break;
        }
        return curr;
    }
};